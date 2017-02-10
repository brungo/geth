#!/usr/bin/make

COREGEN := $(shell command -v coregen 2> /dev/null)
prepare:
ifneq ($(COREGEN),)
	mkdir -p temp
	coregen -p coregen.cgp -b tri_mode_eth_mac.xco
	rm coregen.log
else
	@echo "ERROR: coregen not found."
	@echo "Please prepare the environment running something like:"
	@echo "$ . /PATH_TO_ISE/ISE_DS/settings64.sh"
	@echo "Note: this design needs ISE Design Suite with support and a valid license for Virtex 6 LXT 240."
endif

