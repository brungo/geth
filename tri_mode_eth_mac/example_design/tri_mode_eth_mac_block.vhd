--------------------------------------------------------------------------------
-- File       : tri_mode_eth_mac_block.vhd
-- Author     : Xilinx Inc.
-- ------------------------------------------------------------------------------
-- (c) Copyright 2004-2009 Xilinx, Inc. All rights reserved.
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
-- Description: This is the block level VHDL design for the Tri-Mode
--              Ethernet MAC Example Design.
--
--              This block level:
--
--              * instantiates all clock enable logic required to operate the
--                TEMAC and its example design;
--
--              * instantiates appropriate PHY interface module (GMII/MII/RGMII)
--                as required based on the user configuration;
--
--              Please refer to the Datasheet, Getting Started Guide, and
--              the Tri-Mode Ethernet MAC User Gude for further information.
--
--
--              -----------------------------------------|
--              | BLOCK LEVEL WRAPPER                    |
--              |                                        |
--              |    ---------------------               |
--              |    | ETHERNET MAC      |               |
--              |    | CORE              |  ---------    |
--              |    |                   |  |       |    |
--            --|--->| Tx            Tx  |--|       |--->|
--              |    | client        PHY |  |       |    |
--              |    | I/F           I/F |  |       |    |
--              |    |                   |  | PHY   |    |
--              |    |                   |  | I/F   |    |
--              |    |                   |  |       |    |
--              |    | Rx            Rx  |  |       |    |
--              |    | client        PHY |  |       |    |
--            <-|----| I/F           I/F |<-|       |<---|
--              |    |                   |  ---------    |
--              |    ---------------------               |
--              |                                        |
--              |     clock enable logic                 |
--              |                                        |
--              -----------------------------------------|
--

library unisim;
use unisim.vcomponents.all;

library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;
use ieee.numeric_std.all;


--------------------------------------------------------------------------------
-- The entity declaration for the block level example design.
--------------------------------------------------------------------------------

entity tri_mode_eth_mac_block is
   port(
      -- asynchronous reset
      reset                : in  std_logic;

      -- Reference clock for IDELAYCTRL's
      refclk               : in  std_logic;

      -- Client Receiver Interface
      ----------------------------
      rx_clk               : out std_logic;
      rx_enable            : out std_logic;
      rx_statistics_vector : out std_logic_vector(27 downto 0);
      rx_statistics_valid  : out std_logic;
      rx_data              : out std_logic_vector(7 downto 0);
      rx_data_valid        : out std_logic;
      rx_good_frame        : out std_logic;
      rx_bad_frame         : out std_logic;

      -- Client Transmitter Interface
      -------------------------------
      tx_clk               : out std_logic;
      tx_enable            : out std_logic;
      tx_ifg_delay         : in  std_logic_vector(7 downto 0);
      tx_statistics_vector : out std_logic_vector(31 downto 0);
      tx_statistics_valid  : out std_logic;
      tx_data              : in  std_logic_vector(7 downto 0);
      tx_data_valid        : in  std_logic;
      tx_ack               : out std_logic;
      tx_underrun          : in  std_logic;
      tx_collision         : out std_logic;
      tx_retransmit        : out std_logic;

      -- MAC Control Interface
      ------------------------
      pause_req            : in  std_logic;
      pause_val            : in  std_logic_vector(15 downto 0);

      -- GMII Interface
      -----------------
      gtx_clk              : in  std_logic;
      gmii_txd             : out std_logic_vector(7 downto 0);
      gmii_tx_en           : out std_logic;
      gmii_tx_er           : out std_logic;
      gmii_tx_clk          : out std_logic;
      gmii_rxd             : in  std_logic_vector(7 downto 0);
      gmii_rx_dv           : in  std_logic;
      gmii_rx_er           : in  std_logic;
      gmii_rx_clk          : in  std_logic;
      gmii_col             : in  std_logic;
      gmii_crs             : in  std_logic;
      mii_tx_clk           : in  std_logic;

      -- MDIO Interface
      -----------------
      mdio_i               : in  std_logic;
      mdio_o               : out std_logic;
      mdio_t               : out std_logic;
      mdc                  : out std_logic;

      -- Host Interface
      -----------------
      host_clk             : in  std_logic;
      host_opcode          : in  std_logic_vector(1 downto 0);
      host_addr            : in  std_logic_vector(9 downto 0);
      host_wr_data         : in  std_logic_vector(31 downto 0);
      host_req             : in  std_logic;
      host_miim_sel        : in  std_logic;
      host_rd_data         : out std_logic_vector(31 downto 0);
      host_miim_rdy        : out std_logic
   );
