MODULE_NAME =rpi3b

INCLUDE_DIR =-I$(src)/../inc

SRCS = main.c \
       gpio.c \
       uart.c \
       irq.c \
       ivt.c \
       rpi.c \
       spi.c \
       spi0.c

ccflags-y := $(INCLUDE_DIR)

OBJS = $(SRCS:.c=.o)

obj-m += $(MODULE_NAME).o

$(MODULE_NAME)-y = $(OBJS)

PWD := $(shell pwd)

all:
	make ARCH=arm CROSS_COMPILE=$(CROSS) -C $(KERNEL) SUBDIRS=$(PWD) modules

clean:
	make ARCH=arm CROSS_COMPILE=$(CROSS) -C $(KERNEL) SUBDIRS=$(PWD) clean
