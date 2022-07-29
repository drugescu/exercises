#!/bin/bash
#sudo apt install binutils-arm-none-eabi -y
#sudo apt -y install make gcc-arm-none-eabi binutils-arm-none-eabi gdb-arm-none-eabi libstdc++-arm-none-eabi-newlib libnewlib-arm-none-eabi qemu-system-arm 
#sudo apt install gdb-multiarch
#ln -s /usr/bin/gdb-multiarch /usr/bin/arm-none-eabi-gdb
arm-none-eabi-as -o sum.o sum.s
arm-none-eabi-ld -T 1.lds -o sum.elf sum.o
arm-none-eabi-nm -n sum.elf
arm-none-eabi-objdump -D sum.elf
make all gdb
