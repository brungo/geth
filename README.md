# README #

To run the example you have to get ISE full licence installed and running in a Linux OS.

### Ethernet core instatiation example on Xilinx ML605 Evaluation Board ###

* Run the makefile with 'run' argument
* Version 1.0

### How do I get set up? ###

#### Summary: ####
##### Generate the cores, example design and simulation project   
* Set the environment with **. /PATH_TO_ISE/ISE_DS/settings64.sh**
* Run **make** on the root directory
* Go to /geth/simulation directory and run the Makefile
* Once the simulation files were created, run **make see**


### Implementation notes ###

#### Clocks ####

There are at leaest four independent clock sources needed.
* gtx  clock (125MHz)
* host clock (gtx_clk/3)
* ref  clock (200MHz)
* mii_tx_clk100 (25MHz)

#### Using the example ####

Simple Xilinx ML605 Ethernet example, it's made only for data transmission.
It instatiates MAC Ethernet, GMII handler, rx & tx fifo controllers core,
reset and clocks generators required for a correct operation.