end tri_mode_eth_mac_block;


architecture wrapper of tri_mode_eth_mac_block is


   -----------------------------------------------------------------------------
   -- Component Declaration for TRIMAC (the Tri-Mode EMAC core).
   -----------------------------------------------------------------------------
   component tri_mode_eth_mac
   port(
      -- asynchronous reset
      reset                : in std_logic;

      -- Physical Interface of the core
      --------------------------------
      phyemactxenable      : in std_logic;
      emacphytxd           : out std_logic_vector(7 downto 0);
      emacphytxen          : out std_logic;
      emacphytxer          : out std_logic;
      phyemaccrs           : in std_logic;
      phyemaccol           : in std_logic;
      phyemacrxd           : in std_logic_vector(7 downto 0);
      phyemacrxdv          : in std_logic;
      phyemacrxer          : in std_logic;

      -- MDIO Interface
      -----------------
      emacphymclkout       : out std_logic;
      emacphymdtri         : out std_logic;
      emacphymdout         : out std_logic;
      phyemacmdin          : in std_logic;

      -- Client Transmitter Interface
      -------------------------------
      clientemactxd        : in std_logic_vector(7 downto 0);
      clientemactxdvld     : in std_logic;
      emacclienttxack      : out std_logic;
      clientemactxunderrun : in std_logic;
      emacclienttxcollision: out std_logic;
      emacclienttxretransmit: out std_logic;
      clientemactxifgdelay : in std_logic_vector(7 downto 0);
      clientemactxenable   : in std_logic;

      -- MAC Control Interface
      ------------------------
      clientemacpausereq   : in std_logic;
      clientemacpauseval   : in std_logic_vector(15 downto 0);

      -- Client Receiver Interface
      ----------------------------
      emacclientrxd        : out std_logic_vector(7 downto 0);
      emacclientrxdvld     : out std_logic;
      emacclientrxgoodframe: out std_logic;
      emacclientrxbadframe : out std_logic;
      clientemacrxenable   : in  std_logic;

      -- Client Transmitter Statistics
      --------------------------------
      emacclienttxstats    : out std_logic_vector(31 downto 0);
      emacclienttxstatsvld : out std_logic;

      -- Client Receiver Statistics
      -----------------------------
      emacclientrxstats    : out std_logic_vector(27 downto 0);
      emacclientrxstatsvld : out std_logic;
      -- Core Clock I/Os
      ------------------
      txgmiimiiclk         : in  std_logic;
      rxgmiimiiclk         : in  std_logic;

      -- Current Speed Indication
      ---------------------------
      speedis100           : out std_logic;
      speedis10100         : out std_logic;

      -- Host Interface
      -----------------
      hostclk              : in std_logic;
      hostopcode           : in std_logic_vector(1 downto 0);
      hostreq              : in std_logic;
      hostmiimsel          : in std_logic;
      hostaddr             : in std_logic_vector(9 downto 0);
      hostwrdata           : in std_logic_vector(31 downto 0);
      hostmiimrdy          : out std_logic;
      hostrddata           : out std_logic_vector(31 downto 0);

      -- Always tie to '0' unless connecting to the SGMII LogiCORE
      corehassgmii         : in  std_logic
      );
   end component;


   -----------------------------------------------------------------------------
   -- Component Declaration for the Clock Generation Logic
   -----------------------------------------------------------------------------
   component tx_clk_gen
   port (
      reset                : in  std_logic;
      speed_is_10_100      : in  std_logic;
      clk                  : in  std_logic;
      mii_tx_clk           : in  std_logic;
      tx_gmii_mii_clk      : out std_logic
   );
   end component;


   -----------------------------------------------------------------------------
   -- Component Declaration for the GMII IOB logic
   -----------------------------------------------------------------------------
   component gmii_if
   port(
      -- Synchronous resets
      tx_reset             : in  std_logic;
      rx_reset             : in  std_logic;

      -- Current operating speed is 10/100
      speed_is_10_100      : in  std_logic;

      -- The following ports are the GMII physical interface: these will be at
      -- pins on the FPGA
      gmii_txd             : out std_logic_vector(7 downto 0);
      gmii_tx_en           : out std_logic;
      gmii_tx_er           : out std_logic;
      gmii_tx_clk          : out std_logic;
      gmii_crs             : in  std_logic;
      gmii_col             : in  std_logic;
      gmii_rxd             : in  std_logic_vector(7 downto 0);
      gmii_rx_dv           : in  std_logic;
      gmii_rx_er           : in  std_logic;
      gmii_rx_clk          : in  std_logic;

      -- The following ports are the internal GMII connections from IOB logic
      -- to the TEMAC core
      txd_from_mac         : in  std_logic_vector(7 downto 0);
      tx_en_from_mac       : in  std_logic;
      tx_er_from_mac       : in  std_logic;
      tx_clk               : in  std_logic;
      crs_to_mac           : out std_logic;
      col_to_mac           : out std_logic;
      rxd_to_mac           : out std_logic_vector(7 downto 0);
      rx_dv_to_mac         : out std_logic;
      rx_er_to_mac         : out std_logic;

      -- Receiver clock for the MAC and Client Logic
      rx_clk               : out  std_logic
   );
   end component;


  ------------------------------------------------------------------------------
  -- Component declaration for the synchronisation flip-flop pair
  ------------------------------------------------------------------------------
  component sync_block
  port (
    clk                    : in  std_logic;    -- clock to be sync'ed to
    data_in                : in  std_logic;    -- Data to be 'synced'
    data_out               : out std_logic     -- synced data
    );
  end component;


  ------------------------------------------------------------------------------
  -- Component declaration for the reset synchroniser
  ------------------------------------------------------------------------------
  component reset_sync
  port (
    reset_in               : in  std_logic;    -- Active high asynchronous reset
    clk                    : in  std_logic;    -- clock to be sync'ed to
    enable                 : in  std_logic;    -- enable reset removal
    reset_out              : out std_logic     -- "Synchronised" reset signal
    );
  end component;


  ------------------------------------------------------------------------------
  -- internal signals used in this block level wrapper.
  ------------------------------------------------------------------------------

  attribute KEEP : string;

  -- Signals used for the IDELAYCTRL reset circuitry
  signal idelayctrl_reset_sync   : std_logic;                     -- Used to create a reset pulse in the IDELAYCTRL refclk domain.
  signal idelay_reset_cnt        : std_logic_vector(3 downto 0);  -- Counter to create a long IDELAYCTRL reset pulse.
  signal idelayctrl_reset        : std_logic;                     -- The reset pulse for the IDELAYCTRL.


  signal gmii_tx_en_int          : std_logic;                     -- Internal gmii_tx_en signal.
  signal gmii_tx_er_int          : std_logic;                     -- Internal gmii_tx_er signal.
  signal gmii_txd_int            : std_logic_vector(7 downto 0);  -- Internal gmii_txd signal.
  signal gmii_rx_dv_int          : std_logic;                     -- gmii_rx_dv registered in IOBs.
  signal gmii_rx_er_int          : std_logic;                     -- gmii_rx_er registered in IOBs.
  signal gmii_rxd_int            : std_logic_vector(7 downto 0);  -- gmii_rxd registered in IOBs.
  signal gmii_col_int            : std_logic;                     -- Collision signal from the PHY module
  signal gmii_crs_int            : std_logic;                     -- Carrier Sense signal from the PHY module

  signal rx_enable_int           : std_logic;                     -- rx enable signal routed from MAC to client loopback design example.
  signal tx_clk_int              : std_logic;                     -- Internal transmitter core clock signal.
  signal tx_enable_int           : std_logic;                     -- tx enable signal routed from the MAC to the client loopback design example.

  signal speedis100_int          : std_logic;                     -- Asserted when speed is 100Mb/s.
  signal speedis10100_int        : std_logic;                     -- Asserted when speed is 10Mb/s or 100Mb/s.
  signal rx_gmii_clk_int     : std_logic;                     -- Internal receive gmii/mii clock signal.
  signal tx_gmii_clk_int     : std_logic;                     -- Internal transmit gmii/mii clock signal.
  signal txspeedis10100          : std_logic;                     -- MAC speed setting resampled on the transmitter clock
  signal rxspeedis10100          : std_logic;                     -- MAC speed setting resampled on the receiver clock


  signal tx_gmii_reset       : std_logic;                     -- Synchronous reset in the MAC and gmii Tx domain
  signal rx_gmii_reset       : std_logic;                     -- Synchronous reset in the MAC and gmii Rx domain



  attribute keep of tx_gmii_clk_int    : signal is "true";
  attribute keep of rx_gmii_clk_int    : signal is "true";


