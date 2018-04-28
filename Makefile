#
# Makefile for the input misc STM acc lis3dh driver
#
obj-m := hts221.o
hts221-objs := hts221_core.o hts221_i2c.o
KERNELDIR := /home/linux/openwrt/gateway/linux_3.14/
PWD := $(shell pwd)

all:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- 	
# Makefile for the input misc hts221 driver.
#


# ccflags-y += -DHTS221_DEBUG
