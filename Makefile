MODULE_NAME =rpi3b

PWD := $(shell pwd)

INCLUDE_DIR =-I$(src)/inc            \
             -I$(src)/peripheral/inc \
             -I$(src)/cdev/inc

SRCS = peripheral/src/main.c \
       peripheral/src/gpio.c \
       peripheral/src/uart.c \
       peripheral/src/irq.c  \
       peripheral/src/ivt.c  \
       peripheral/src/rpi.c  \
       peripheral/src/spi.c  \
       peripheral/src/spi0.c \
       cdev/src/cdev.c

ccflags-y := $(INCLUDE_DIR)

OBJS = $(SRCS:.c=.o)

obj-m += $(MODULE_NAME).o

$(MODULE_NAME)-y = $(OBJS)


all:
	make ARCH=arm CROSS_COMPILE=$(CROSS) -C $(KERNEL) SUBDIRS=$(PWD) modules

clean:
	make ARCH=arm CROSS_COMPILE=$(CROSS) -C $(KERNEL) SUBDIRS=$(PWD) clean
