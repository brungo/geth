--------------------------------------------------------------------------------
-- Title      : Client to Local-link Receiver FIFO
-- Version    : 1.2
-- Project    : Tri-Mode Ethernet MAC
--------------------------------------------------------------------------------
-- File       : rx_client_fifo.vhd
-- Author     : Xilinx Inc.
-- ------------------------------------------------------------------------------
-- (c) Copyright 2004-2008 Xilinx, Inc. All rights reserved.
--
-- This file contains confidential and proprietary information
-- of Xilinx, Inc. and is protected under U.S. and
-- international copyright and other intellectual property
-- laws.
--
-- DISCLAIMER
-- This disclaimer is not a license and does not grant any
-- rights to the materials distributed herewith. Except as
-- otherwise provided in a valid license issued to you by
-- Xilinx, and to the maximum extent permitted by applicable
-- law: (1) THESE MATERIALS ARE MADE AVAILABLE "AS IS" AND
-- WITH ALL FAULTS, AND XILINX HEREBY DISCLAIMS ALL WARRANTIES
-- AND CONDITIONS, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
-- BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, NON-
-- INFRINGEMENT, OR FITNESS FOR ANY PARTICULAR PURPOSE; and
-- (2) Xilinx shall not be liable (whether in contract or tort,
-- including negligence, or under any other theory of
-- liability) for any loss or damage of any kind or nature
-- related to, arising under or in connection with these
-- materials, including for any direct, or any indirect,
-- special, incidental, or consequential loss or damage
-- (including loss of data, profits, goodwill, or any type of
-- loss or damage suffered as a result of any action brought
-- by a third party) even if such damage or loss was
-- reasonably foreseeable or Xilinx had been advised of the
-- possibility of the same.
--
-- CRITICAL APPLICATIONS
-- Xilinx products are not designed or intended to be fail-
-- safe, or for use in any application requiring fail-safe
-- performance, such as life-support or safety devices or
-- systems, Class III medical devices, nuclear facilities,
-- applications related to the deployment of airbags, or any
-- other applications that could lead to death, personal
-- injury, or severe property or environmental damage
-- (individually and collectively, "Critical
-- Applications"). Customer assumes the sole risk and
-- liability of any use of Xilinx products in Critical
-- Applications, subject only to applicable laws and
-- regulations governing limitations on product liability.
--
-- THIS COPYRIGHT NOTICE AND DISCLAIMER MUST BE RETAINED AS
-- PART OF THIS FILE AT ALL TIMES. 
-- ------------------------------------------------------------------------------
-- Description: This is the receiver side local link fifo for the design example
--              of the Tri-Mode Ethernet MAC core.
--
--              The FIFO is created from 2 Block RAMs of size 2048
--              words of 8-bits per word, giving a total frame memory capacity
--              of 4096 bytes.
--
--              Frame data received from the MAC receiver is written into the
--              FIFO on the wr_clk.  An End Of Frame marker is written to the
--              BRAM parity bit on the last byte of data stored for a frame.
--              This acts as frame deliniation.
--
--              The rx_good_frame and rx_bad_frame signals are used to
--              qualify the frame.  A frame for which rx_bad_frame was
--              asserted will cause the FIFO write address pointer to be
--              reset to the base address of that frame.  In this way
--              the bad frame will be overwritten with the next received
--              frame and is therefore dropped from the FIFO.
--
--              Frames will also be dropped from the FIFO if an overflow occurs.
--              If there is not enough memory capacity in the FIFO to store the
--              whole of an incoming frame, the write address pointer will be
--              reset and the overflow signal asserted.
--
--              When there is at least one complete frame in the FIFO,
--              the 8 bit Local-link read interface will be enabled allowing
--              data to be read from the fifo.
--
--              The FIFO has been designed to operate with different clocks
--              on the write and read sides.  The read clock (locallink clock)
--              should always operate at an equal or faster frequency
--              than the write clock (client clock).
--
--              The FIFO is designed to work with a minimum frame length of 8
--              bytes.
--
--              The FIFO memory size can be increased by expanding the rd_addr
--              and wr_addr signal widths, to address further BRAMs.
--
--              Requirements :
--              * Minimum frame size of 8 bytes
--              * Spacing between good/bad frame flags is at least 64 clock
--                cycles
--              * Wr clock is 125MHz downto 1.25MHz
--              * Rd clock is downto 20MHz
--------------------------------------------------------------------------------

library unisim;

use unisim.vcomponents.all;

library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;
use ieee.numeric_std.all;


--------------------------------------------------------------------------------
-- The entity declaration for the Receiver FIFO
--------------------------------------------------------------------------------

entity rx_client_fifo is
  port (
        -- Local-link Interface      
        rd_clk         : in  std_logic;
        rd_sreset      : in  std_logic;
        rd_data_out    : out std_logic_vector(7 downto 0);
        rd_sof_n       : out std_logic;
        rd_eof_n       : out std_logic;
        rd_src_rdy_n   : out std_logic;
        rd_dst_rdy_n   : in std_logic;

        -- Client Interface
        wr_clk         : in  std_logic;
        wr_sreset      : in  std_logic;
        wr_enable      : in  std_logic;
        rx_data        : in  std_logic_vector(7 downto 0);
        rx_data_valid  : in std_logic;
        rx_good_frame  : in std_logic;
        rx_bad_frame   : in std_logic;
        rx_fifo_status : out std_logic_vector(3 downto 0);
        overflow       : out std_logic
        );
end rx_client_fifo;


architecture RTL of rx_client_fifo is


  ------------------------------------------------------------------------------
  -- Component declaration for the synchronisation flip-flop pair
  ------------------------------------------------------------------------------
  component sync_block
  port (
    clk                : in  std_logic;
    data_in            : in  std_logic;
    data_out           : out std_logic
    );
  end component;

  ------------------------------------------------------------------------------
  -- Component declaration for the reset synchroniser
  ------------------------------------------------------------------------------
  component reset_sync
  port (
    reset_in               : in  std_logic;    -- Active high asynchronous reset
    enable                 : in  std_logic;    -- enable reeset removal
    clk                    : in  std_logic;    -- clock to be sync'ed to
    reset_out              : out std_logic     -- "Synchronised" reset signal
    );
  end component;


  ------------------------------------------------------------------------------
  -- Define Internal Signals
  ------------------------------------------------------------------------------
  signal GND                 : std_logic;
  signal VCC                 : std_logic;
  signal GND_BUS             : std_logic_vector(7 downto 0);

  -- Encode rd state machine
  type rd_state_typ is      (WAIT_s,
                             QUEUE1_s,
                             QUEUE2_s,
                             QUEUE3_s,
                             QUEUE_SOF_s,
                             SOF_s,
                             DATA_s,
                             EOF_s);

  signal rd_state            : rd_state_typ;
  signal rd_nxt_state        : rd_state_typ;

  -- Encode wr state machine
  type wr_state_typ is      (IDLE_s, 
                             FRAME_s, 
                             END_s, 
                             GF_s, 
                             BF_s, 
                             OVFLOW_s);
                       
  signal wr_state            : wr_state_typ;
  signal wr_nxt_state        : wr_state_typ;

  type data_pipe is array (0 to 1) of std_logic_vector(7 downto 0);
  type cntl_pipe is array(0 to 1) of std_logic;

  signal wr_en               : std_logic;
  signal wr_en_u             : std_logic;
  signal wr_en_l             : std_logic;
  signal wr_addr             : unsigned(11 downto 0);
  signal wr_addr_inc         : std_logic;
  signal wr_start_addr_load  : std_logic;
  signal wr_addr_reload      : std_logic;
  signal wr_start_addr       : unsigned(11 downto 0);
  signal wr_data_bram        : std_logic_vector(7 downto 0);
  signal wr_data_pipe        : data_pipe;
  signal wr_eof_bram         : std_logic_vector(0 downto 0);
  signal wr_dv_pipe          : cntl_pipe;
  signal wr_gf_pipe          : cntl_pipe;
  signal wr_bf_pipe          : cntl_pipe;
  signal frame_in_fifo       : std_logic;

  signal rd_addr             : unsigned(11 downto 0);
  signal rd_addr_inc         : std_logic;
  signal rd_addr_reload      : std_logic;
  signal rd_data_bram_u      : std_logic_vector(7 downto 0);
  signal rd_data_bram_l      : std_logic_vector(7 downto 0);
  signal rd_data_pipe_u      : std_logic_vector(7 downto 0);
  signal rd_data_pipe_l      : std_logic_vector(7 downto 0);
  signal rd_data_pipe        : std_logic_vector(7 downto 0);
  signal rd_eof_bram_u       : std_logic_vector(0 downto 0);
  signal rd_eof_bram_l       : std_logic_vector(0 downto 0);
  signal rd_en               : std_logic;
  signal rd_bram_u           : std_logic;
  signal rd_bram_u_reg       : std_logic;
  signal rd_pull_frame       : std_logic;
  signal rd_eof              : std_logic;

  signal wr_store_frame_tog  : std_logic := '0';
  signal rd_store_frame_sync : std_logic;
  signal rd_store_frame_delay : std_logic := '0';
  signal rd_store_frame      : std_logic;
  signal rd_frames           : std_logic_vector(8 downto 0);
  signal wr_fifo_full        : std_logic;

  signal old_rd_addr         : std_logic_vector(1 downto 0);
  signal update_addr_tog     : std_logic;
  signal update_addr_tog_sync : std_logic;
  signal update_addr_tog_sync_reg : std_logic;

  signal wr_rd_addr          : unsigned(11 downto 0);
  signal wr_addr_diff_in     : unsigned(12 downto 0);
  signal wr_addr_diff        : unsigned(11 downto 0);

  signal wr_fifo_status      : unsigned(3 downto 0);

  signal rd_eof_n_int        : std_logic;

  signal rd_valid_pipe       : std_logic_vector(1 downto 0);

--------------------------------------------------------------------------------
-- Begin FIFO architecture
--------------------------------------------------------------------------------


begin


  GND     <= '0';
  VCC     <= '1';
  GND_BUS <= (others => '0');



  ------------------------------------------------------------------------------
  -- Read State machines and control
  ------------------------------------------------------------------------------

  -- local link state machine
  -- states are WAIT, QUEUE1, QUEUE2, QUEUE3, SOF, DATA, EOF
  -- clock state to next state
  clock_rds_p : process(rd_clk)
  begin
     if (rd_clk'event and rd_clk = '1') then
        if rd_sreset = '1' then
           rd_state <= WAIT_s;
        else
           rd_state <= rd_nxt_state;
        end if;
     end if;
  end process clock_rds_p;

  rd_eof_n <= rd_eof_n_int;

  -- decode next state, combinatorial
  next_rds_p : process(rd_state, frame_in_fifo, rd_eof, rd_dst_rdy_n,
                       rd_eof_n_int, rd_valid_pipe)
  begin
     case rd_state is
        when WAIT_s =>
           -- wait till there is a full frame in the fifo
           -- then start to load the pipeline
           if frame_in_fifo = '1' and rd_eof_n_int = '1' then
              rd_nxt_state <= QUEUE1_s;
           else
              rd_nxt_state <= WAIT_s;
           end if;
        when QUEUE1_s =>
           -- load the output pipeline
           -- this takes three clocks
           rd_nxt_state <= QUEUE2_s;
        when QUEUE2_s =>
           rd_nxt_state <= QUEUE3_s;
        when QUEUE3_s =>
           rd_nxt_state <= QUEUE_SOF_s;
        when QUEUE_SOF_s =>
           -- used to mark sof at end of queue
              rd_nxt_state <= DATA_s;  -- move straight to frame.
        when SOF_s =>
           -- used to mark sof when following straight from eof
           if rd_dst_rdy_n = '0' then
              rd_nxt_state <= DATA_s;
           else
              rd_nxt_state <= SOF_s;
           end if;
        when DATA_s =>
           -- When the eof marker is detected from the BRAM output
           -- move to EOF state
           if rd_dst_rdy_n = '0' and rd_eof = '1' then
              rd_nxt_state <= EOF_s;
           else
              rd_nxt_state <= DATA_s;
           end if;
        when EOF_s =>
           -- hold in this state until dst rdy is low
           -- and eof bit is accepted on interface
           -- If there is a frame in the fifo, then the next frame
           -- will already be queued into the pipe line so move straight
           -- to sof state.
           if rd_dst_rdy_n = '0' then
              if rd_valid_pipe(1) = '1' then
                rd_nxt_state <= SOF_s;
              else
                 rd_nxt_state <= WAIT_s;
              end if;
           else
              rd_nxt_state <= EOF_s;
           end if;
        when others =>
           rd_nxt_state <= WAIT_s;
        end case;
  end process next_rds_p;

  -- detect if frame in fifo was high 3 reads ago
  -- this is used to ensure we only treat data in the pipeline as valid if
  -- frame in fifo goes high at or before the eof of the current frame
  -- It may be that there is valid data (i.e a partial packet has been written)
  -- but until the end of that packet we do not know if it is a good packet
  rd_valid_pipe_p : process(rd_clk)
  begin
     if (rd_clk'event and rd_clk = '1') then
         if (rd_dst_rdy_n = '0') then
            rd_valid_pipe <= rd_valid_pipe(0) &
                             frame_in_fifo;
         end if;
     end if;
  end process rd_valid_pipe_p;


  -- decode the output signals depending on current state.
  -- decode sof signal.
  rd_ll_sof_p : process(rd_clk)
  begin
     if (rd_clk'event and rd_clk = '1') then
        if rd_sreset = '1' then
           rd_sof_n <= '1';
        else
           case rd_state is
              when QUEUE_SOF_s =>
                 -- no need to wait for dst rdy to be low: there is valid data
                 rd_sof_n <= '0';
              when SOF_s =>
                 -- needed to wait till rd_dst_rdy is low to ensure eof signal
                 -- has been accepted onto the interface before asserting sof.
                 if rd_dst_rdy_n = '0' then
                    rd_sof_n <= '0';
                 end if;
              when others =>
                 -- needed to wait till rd_dst_rdy is low to ensure sof signal
                 -- has been accepted onto the interface.
                 if rd_dst_rdy_n = '0' then
                    rd_sof_n <= '1';
                 end if;
           end case;
        end if;
     end if;
  end process rd_ll_sof_p;

  -- decode eof signal
  -- check init value of this reg is 1.
  rd_ll_decode_p : process(rd_clk)
  begin
     if (rd_clk'event and rd_clk = '1') then
        if rd_sreset = '1' then
           rd_eof_n_int <= '1';
        elsif rd_dst_rdy_n = '0' then
           -- needed to wait till rd_dst_rdy is low to ensure penultimate byte
           -- of frame has been accepted onto the interface before asserting eof
           -- and that eof is accepted before moving on
           case rd_state is
              when EOF_s =>
                 rd_eof_n_int <= '0';
              when others =>
                 rd_eof_n_int <= '1';
           end case;
        end if;
     end if;
  end process rd_ll_decode_p;

  -- decode data output
  rd_ll_data_p : process(rd_clk)
  begin
     if (rd_clk'event and rd_clk = '1') then
        if rd_en = '1' then
           rd_data_out <= rd_data_pipe;
        end if;
     end if;
  end process rd_ll_data_p;

  -- decode the output scr_rdy signal
  -- want to remove the dependancy of src_rdy from dst rdy
  -- check init value of this reg is '1'
  rd_ll_src_p : process(rd_clk)
  begin
     if (rd_clk'event and rd_clk = '1') then
        if rd_sreset = '1' then
           rd_src_rdy_n <= '1';
        else
           case rd_state is
              when QUEUE_SOF_s =>
                 rd_src_rdy_n <= '0';
              when SOF_s =>
                 rd_src_rdy_n <= '0';
              when DATA_s =>
                 rd_src_rdy_n <= '0';
              when EOF_s =>
                 rd_src_rdy_n <= '0';
              when others =>
                 if rd_dst_rdy_n = '0' then
                    rd_src_rdy_n <= '1';
                 end if;
            end case;
         end if;
     end if;
  end process rd_ll_src_p;


  -- decode internal control signals
  -- rd_en is used to enable the BRAM read and load the output pipe
  rd_en_p : process(rd_state, rd_dst_rdy_n)
  begin
     case rd_state is
        when WAIT_s =>
           rd_en <= '0';
        when QUEUE1_s =>
           rd_en <= '1';
        when QUEUE2_s =>
           rd_en <= '1';
        when QUEUE3_s =>
           rd_en <= '1';
        when QUEUE_SOF_s =>
           rd_en <= '1';
        when others =>
           rd_en <= not rd_dst_rdy_n;
     end case;
  end process rd_en_p;

  -- rd_addr_inc is used to enable the BRAM read address to increment
  rd_addr_inc <= rd_en;


  -- When the current frame is output, if there is no frame in the fifo, then
  -- the fifo must wait until a new frame is written in.  This requires the read
  -- address to be moved back to where the new frame will be written.  The pipe
  -- is then reloaded using the QUEUE states
  p_rd_addr_reload : process (rd_clk)
  begin
    if rd_clk'event and rd_clk = '1' then
      if rd_sreset = '1' then
        rd_addr_reload <= '0';
      else
        if rd_state = EOF_s and rd_nxt_state = WAIT_s then
          rd_addr_reload <= '1';
        else
          rd_addr_reload <= '0';
        end if;
      end if;
    end if;
  end process p_rd_addr_reload;

  -- frame in fifo signal is required on the rd side, need to convert wr
  -- address to rd clock domain.
  -- Data is available if there is at least one frame stored in the FIFO.
  p_rd_avail : process (rd_clk)
  begin
    if rd_clk'event and rd_clk = '1' then
      if rd_sreset = '1' then
        frame_in_fifo <= '0';
      else
        if rd_frames /= (rd_frames'range => '0') then
          frame_in_fifo <= '1';
        else
          frame_in_fifo <= '0';
        end if;
      end if;
    end if;
  end process p_rd_avail;

  -- when a frame has been stored need to convert to rd clock domain for frame
  -- count store.
  resync_wr_store_frame_tog : sync_block
  port map (
    clk       => rd_clk,
    data_in   => wr_store_frame_tog,
    data_out  => rd_store_frame_sync
  );

  -- edge detect of the resynchronized frame count
  p_delay_rd_store : process (rd_clk)
  begin
    if rd_clk'event and rd_clk = '1' then
      rd_store_frame_delay <= rd_store_frame_sync;
    end if;
  end process p_delay_rd_store;

  -- edge detect of the resynchronized frame count
  p_sync_rd_store : process (rd_clk)
  begin
    if rd_clk'event and rd_clk = '1' then
      if rd_sreset = '1' then
        rd_store_frame      <= '0';
      else
        -- edge detector
        if (rd_store_frame_delay xor rd_store_frame_sync) = '1' then
          rd_store_frame    <= '1';
        else
          rd_store_frame    <= '0';
        end if;
      end if;
    end if;
  end process p_sync_rd_store;

  p_rd_pull_frame : process (rd_clk)
  begin
    if rd_clk'event and rd_clk = '1' then
      if rd_sreset = '1' then
        rd_pull_frame <= '0';
      else
        if rd_state = SOF_s and rd_nxt_state /= SOF_s then
          rd_pull_frame <= '1';
        elsif rd_state = QUEUE_SOF_s and rd_nxt_state /= QUEUE_SOF_s then
          rd_pull_frame <= '1';
        else
          rd_pull_frame <= '0';
        end if;
      end if;
    end if;
  end process p_rd_pull_frame;

  -- Up/Down counter to monitor the number of frames stored within the
  -- the FIFO. Note:
  --    * decrements at the beginning of a frame read cycle
  --    * increments at the end of a frame write cycle
  p_rd_frames : process (rd_clk)
  begin
    if rd_clk'event and rd_clk = '1' then
      if rd_sreset = '1' then
        rd_frames <= (others => '0');
      else
        -- A frame is written to the fifo in this cycle, and no frame is being
        -- read out on the same cycle
        if rd_store_frame = '1' and rd_pull_frame = '0' then
            rd_frames <= rd_frames + 1;
        -- A frame is being read out on this cycle and no frame is being
        -- written on the same cycle
        elsif rd_store_frame = '0' and rd_pull_frame = '1' then
             rd_frames <= rd_frames - 1;
        end if;
      end if;
    end if;
  end process p_rd_frames;


  ------------------------------------------------------------------------------
  -- Write State machines and control
  ------------------------------------------------------------------------------

  -- write state machine
  -- states are IDLE, FRAME, EOF, GF, BF, OVFLOW
  -- clock state to next state
  clock_wrs_p : process(wr_clk)
  begin
     if (wr_clk'event and wr_clk = '1') then
        if wr_sreset = '1' then
           wr_state <= IDLE_s;
        elsif wr_enable = '1' then
           wr_state <= wr_nxt_state;
        end if;
     end if;
  end process clock_wrs_p;

  -- decode next state, combinatorial
  next_wrs_p : process(wr_state, wr_dv_pipe(1), wr_gf_pipe(1), wr_bf_pipe(1),
                       wr_eof_bram(0), wr_fifo_full)
  begin
  case wr_state is
           when IDLE_s =>
              -- there is data in incoming pipeline when dv_pipe(1) goes high
              if wr_dv_pipe(1) = '1' then
                 wr_nxt_state <= FRAME_s;
              else
                 wr_nxt_state <= IDLE_s;
              end if;
           when FRAME_s =>
              -- if fifo is full then go to overflow state.
              -- if the good or bad flag is detected the end
              -- of the frame has been reached!
              -- this transistion occurs when the gb flag
              -- is on the clock edge immediately following
              -- the end of the frame.
              -- if the eof_bram signal is detected then data valid has
              -- fallen low and the end of frame has been detected.
              if wr_fifo_full = '1' then
                 wr_nxt_state <= OVFLOW_s;
              elsif wr_gf_pipe(1) = '1' then
                 wr_nxt_state <= GF_s;
              elsif wr_bf_pipe(1) = '1' then
                 wr_nxt_state <= BF_s;
              elsif wr_eof_bram(0) = '1' then
                 wr_nxt_state <= END_s;
              else
                 wr_nxt_state <= FRAME_s;
              end if;
           when END_s =>
              -- wait until the good or bad flag has been received.
              if wr_gf_pipe(1) = '1' then
                 wr_nxt_state <= GF_s;
              elsif wr_bf_pipe(1) = '1' then
                 wr_nxt_state <= BF_s;
              else
                 wr_nxt_state <= END_s;
              end if;
           when GF_s =>
              -- wait for next frame
              wr_nxt_state <= IDLE_s;
           when BF_s =>
              -- wait for next frame
              wr_nxt_state <= IDLE_s;
           when OVFLOW_s =>
              -- wait until the good or bad flag received.
              if wr_gf_pipe(1) = '1' or wr_bf_pipe(1) = '1' then
                 wr_nxt_state <= IDLE_s;
              else
                 wr_nxt_state <= OVFLOW_s;
              end if;
           when others =>
              wr_nxt_state <= IDLE_s;
        end case;
  end process next_wrs_p;


  -- decode control signals
  -- wr_en is used to enable the BRAM write and loading of the input pipeline
  wr_en <= '1' when wr_state = FRAME_s else '0';

  -- the upper and lower signals are used to distinguish between the upper and
  -- lower BRAM
  wr_en_l <= wr_en and not(wr_addr(11));
  wr_en_u <= wr_en and wr_addr(11);

  -- increment the write address when we are receiving a frame
  wr_addr_inc <= '1' when wr_state = FRAME_s else '0';

  -- if the fifo overflows or a frame is to be dropped, we need to move the
  -- write address back to the start of the frame.  This allows the data to be
  -- overwritten.
  wr_addr_reload <= '1' when wr_state = BF_s or wr_state = OVFLOW_s else '0';

  -- the start address is saved when in the WAIT state
  wr_start_addr_load <= '1' when wr_state = IDLE_s else '0';

  -- we need to know when a frame is stored, in order to increment the count of
  -- frames stored in the fifo.
  p_wr_store_tog : process (wr_clk)
  begin  -- process
     if wr_clk'event and wr_clk = '1' then
        if wr_enable = '1' then
           if wr_state = GF_s then
              wr_store_frame_tog <= not wr_store_frame_tog;
           end if;
        end if;
     end if;
  end process;


  ------------------------------------------------------------------------------
  -- Address counters
  ------------------------------------------------------------------------------

  -- write address is incremented when write enable signal has been asserted
  wr_addr_p : process(wr_clk)
  begin
     if (wr_clk'event and wr_clk = '1') then
        if wr_sreset = '1' then
           wr_addr <= (others => '0');
        elsif wr_enable = '1' then
           if wr_addr_reload = '1' then
              wr_addr <= wr_start_addr;
           elsif wr_addr_inc = '1' then
              wr_addr <= wr_addr + 1;
           end if;
        end if;
     end if;
  end process wr_addr_p;

  -- store the start address
  wr_staddr_p : process(wr_clk)
  begin
     if (wr_clk'event and wr_clk = '1') then
        if wr_sreset = '1' then
           wr_start_addr <= (others => '0');
        elsif wr_enable = '1' then
           if wr_start_addr_load = '1' then
              wr_start_addr <= wr_addr;
           end if;
        end if;
     end if;
  end process wr_staddr_p;

  -- read address is incremented when read enable signal has been asserted
  rd_addr_p : process(rd_clk)
  begin
     if (rd_clk'event and rd_clk = '1') then
        if rd_sreset = '1' then
           rd_addr <= (others => '0');
        else
           if rd_addr_reload = '1' then
              rd_addr <= rd_addr - 3;
           elsif rd_addr_inc = '1' then
              rd_addr <= rd_addr + 1;
           end if;
        end if;
     end if;
  end process rd_addr_p;

  -- which BRAM is read from is dependant on the upper bit of the address
  -- space.  this needs to be registered to give the correct timing.
  rd_bram_p : process(rd_clk)
  begin
     if (rd_clk'event and rd_clk = '1') then
        if rd_sreset = '1' then
           rd_bram_u <= '0';
           rd_bram_u_reg <= '0';
        elsif rd_addr_inc = '1' then
           rd_bram_u <= rd_addr(11);
           rd_bram_u_reg <= rd_bram_u;
        end if;
     end if;
  end process rd_bram_p;


  ------------------------------------------------------------------------------
  -- Data Pipelines
  ------------------------------------------------------------------------------

  -- register data inputs to bram
  -- no reset to allow srl16 target
  reg_din_p : process(wr_clk)
  begin
     if (wr_clk'event and wr_clk = '1') then
        if wr_enable = '1' then
           wr_data_pipe(0) <= rx_data;
           wr_data_pipe(1) <= wr_data_pipe(0);
           wr_data_bram    <= wr_data_pipe(1);
        end if;
     end if;
  end process reg_din_p;

 reg_eof_p : process(wr_clk)
  begin
     if (wr_clk'event and wr_clk = '1') then
        if wr_sreset = '1' then
           wr_dv_pipe    <= (others => '0');
           wr_eof_bram   <= (others => '0');
        elsif wr_enable = '1' then
           wr_dv_pipe(0) <= rx_data_valid;
           wr_dv_pipe(1) <= wr_dv_pipe(0);
           wr_eof_bram(0) <= wr_dv_pipe(1) and not wr_dv_pipe(0);
        end if;
     end if;
  end process reg_eof_p;

   -- no reset to allow srl16 target
  reg_gf_p : process(wr_clk)
  begin
     if (wr_clk'event and wr_clk = '1') then
        if wr_enable = '1' then
           wr_gf_pipe(0) <= rx_good_frame;
           wr_gf_pipe(1) <= wr_gf_pipe(0);
           wr_bf_pipe(0) <= rx_bad_frame;
           wr_bf_pipe(1) <= wr_bf_pipe(0);
        end if;
     end if;
  end process reg_gf_p;

  -- register data outputs from bram
  -- no reset to allow srl16 target
  reg_dout_p : process(rd_clk)
  begin
     if (rd_clk'event and rd_clk = '1') then
        if rd_en = '1' then
           rd_data_pipe_u <= rd_data_bram_u;
           rd_data_pipe_l <= rd_data_bram_l;
           if rd_bram_u_reg = '1' then
              rd_data_pipe <= rd_data_pipe_u;
           else
              rd_data_pipe <= rd_data_pipe_l;
           end if;
        end if;
     end if;
  end process reg_dout_p;

  -- register data outputs from bram
  reg_eofout_p : process(rd_clk)
  begin
     if (rd_clk'event and rd_clk = '1') then
        if rd_en = '1' then
           if rd_bram_u = '1' then
              rd_eof <= rd_eof_bram_u(0);
           else
              rd_eof <= rd_eof_bram_l(0);
           end if;
        end if;
     end if;
  end process reg_eofout_p;


  ------------------------------------------------------------------------------
  -- Overflow functionality
  ------------------------------------------------------------------------------

  -- to minimise the number of read address updates the bottom 6 bits of the 
  -- read address are not passed across and the write domain will only sample 
  -- them when bits 5 and 4 of the read address transition from 01 to 10.  
  -- Since this is for full detection this just means that if the read stops
  -- the write will hit full up to 64 locations early
  
  -- need to use two bits and look for an increment transition as reload can cause
  -- a decrement on this boundary (decrement is only by 3 so above bit 2 should be safe)
  p_rd_addr_tog : process (rd_clk)
  begin
     if rd_clk'event and rd_clk = '1' then
        if rd_sreset = '1' then
           old_rd_addr <= (others => '0');
           update_addr_tog <= '0';
        else 
           old_rd_addr <= std_logic_vector(rd_addr(5 downto 4));
           if rd_addr(5 downto 4) = "10" and old_rd_addr = "01" then
              update_addr_tog <= not update_addr_tog;
           end if;
        end if;
     end if;
  end process p_rd_addr_tog;

  sync_rd_addr_tog: sync_block
  port map (
     clk       => wr_clk,
     data_in   => update_addr_tog,
     data_out  => update_addr_tog_sync
  );

  -- Obtain the difference between write and read pointers.
  p_sample_addr : process (wr_clk)
  begin
     if wr_clk'event and wr_clk = '1' then
        if wr_sreset = '1' then
           update_addr_tog_sync_reg <= '0';
           wr_rd_addr               <= (others => '0');
        else
           update_addr_tog_sync_reg <= update_addr_tog_sync;
           if update_addr_tog_sync_reg /= update_addr_tog_sync then
              wr_rd_addr               <= rd_addr(11 downto 6) & "000000";
           end if;
        end if;
     end if;
  end process p_sample_addr;

  wr_addr_diff_in <= ('0' & wr_rd_addr) - ('0' & wr_addr);

  -- Obtain the difference between write and read pointers.
  p_addr_diff : process (wr_clk)
  begin
     if wr_clk'event and wr_clk = '1' then
        if wr_sreset = '1' then
           wr_addr_diff <= (others => '0');
        else
           wr_addr_diff <= wr_addr_diff_in(11 downto 0);
        end if;
     end if;
  end process p_addr_diff;

  -- Detect when the FIFO is full
  -- The FIFO is considered to be full if the write address
  -- pointer is within 4 to 15 of the read address pointer.
  p_wr_full : process (wr_clk)
  begin
     if wr_clk'event and wr_clk = '1' then
       if wr_sreset = '1' then
         wr_fifo_full <= '0';
       elsif wr_enable = '1' then
         if wr_addr_diff(11 downto 4) = 0
            and wr_addr_diff(3 downto 2) /= "00" then
           wr_fifo_full <= '1';
         else
            wr_fifo_full <= '0';
         end if;
       end if;
     end if;
  end process p_wr_full;

  overflow <= '1' when wr_state = OVFLOW_s else '0';


  ------------------------------------------------------------------------------
  -- FIFO Status Signals
  ------------------------------------------------------------------------------

  -- The FIFO status signal is four bits which represents the occupancy
  -- of the FIFO in 16'ths.  To generate this signal we therefore only
  -- need to compare the 4 most significant bits of the write address
  -- pointer with the 4 most significant bits of the read address
  -- pointer.

  -- already have fifo status on write side through wr_addr_diff.
  -- calculate fifo status here and output on the wr clock domain.


  p_wr_fifo_status : process (wr_clk)
  begin
     if wr_clk'event and wr_clk = '1' then
        if wr_sreset = '1' then
           wr_fifo_status <= "0000";
        elsif wr_enable = '1' then
           if wr_addr_diff = (wr_addr_diff'range => '0') then
              wr_fifo_status <= "0000";
           else
              wr_fifo_status(3) <= not wr_addr_diff(11);
              wr_fifo_status(2) <= not wr_addr_diff(10);
              wr_fifo_status(1) <= not wr_addr_diff(9);
              wr_fifo_status(0) <= not wr_addr_diff(8);
           end if;
        end if;
     end if;
  end process p_wr_fifo_status;

  rx_fifo_status <= std_logic_vector(wr_fifo_status);


  ------------------------------------------------------------------------------
  -- Instantiate Memory
  ------------------------------------------------------------------------------

  -- Block Ram for lower address space (rx_addr(11) = '0')
  ramgen_l : RAMB16_S9_S9
    generic map (
      WRITE_MODE_A => "WRITE_FIRST",
      WRITE_MODE_B => "WRITE_FIRST")
    port map (
      WEA   => wr_en_l,
      ENA   => VCC,
      SSRA  => wr_sreset,
      CLKA  => wr_clk,
      ADDRA => std_logic_vector(wr_addr(10 downto 0)),
      DIA   => wr_data_bram,
      DIPA  => wr_eof_bram,
      WEB   => GND,
      ENB   => rd_en,
      SSRB  => rd_sreset,
      CLKB  => rd_clk,
      ADDRB => std_logic_vector(rd_addr(10 downto 0)),
      DIB   => GND_BUS(7 downto 0),
      DIPB  => GND_BUS(0 downto 0),
      DOB   => rd_data_bram_l,
      DOPB  => rd_eof_bram_l);

  -- Block Ram for lower address space (rx_addr(11) = '0')
  ramgen_u : RAMB16_S9_S9
    generic map (
      WRITE_MODE_A => "WRITE_FIRST",
      WRITE_MODE_B => "WRITE_FIRST")
    port map (
      WEA   => wr_en_u,
      ENA   => VCC,
      SSRA  => wr_sreset,
      CLKA  => wr_clk,
      ADDRA => std_logic_vector(wr_addr(10 downto 0)),
      DIA   => wr_data_bram,
      DIPA  => wr_eof_bram,
      WEB   => GND,
      ENB   => rd_en,
      SSRB  => rd_sreset,
      CLKB  => rd_clk,
      ADDRB => std_logic_vector(rd_addr(10 downto 0)),
      DIB   => GND_BUS(7 downto 0),
      DIPB  => GND_BUS(0 downto 0),
      DOB   => rd_data_bram_u,
      DOPB  => rd_eof_bram_u);



end RTL;
