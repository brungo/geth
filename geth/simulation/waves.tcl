wcfg new

wave add /testbench/dut/trimac_locallink/trimac_block/reset
wave add /testbench/dut/trimac_locallink/trimac_block/refclk
wave add /testbench/dut/trimac_locallink/trimac_block/rx_enable

divider add "GMII"
wave add /testbench/gtx_clk
wave add /testbench/gmii_tx_clk
wave add /testbench/gmii_txd -radix hex
wave add /testbench/gmii_tx_en
wave add /testbench/gmii_tx_er
wave add /testbench/gmii_rx_clk
wave add /testbench/gmii_rxd -radix hex
wave add /testbench/gmii_rx_dv
wave add /testbench/gmii_rx_er
wave add /testbench/gmii_crs
wave add /testbench/gmii_col
wave add /testbench/mii_tx_clk

divider add "Tx_if"
wave add /testbench/dut/trimac_locallink/trimac_block/tx_clk
wave add /testbench/dut/trimac_locallink/trimac_block/tx_enable
wave add /testbench/dut/trimac_locallink/trimac_block/tx_ifg_delay
wave add /testbench/dut/trimac_locallink/trimac_block/tx_statistics_vector
wave add /testbench/dut/trimac_locallink/trimac_block/tx_statistics_valid
wave add /testbench/dut/trimac_locallink/trimac_block/tx_data -radix hex
wave add /testbench/dut/trimac_locallink/trimac_block/tx_data_valid
wave add /testbench/dut/trimac_locallink/trimac_block/tx_ack
wave add /testbench/dut/trimac_locallink/trimac_block/tx_underrun
wave add /testbench/dut/trimac_locallink/trimac_block/tx_collision
wave add /testbench/dut/trimac_locallink/trimac_block/tx_retransmit

divider add "Rx_if"
wave add /testbench/dut/trimac_locallink/trimac_block/rx_clk
wave add /testbench/dut/trimac_locallink/trimac_block/rx_enable
wave add /testbench/dut/trimac_locallink/trimac_block/rx_statistics_vector
wave add /testbench/dut/trimac_locallink/trimac_block/rx_statistics_valid
wave add /testbench/dut/trimac_locallink/trimac_block/rx_data -radix hex
wave add /testbench/dut/trimac_locallink/trimac_block/rx_data_valid
wave add /testbench/dut/trimac_locallink/trimac_block/rx_good_frame
wave add /testbench/dut/trimac_locallink/trimac_block/rx_bad_frame

#divider add "MAC control IF"
#wave add /testbench/dut/trimac_locallink/trimac_block/pause_req
#wave add /testbench/dut/trimac_locallink/trimac_block/pause_val
#wave add /testbench/dut/client_side_asm/rx_ll_data_in -radix hex
#wave add /testbench/dut/client_side_asm/rx_ll_data_out -radix hex

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
