#!/bin/bash

#this instruction is to be run on shreyash for flashing into vaman

sudo python3 /home/shreyash/fpgaencoder/TinyFPGA-Programmer-Application/tinyfpga-programmer-gui.py --port /dev/ttyACM0 --appfpga /home/shreyash/fpgaencoder/helloworldfpga.bin --mode fpga --reset