begin



   -----------------------------------------------------------------------------
   -- An IDELAYCTRL primitive needs to be instantiated for the Fixed Tap Delay
   -- mode of the IDELAY.
   -- All IDELAYs in Fixed Tap Delay mode and the IDELAYCTRL primitives have
   -- to be LOC'ed in the UCF file.
   -----------------------------------------------------------------------------
   -- Instantiate IDELAYCTRL for all IDELAY and ODELAY elements in the design
   dlyctrl : IDELAYCTRL
   port map (
      RDY               => open,
      REFCLK            => refclk,
      RST               => idelayctrl_reset
   );


   -- Create a synchronous reset in the IDELAYCTRL refclk clock domain.
   idelayctrl_reset_gen : reset_sync
   port map(
      clk               => refclk,
      enable            => '1',
      reset_in          => reset,
      reset_out         => idelayctrl_reset_sync
   );


   -- Reset circuitry for the IDELAYCTRL reset.

   -- The IDELAYCTRL must experience a pulse which is at least 50 ns in
   -- duration.  This is ten clock cycles of the 200MHz refclk.  Here we
   -- drive the reset pulse for 12 clock cycles.
   process (refclk)
   begin
      if refclk'event and refclk = '1' then
         if idelayctrl_reset_sync = '1' then
            idelay_reset_cnt <= "0000";
            idelayctrl_reset <= '1';
         else
            idelayctrl_reset <= '1';
            case idelay_reset_cnt is
            when "0000"  => idelay_reset_cnt <= "0001";
            when "0001"  => idelay_reset_cnt <= "0010";
            when "0010"  => idelay_reset_cnt <= "0011";
            when "0011"  => idelay_reset_cnt <= "0100";
            when "0100"  => idelay_reset_cnt <= "0101";
            when "0101"  => idelay_reset_cnt <= "0110";
            when "0110"  => idelay_reset_cnt <= "0111";
            when "0111"  => idelay_reset_cnt <= "1000";
            when "1000"  => idelay_reset_cnt <= "1001";
            when "1001"  => idelay_reset_cnt <= "1010";
            when "1010"  => idelay_reset_cnt <= "1011";
            when "1011"  => idelay_reset_cnt <= "1100";
            when "1100"  => idelay_reset_cnt <= "1101";
            when "1101"  => idelay_reset_cnt <= "1110";
            when others  => idelay_reset_cnt <= "1110";
                            idelayctrl_reset <= '0';
            end case;
         end if;
      end if;
   end process;


   -----------------------------------------------------------------------------
   -- Transmitter Clock generation circuit. These circuits produce the clocks
   -- for 10/100/1000 operation.
   -----------------------------------------------------------------------------
   clock_inst : tx_clk_gen
   port map (
      reset             => reset,
      speed_is_10_100   => speedis10100_int,
      clk               => gtx_clk,
      mii_tx_clk        => mii_tx_clk,
      tx_gmii_mii_clk   => tx_gmii_clk_int
   );

   tx_clk_int <= tx_gmii_clk_int;

   -- Assign the internal clock signals to output ports.
   tx_clk <= tx_clk_int;
   rx_clk <= rx_gmii_clk_int;


   -----------------------------------------------------------------------------
   -- Clock Enable circuitry
   -----------------------------------------------------------------------------


   -- Resynchronise the speed selection signal in the receiver clock domain
   rxspeedis10100gen : sync_block
   port map(
      clk               => rx_gmii_clk_int,
      data_in           => speedis10100_int,
      data_out          => rxspeedis10100
   );

   -- Resynchronise the speed selection signal in the transmitter clock domain
   txspeedis10100gen : sync_block
   port map(
      clk               => tx_gmii_clk_int,
      data_in           => speedis10100_int,
      data_out          => txspeedis10100
   );

   -- Create the receiver clock enable
   rxcesamplegen : process(rx_gmii_clk_int)
   begin
     if rx_gmii_clk_int'event and rx_gmii_clk_int = '1' then
       if rx_gmii_reset = '1' then
         rx_enable_int <= '0';
       elsif rxspeedis10100 = '1' then
         rx_enable_int <= not(rx_enable_int) after 1 ps;
       else
         rx_enable_int <= '1' after 1 ps;
       end if;
     end if;
   end process rxcesamplegen;


   -- Create the transmitter clock enable
   txcesamplegen : process(tx_gmii_clk_int)
   begin
     if tx_gmii_clk_int'event and tx_gmii_clk_int = '1' then
       if tx_gmii_reset = '1' then
         tx_enable_int <= '0';
       elsif txspeedis10100 = '1' then
         tx_enable_int <= not(tx_enable_int) after 1 ps;
       else
         tx_enable_int <= '1' after 1 ps;
       end if;
     end if;
   end process txcesamplegen;


   -- Assign the internal clock enable signals to output ports.
   rx_enable <= rx_enable_int;
   tx_enable <= tx_enable_int;



   -----------------------------------------------------------------------------
   -- Instantiate reset synchronisers
   -----------------------------------------------------------------------------

   -- Generate a synchronous reset signal in the Tx clock domain
   tx_gmii_reset_gen : reset_sync
   port map(
      clk               => tx_gmii_clk_int,
      enable            => '1',
      reset_in          => reset,
      reset_out         => tx_gmii_reset
   );


   -- Generate a synchronous reset signal in the Rx clock domain
   rx_gmii_reset_gen : reset_sync
   port map(
      clk               => rx_gmii_clk_int,
      enable            => '1',
      reset_in          => reset,
      reset_out         => rx_gmii_reset
   );


   -----------------------------------------------------------------------------
   -- Instantiate GMII Interface
   -----------------------------------------------------------------------------

   -- Instantiate the GMII physical interface logic
   gmii_interface : gmii_if
   port map (
      -- Synchronous resets
      tx_reset          => tx_gmii_reset,
      rx_reset          => rx_gmii_reset,

      -- Current operating speed is 10/100
      speed_is_10_100   => speedis10100_int,

      -- The following ports are the GMII physical interface: these will be at
      -- pins on the FPGA
      gmii_txd          => gmii_txd,
      gmii_tx_en        => gmii_tx_en,
      gmii_tx_er        => gmii_tx_er,
      gmii_tx_clk       => gmii_tx_clk,
      gmii_col          => gmii_col,
      gmii_crs          => gmii_crs,
      gmii_rxd          => gmii_rxd,
      gmii_rx_dv        => gmii_rx_dv,
      gmii_rx_er        => gmii_rx_er,
      gmii_rx_clk       => gmii_rx_clk,

      -- The following ports are the internal GMII connections from IOB logic
      -- to the TEMAC core
      txd_from_mac      => gmii_txd_int,
      tx_en_from_mac    => gmii_tx_en_int,
      tx_er_from_mac    => gmii_tx_er_int,
      tx_clk            => tx_gmii_clk_int,
      col_to_mac        => gmii_col_int,
      crs_to_mac        => gmii_crs_int,
      rxd_to_mac        => gmii_rxd_int,
      rx_dv_to_mac      => gmii_rx_dv_int,
      rx_er_to_mac      => gmii_rx_er_int,

      -- Receiver clock for the MAC and Client Logic
      rx_clk            => rx_gmii_clk_int
   );


   -----------------------------------------------------------------------------
   -- Instantiate the TRIMAC core
   -----------------------------------------------------------------------------
   trimac_core : tri_mode_eth_mac
   port map (
      -- asynchronous reset
      reset                   => reset,

      -- Physical Interface of the core
      phyemactxenable         => '1',
      emacphytxd              => gmii_txd_int,
      emacphytxen             => gmii_tx_en_int,
      emacphytxer             => gmii_tx_er_int,
      phyemaccrs              => gmii_crs_int,
      phyemaccol              => gmii_col_int,
      phyemacrxd              => gmii_rxd_int,
      phyemacrxdv             => gmii_rx_dv_int,
      phyemacrxer             => gmii_rx_er_int,

      -- MDIO Interface
      emacphymclkout          => mdc,
      emacphymdtri            => mdio_t,
      emacphymdout            => mdio_o,
      phyemacmdin             => mdio_i,

      -- Client Transmitter Interface
      clientemactxd           => tx_data,
      clientemactxdvld        => tx_data_valid,
      emacclienttxack         => tx_ack,
      clientemactxunderrun    => tx_underrun,
      emacclienttxcollision   => tx_collision,
      emacclienttxretransmit  => tx_retransmit,
      clientemactxifgdelay    => tx_ifg_delay,
      clientemactxenable      => tx_enable_int,

      -- MAC Control Interface
      clientemacpausereq      => pause_req,
      clientemacpauseval      => pause_val,

      -- Client Receiver Interface
      emacclientrxd           => rx_data,
      emacclientrxdvld        => rx_data_valid,
      emacclientrxgoodframe   => rx_good_frame,
      emacclientrxbadframe    => rx_bad_frame,
      clientemacrxenable      => rx_enable_int,

      -- Client Transmitter Statistics
      emacclienttxstats       => tx_statistics_vector,
      emacclienttxstatsvld    => tx_statistics_valid,

      -- Client Receiver Statistics
      emacclientrxstats       => rx_statistics_vector,
      emacclientrxstatsvld    => rx_statistics_valid,

      -- Core Clock I/Os
      txgmiimiiclk            => tx_gmii_clk_int,
      rxgmiimiiclk            => rx_gmii_clk_int,

      -- Current Speed Indication
      speedis100              => speedis100_int,
      speedis10100            => speedis10100_int,

      -- Host Interface
      hostclk                 => host_clk,
      hostopcode              => host_opcode,
      hostreq                 => host_req,
      hostmiimsel             => host_miim_sel,
      hostaddr                => host_addr,
      hostwrdata              => host_wr_data,
      hostmiimrdy             => host_miim_rdy,
      hostrddata              => host_rd_data,

      -- Always tie to '0' unless connecting to the SGMII LogiCORE
      corehassgmii            => '0'
      );


end wrapper;
