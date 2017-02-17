--
-- Gigabit Ethernet on ml605
--
-- Author(s):
-- * Bruno Valinoti
--
-- Copyright (c) 2016 Authors and INTI
-- Distributed under the BSD 3-Clause License

library IEEE;
use IEEE.std_logic_1164.all;

entity Top is
 port(
   -- asynchronous reset
   reset_i                : in  std_logic;

   -- Reference clock for IDELAYCTRL's
   refclk_i               : in  std_logic;


   -- Client Receiver Statistics Interface
   ---------------------------------------
   rx_clk_o               : out std_logic;
   rx_statistics_vector_o : out std_logic;
   rx_statistics_valid_o  : out std_logic;

   -- Client Transmitter Statistics Interface
   ------------------------------------------
   tx_clk_o               : out std_logic;
   tx_statistics_vector_o : out std_logic;
   tx_statistics_valid_o  : out std_logic;

  -- MAC Control Interface
   ------------------------
   pause_req_i            : in  std_logic;
   pause_val_i            : in  std_logic;

   -- GMII Interface
   -----------------
   gtx_clk_i              : in  std_logic;
   gmii_txd_o             : out std_logic_vector(7 downto 0);
   gmii_tx_en_o           : out std_logic;
   gmii_tx_er_o           : out std_logic;
   gmii_tx_clk_o          : out std_logic;
   gmii_rxd_i             : in  std_logic_vector(7 downto 0);
   gmii_rx_dv_i           : in  std_logic;
   gmii_rx_er_i           : in  std_logic;
   gmii_rx_clk_i          : in  std_logic;
   gmii_col_i             : in  std_logic;
   gmii_crs_i             : in  std_logic;
   mii_tx_clk_i           : in  std_logic;

   -- MDIO Interface
   -----------------
   mdio_io                : inout  std_logic;
   mdc_o                  : out std_logic;

   -- Host Interface
   -----------------
   host_clk_i             : in  std_logic;
   host_opcode_i          : in  std_logic_vector(1 downto 0);
   host_addr_i            : in  std_logic_vector(9 downto 0);
   host_wr_data_i         : in  std_logic_vector(31 downto 0);
   host_req_i             : in  std_logic;
   host_miim_sel_i        : in  std_logic;
   host_rd_data_o         : out std_logic_vector(31 downto 0);
   host_miim_rdy_o        : out std_logic;

   --Write FiFO interface
   ----------------------
   tx_ll_data_in_i        : in  std_logic_vector(7 downto 0);
   tx_ll_sof_in_n_i       : in  std_logic;
   tx_ll_eof_in_n_i       : in  std_logic;
   tx_ll_src_rdy_in_n_i   : in  std_logic;
   tx_ll_dst_rdy_out_n_i  : out std_logic
   );
end entity Top;




architecture Behav of Top is
------------------------------------------------------------------------------
-- Constants for Configuration Register Addresses
------------------------------------------------------------------------------

-- Management configuration register address (0x340)
constant config_management_add : std_logic_vector(8 downto 0) := "101000000";

-- Flow control configuration register address (0x2C0)
constant config_flow_ctrl_add  : std_logic_vector(8 downto 0) := "011000000";

-- Receiver configuration register address  (0x240)
constant receiver_add          : std_logic_vector(8 downto 0) := "001000000";

-- Transmitter configuration register address (0x280)
constant transmitter_add       : std_logic_vector(8 downto 0) := "010000000";

-- EMAC configuration register address (0x300)
constant emac_config_add       : std_logic_vector(8 downto 0) := "100000000";



------------------------------------------------------------------------------
-- types to support frame data
------------------------------------------------------------------------------
-- Tx Data and Data_valid record
type data_typ is record
    data : bit_vector(7 downto 0);        -- data
    valid : bit;                          -- data_valid
    error : bit;                          -- data_error
end record;
type frame_of_data_typ is array (natural range <>) of data_typ;

-- Tx Data, Data_valid and underrun record
type frame_typ is record
    columns   : frame_of_data_typ(0 to 65);-- data field
    bad_frame : boolean;                   -- does this frame contain an error?
end record;
type frame_typ_ary is array (natural range <>) of frame_typ;

