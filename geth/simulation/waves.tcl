wcfg new

wave add /testbench/dut/trimac_locallink/trimac_block/reset
wave add /testbench/dut/trimac_locallink/trimac_block/refclk
wave add /testbench/dut/trimac_locallink/trimac_block/rx_enable

divider add "GMII"
set GMII [group add "GMII"]
wave add -into $GMII /testbench/gtx_clk
wave add -into $GMII /testbench/gmii_tx_clk
wave add -into $GMII /testbench/gmii_txd -radix hex
wave add -into $GMII /testbench/gmii_tx_en
wave add -into $GMII /testbench/gmii_tx_er
wave add -into $GMII /testbench/gmii_rx_clk
wave add -into $GMII /testbench/gmii_rxd -radix hex
wave add -into $GMII /testbench/gmii_rx_dv
wave add -into $GMII /testbench/gmii_rx_er
wave add -into $GMII /testbench/gmii_crs
wave add -into $GMII /testbench/gmii_col
wave add -into $GMII /testbench/mii_tx_clk

divider add "Tx_if"
set Tx_if [group add "Tx_if"]
wave add -into $Tx_if /testbench/dut/trimac_locallink/trimac_block/tx_clk
wave add -into $Tx_if /testbench/dut/trimac_locallink/trimac_block/tx_enable
wave add -into $Tx_if /testbench/dut/trimac_locallink/trimac_block/tx_ifg_delay
wave add -into $Tx_if /testbench/dut/trimac_locallink/trimac_block/tx_statistics_vector
wave add -into $Tx_if /testbench/dut/trimac_locallink/trimac_block/tx_statistics_valid
wave add -into $Tx_if /testbench/dut/trimac_locallink/trimac_block/tx_data -radix hex
wave add -into $Tx_if /testbench/dut/trimac_locallink/trimac_block/tx_data_valid
wave add -into $Tx_if /testbench/dut/trimac_locallink/trimac_block/tx_ack
wave add -into $Tx_if /testbench/dut/trimac_locallink/trimac_block/tx_underrun
wave add -into $Tx_if /testbench/dut/trimac_locallink/trimac_block/tx_collision
wave add -into $Tx_if /testbench/dut/trimac_locallink/trimac_block/tx_retransmit

divider add "Rx_if"
set Rx_if [group add "Rx_if"]
wave add -into $Rx_if /testbench/dut/trimac_locallink/trimac_block/rx_clk
wave add -into $Rx_if /testbench/dut/trimac_locallink/trimac_block/rx_enable
wave add -into $Rx_if /testbench/dut/trimac_locallink/trimac_block/rx_statistics_vector
wave add -into $Rx_if /testbench/dut/trimac_locallink/trimac_block/rx_statistics_valid
wave add -into $Rx_if /testbench/dut/trimac_locallink/trimac_block/rx_data -radix hex
wave add -into $Rx_if /testbench/dut/trimac_locallink/trimac_block/rx_data_valid
wave add -into $Rx_if /testbench/dut/trimac_locallink/trimac_block/rx_good_frame
wave add -into $Rx_if /testbench/dut/trimac_locallink/trimac_block/rx_bad_frame

#divider add "MAC control IF"
#wave add /testbench/dut/trimac_locallink/trimac_block/pause_req
#wave add /testbench/dut/trimac_locallink/trimac_block/pause_val
#wave add /testbench/dut/client_side_asm/rx_ll_data_in -radix hex
#wave add /testbench/dut/client_side_asm/rx_ll_data_out -radix hex

divider add "FIFO_Control"
set FIFO_Control [group add "FIFO_Control"]
wave add -into $FIFO_Control /testbench/dut/trimac_locallink/client_side_FIFO/tx_ll_clock
wave add -into $FIFO_Control /testbench/dut/trimac_locallink/client_side_FIFO/tx_ll_reset
wave add -into $FIFO_Control /testbench/dut/trimac_locallink/client_side_FIFO/tx_ll_data_in -radix hex
wave add -into $FIFO_Control /testbench/dut/trimac_locallink/client_side_FIFO/tx_ll_sof_in_n
wave add -into $FIFO_Control /testbench/dut/trimac_locallink/client_side_FIFO/tx_ll_eof_in_n
wave add -into $FIFO_Control /testbench/dut/trimac_locallink/client_side_FIFO/tx_ll_src_rdy_in_n
wave add -into $FIFO_Control /testbench/dut/trimac_locallink/client_side_FIFO/tx_ll_dst_rdy_out_n
wave add -into $FIFO_Control /testbench/dut/trimac_locallink/client_side_FIFO/rx_ll_clock
wave add -into $FIFO_Control /testbench/dut/trimac_locallink/client_side_FIFO/rx_ll_reset
wave add -into $FIFO_Control /testbench/dut/trimac_locallink/client_side_FIFO/rx_ll_data_out -radix hex
wave add -into $FIFO_Control /testbench/dut/trimac_locallink/client_side_FIFO/rx_ll_sof_out_n
wave add -into $FIFO_Control /testbench/dut/trimac_locallink/client_side_FIFO/rx_ll_eof_out_n
wave add -into $FIFO_Control /testbench/dut/trimac_locallink/client_side_FIFO/rx_ll_src_rdy_out_n
wave add -into $FIFO_Control /testbench/dut/trimac_locallink/client_side_FIFO/rx_ll_dst_rdy_in_n
run 5000 us
quit
