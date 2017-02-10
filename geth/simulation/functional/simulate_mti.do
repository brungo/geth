vlib work
vmap work work

echo "Compiling Core Simulation Model"
vcom -work work ../../../geth.vhd

echo "Compiling Example Design"
vcom -work work \
../../example_design/fifo/tx_client_fifo.vhd \
../../example_design/fifo/rx_client_fifo.vhd \
../../example_design/fifo/ten_100_1g_eth_fifo.vhd \
../../example_design/address_swap_module.vhd \
../../example_design/physical/gmii_if.vhd \
../../example_design/tx_clk_gen.vhd \
../../example_design/sync_block.vhd \
../../example_design/reset_sync.vhd \
../../example_design/geth_block.vhd \
../../example_design/geth_locallink.vhd \
../../example_design/geth_example_design.vhd

echo "Compiling Test Bench"
vcom -work work ../demo_tb.vhd

echo "Starting simulation"
vsim -t ps work.testbench -voptargs="+acc+testbench+/testbench/dut+/testbench/dut/trimac_locallink"
do wave_mti.do
run -all
