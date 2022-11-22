#!/bin/bash
ip="192.168.5.209"
path="/home/ra1/fwc-1/arm-gcc/setup/"
cd $1/GCC_Project/
make -j4
scp output/bin/$1.bin ra1@$ip:$path
cd ../..
