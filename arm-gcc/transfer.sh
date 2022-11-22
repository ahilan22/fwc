#! /bin/bash
ip="192.168.0.109"
path="/home/ra1/fwc"
cd $1/GCC_Project/
make -j4
#scp output/bin/$1.bin ra1@$ip:$path
scp output/bin/$2.bin ra1@$ip:$path
#cd ../..
