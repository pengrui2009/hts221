INSTALLDIR := /mnt/hgfs/share/ko
STAGING_DIR := /home/linux/openwrt/openwrt-offical/staging_dir
#CROSS_COMPILE := 

KERNELDIR := /home/linux/imx6/linux-3.14.52
PWD := $(shell pwd)

obj-m := hts221.o
hts221-objs := hts221_i2c.o hts221_core.o
# ccflags-y += -DHTS221_DEBUG
all:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf-
	arm-linux-gnueabihf-gcc -o test_hts221 test/test_hts221.c -I./
	#cp lora1278.ko $(INSTALLDIR)

clean:
	-rm -rf *.o *.ko *.mod.c .*.cmd .tmp_versions Module.symvers modules.order $(INSTALLDIR)/spidev.ko 
