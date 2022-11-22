#! /bin/bash
#from rPi
#sudo python3 /home/ra1/fwc/arm-gcc/setup/TinyFPGA-Programmer-Application/tinyfpga-programmer-gui.py --port /dev/ttyACM0  --appfpga top.bin --m4app blink.bin --mode m4-fpga --reset
sudo python3 /home/ra1/fwc/arm-gcc/setup/TinyFPGA-Programmer-Application/tinyfpga-programmer-gui.py --port /dev/ttyACM0  --appfpga $2 --m4app $1 --mode m4-fpga --reset
