#!/bin/bash

#this instruction is to be run on laptop for flashing into vaman

sudo python3 /home/shreyash/ip/TinyFPGA-Programmer-Application/tinyfpga-programmer-gui.py --port /dev/ttyACM0  --appfpga top.bin --m4app encoder.bin --mode m4-fpga --reset


