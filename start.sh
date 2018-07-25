#!/bin/sh

#location of cross compilation tool in this case is buildroot
LOC="/home/balaagh/rpi/build_root/buildroot"

if [ "$1" = "clean" ]
  then
     make KERNEL=$LOC/output/build/linux-custom CROSS=$LOC/output/host/bin/arm-linux- clean
else
  make KERNEL=$LOC/output/build/linux-custom CROSS=$LOC/output/host/bin/arm-linux-
fi
 

