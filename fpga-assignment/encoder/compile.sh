#!/bin/bash

#cimmand ti compile helloworldfpga.v file

ql_symbiflow -compile -src /data/data/com.termux/files/home/fpga-assignment/encoder -d ql-eos-s3 -P PU64 -v helloworldfpga.v -t helloworldfpga -p quickfeather.pcf -dump binary