constant frame_data : frame_typ_ary := (
 -------------
 -- Frame 0
 -------------
  0          => (
    columns  => (
      0      => ( DATA => X"DA", VALID => '1', ERROR => '0'), -- Destination Address (DA)
      1      => ( DATA => X"02", VALID => '1', ERROR => '0'),
      2      => ( DATA => X"03", VALID => '1', ERROR => '0'),
      3      => ( DATA => X"04", VALID => '1', ERROR => '0'),
      4      => ( DATA => X"05", VALID => '1', ERROR => '0'),
      5      => ( DATA => X"06", VALID => '1', ERROR => '0'),
      6      => ( DATA => X"5A", VALID => '1', ERROR => '0'), -- Source Address (5A)
      7      => ( DATA => X"02", VALID => '1', ERROR => '0'),
      8      => ( DATA => X"03", VALID => '1', ERROR => '0'),
      9      => ( DATA => X"04", VALID => '1', ERROR => '0'),
     10      => ( DATA => X"05", VALID => '1', ERROR => '0'),
     11      => ( DATA => X"06", VALID => '1', ERROR => '0'),
     12      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     13      => ( DATA => X"2E", VALID => '1', ERROR => '0'), -- Length/Type = Length = 46
     14      => ( DATA => X"01", VALID => '1', ERROR => '0'),
     15      => ( DATA => X"02", VALID => '1', ERROR => '0'),
     16      => ( DATA => X"03", VALID => '1', ERROR => '0'),
     17      => ( DATA => X"04", VALID => '1', ERROR => '0'),
     18      => ( DATA => X"05", VALID => '1', ERROR => '0'),
     19      => ( DATA => X"06", VALID => '1', ERROR => '0'),
     20      => ( DATA => X"07", VALID => '1', ERROR => '0'),
     21      => ( DATA => X"08", VALID => '1', ERROR => '0'),
     22      => ( DATA => X"09", VALID => '1', ERROR => '0'),
     23      => ( DATA => X"0A", VALID => '1', ERROR => '0'),
     24      => ( DATA => X"0B", VALID => '1', ERROR => '0'),
     25      => ( DATA => X"0C", VALID => '1', ERROR => '0'),
     26      => ( DATA => X"0D", VALID => '1', ERROR => '0'),
     27      => ( DATA => X"0E", VALID => '1', ERROR => '0'),
     28      => ( DATA => X"0F", VALID => '1', ERROR => '0'),
     29      => ( DATA => X"10", VALID => '1', ERROR => '0'),
     30      => ( DATA => X"11", VALID => '1', ERROR => '0'),
     31      => ( DATA => X"12", VALID => '1', ERROR => '0'),
     32      => ( DATA => X"13", VALID => '1', ERROR => '0'),
     33      => ( DATA => X"14", VALID => '1', ERROR => '0'),
     34      => ( DATA => X"15", VALID => '1', ERROR => '0'),
     35      => ( DATA => X"16", VALID => '1', ERROR => '0'),
     36      => ( DATA => X"17", VALID => '1', ERROR => '0'),
     37      => ( DATA => X"18", VALID => '1', ERROR => '0'),
     38      => ( DATA => X"19", VALID => '1', ERROR => '0'),
     39      => ( DATA => X"1A", VALID => '1', ERROR => '0'),
     40      => ( DATA => X"1B", VALID => '1', ERROR => '0'),
     41      => ( DATA => X"1C", VALID => '1', ERROR => '0'),
     42      => ( DATA => X"1D", VALID => '1', ERROR => '0'),
     43      => ( DATA => X"1E", VALID => '1', ERROR => '0'),
     44      => ( DATA => X"1F", VALID => '1', ERROR => '0'),
     45      => ( DATA => X"20", VALID => '1', ERROR => '0'),
     46      => ( DATA => X"21", VALID => '1', ERROR => '0'),
     47      => ( DATA => X"22", VALID => '1', ERROR => '0'),
     48      => ( DATA => X"23", VALID => '1', ERROR => '0'),
     49      => ( DATA => X"24", VALID => '1', ERROR => '0'),
     50      => ( DATA => X"25", VALID => '1', ERROR => '0'),
     51      => ( DATA => X"26", VALID => '1', ERROR => '0'),
     52      => ( DATA => X"27", VALID => '1', ERROR => '0'),
     53      => ( DATA => X"28", VALID => '1', ERROR => '0'),
     54      => ( DATA => X"29", VALID => '1', ERROR => '0'),
     55      => ( DATA => X"2A", VALID => '1', ERROR => '0'),
     56      => ( DATA => X"2B", VALID => '1', ERROR => '0'),
     57      => ( DATA => X"2C", VALID => '1', ERROR => '0'),
     58      => ( DATA => X"2D", VALID => '1', ERROR => '0'),
     59      => ( DATA => X"2E", VALID => '0', ERROR => '0'), -- 46th Byte of Data
     others  => ( DATA => X"00", VALID => '0', ERROR => '0')),

    -- No error in this frame
    bad_frame => false),


 -------------
 -- Frame 1
 -------------
  1          => (
    columns  => (
      0      => ( DATA => X"DA", VALID => '1', ERROR => '0'), -- Destination Address (DA)
      1      => ( DATA => X"02", VALID => '1', ERROR => '0'),
      2      => ( DATA => X"03", VALID => '1', ERROR => '0'),
      3      => ( DATA => X"04", VALID => '1', ERROR => '0'),
      4      => ( DATA => X"05", VALID => '1', ERROR => '0'),
      5      => ( DATA => X"06", VALID => '1', ERROR => '0'),
      6      => ( DATA => X"5A", VALID => '1', ERROR => '0'), -- Source Address (5A)
      7      => ( DATA => X"02", VALID => '1', ERROR => '0'),
      8      => ( DATA => X"03", VALID => '1', ERROR => '0'),
      9      => ( DATA => X"04", VALID => '1', ERROR => '0'),
     10      => ( DATA => X"05", VALID => '1', ERROR => '0'),
     11      => ( DATA => X"06", VALID => '1', ERROR => '0'),
     12      => ( DATA => X"80", VALID => '1', ERROR => '0'), -- Length/Type = Type = 8000
     13      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     14      => ( DATA => X"01", VALID => '1', ERROR => '0'),
     15      => ( DATA => X"02", VALID => '1', ERROR => '0'),
     16      => ( DATA => X"03", VALID => '1', ERROR => '0'),
     17      => ( DATA => X"04", VALID => '1', ERROR => '0'),
     18      => ( DATA => X"05", VALID => '1', ERROR => '0'),
     19      => ( DATA => X"06", VALID => '1', ERROR => '0'),
     20      => ( DATA => X"07", VALID => '1', ERROR => '0'),
     21      => ( DATA => X"08", VALID => '1', ERROR => '0'),
     22      => ( DATA => X"09", VALID => '1', ERROR => '0'),
     23      => ( DATA => X"0A", VALID => '1', ERROR => '0'),
     24      => ( DATA => X"0B", VALID => '1', ERROR => '0'),
     25      => ( DATA => X"0C", VALID => '1', ERROR => '0'),
     26      => ( DATA => X"0D", VALID => '1', ERROR => '0'),
     27      => ( DATA => X"0E", VALID => '1', ERROR => '0'),
     28      => ( DATA => X"0F", VALID => '1', ERROR => '0'),
     29      => ( DATA => X"10", VALID => '1', ERROR => '0'),
     30      => ( DATA => X"11", VALID => '1', ERROR => '0'),
     31      => ( DATA => X"12", VALID => '1', ERROR => '0'),
     32      => ( DATA => X"13", VALID => '1', ERROR => '0'),
     33      => ( DATA => X"14", VALID => '1', ERROR => '0'),
     34      => ( DATA => X"15", VALID => '1', ERROR => '0'),
     35      => ( DATA => X"16", VALID => '1', ERROR => '0'),
     36      => ( DATA => X"17", VALID => '1', ERROR => '0'),
     37      => ( DATA => X"18", VALID => '1', ERROR => '0'),
     38      => ( DATA => X"19", VALID => '1', ERROR => '0'),
     39      => ( DATA => X"1A", VALID => '1', ERROR => '0'),
     40      => ( DATA => X"1B", VALID => '1', ERROR => '0'),
     41      => ( DATA => X"1C", VALID => '1', ERROR => '0'),
     42      => ( DATA => X"1D", VALID => '1', ERROR => '0'),
     43      => ( DATA => X"1E", VALID => '1', ERROR => '0'),
     44      => ( DATA => X"1F", VALID => '1', ERROR => '0'),
     45      => ( DATA => X"20", VALID => '1', ERROR => '0'),
     46      => ( DATA => X"21", VALID => '1', ERROR => '0'),
     47      => ( DATA => X"22", VALID => '1', ERROR => '0'),
     48      => ( DATA => X"23", VALID => '1', ERROR => '0'),
     49      => ( DATA => X"24", VALID => '1', ERROR => '0'),
     50      => ( DATA => X"25", VALID => '1', ERROR => '0'),
     51      => ( DATA => X"26", VALID => '1', ERROR => '0'),
     52      => ( DATA => X"27", VALID => '1', ERROR => '0'),
     53      => ( DATA => X"28", VALID => '1', ERROR => '0'),
     54      => ( DATA => X"29", VALID => '1', ERROR => '0'),
     55      => ( DATA => X"2A", VALID => '1', ERROR => '0'),
     56      => ( DATA => X"2B", VALID => '1', ERROR => '0'),
     57      => ( DATA => X"2C", VALID => '1', ERROR => '0'),
     58      => ( DATA => X"2D", VALID => '1', ERROR => '0'),
     59      => ( DATA => X"2E", VALID => '1', ERROR => '0'),
     60      => ( DATA => X"2F", VALID => '1', ERROR => '0'), -- 47th Data byte
     others  => ( DATA => X"00", VALID => '0', ERROR => '0')),

    -- No error in this frame
    bad_frame => false),


 -------------
 -- Frame 2
 -------------
  2          => (
    columns  => (
      0      => ( DATA => X"DA", VALID => '1', ERROR => '0'), -- Destination Address (DA)
      1      => ( DATA => X"02", VALID => '1', ERROR => '0'),
      2      => ( DATA => X"03", VALID => '1', ERROR => '0'),
      3      => ( DATA => X"04", VALID => '1', ERROR => '0'),
      4      => ( DATA => X"05", VALID => '1', ERROR => '0'),
      5      => ( DATA => X"06", VALID => '1', ERROR => '0'),
      6      => ( DATA => X"5A", VALID => '1', ERROR => '0'), -- Source Address (5A)
      7      => ( DATA => X"02", VALID => '1', ERROR => '0'),
      8      => ( DATA => X"03", VALID => '1', ERROR => '0'),
      9      => ( DATA => X"04", VALID => '1', ERROR => '0'),
     10      => ( DATA => X"05", VALID => '1', ERROR => '0'),
     11      => ( DATA => X"06", VALID => '1', ERROR => '0'),
     12      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     13      => ( DATA => X"2E", VALID => '1', ERROR => '0'), -- Length/Type = Length = 46
     14      => ( DATA => X"01", VALID => '1', ERROR => '0'),
     15      => ( DATA => X"02", VALID => '1', ERROR => '0'),
     16      => ( DATA => X"03", VALID => '1', ERROR => '0'),
     17      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     18      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     19      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     20      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     21      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     22      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     23      => ( DATA => X"00", VALID => '1', ERROR => '1'), -- Error asserted
     24      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     25      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     26      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     27      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     28      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     29      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     30      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     31      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     32      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     33      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     34      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     35      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     36      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     37      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     38      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     39      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     40      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     41      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     42      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     43      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     44      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     45      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     46      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     47      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     48      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     49      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     50      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     51      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     52      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     53      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     54      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     55      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     56      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     57      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     58      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     59      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     others  => ( DATA => X"00", VALID => '0', ERROR => '0')),

     -- Error this frame
    bad_frame => true),


 -------------
 -- Frame 3
 -------------
 3          => (
    columns  => (
      0      => ( DATA => X"DA", VALID => '1', ERROR => '0'), -- Destination Address (DA)
      1      => ( DATA => X"02", VALID => '1', ERROR => '0'),
      2      => ( DATA => X"03", VALID => '1', ERROR => '0'),
      3      => ( DATA => X"04", VALID => '1', ERROR => '0'),
      4      => ( DATA => X"05", VALID => '1', ERROR => '0'),
      5      => ( DATA => X"06", VALID => '1', ERROR => '0'),
      6      => ( DATA => X"5A", VALID => '1', ERROR => '0'), -- Source Address (5A)
      7      => ( DATA => X"02", VALID => '1', ERROR => '0'),
      8      => ( DATA => X"03", VALID => '1', ERROR => '0'),
      9      => ( DATA => X"04", VALID => '1', ERROR => '0'),
     10      => ( DATA => X"05", VALID => '1', ERROR => '0'),
     11      => ( DATA => X"06", VALID => '1', ERROR => '0'),
     12      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     13      => ( DATA => X"03", VALID => '1', ERROR => '0'), -- Length/Type = Length = 03
     14      => ( DATA => X"01", VALID => '1', ERROR => '0'), -- Therefore padding is required
     15      => ( DATA => X"02", VALID => '1', ERROR => '0'),
     16      => ( DATA => X"03", VALID => '1', ERROR => '0'),
     17      => ( DATA => X"00", VALID => '1', ERROR => '0'), -- Padding starts here
     18      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     19      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     20      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     21      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     22      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     23      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     24      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     25      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     26      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     27      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     28      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     29      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     30      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     31      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     32      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     33      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     34      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     35      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     36      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     37      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     38      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     39      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     40      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     41      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     42      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     43      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     44      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     45      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     46      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     47      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     48      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     49      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     50      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     51      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     52      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     53      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     54      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     55      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     56      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     57      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     58      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     59      => ( DATA => X"00", VALID => '1', ERROR => '0'),
     others  => ( DATA => X"00", VALID => '0', ERROR => '0')),

    -- No error in this frame
    bad_frame => false));


 signal gtx_clk      : std_logic;
 signal host_clk     : std_logic;
 signal ref_c

begin

end architecture Behav;
