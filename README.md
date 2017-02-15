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

Ejemplo sencillo para utilizar con la placa de evaluación Xilinx ML605, suponiendo
que solamente se va a utilizar para enviar datos.
 Cuenta con el core MAC Ethernet, GMII handler, rx & tx fifo controller y generadores
de reset y clocks necesarios para el funcionamiento de los anteriores.
 El uso básico del ejemplo consta en escribir datos en la FIFO de entrada, 
