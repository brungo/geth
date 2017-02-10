#!/usr/bin/make

all: run

run top_tb:
	fuse work.testbench -prj files.prj -L unisim -L secureip -timeprecision_vhdl fs -o testbench

see: top_tb
	./testbench -gui -tclbatch waves.tcl

clean:
	rm -fr isim *.wdb *.wcfg *.xmsgs *.log *.cmd top_tb
