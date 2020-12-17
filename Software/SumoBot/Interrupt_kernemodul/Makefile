ifeq ($(KERNELRELEASE),)
KERNELDIR = ~/sources/rpi-5.4.51/
PWD := $(shell pwd)

default:
	$(MAKE) ARCH=arm CROSS_COMPILE=arm-poky-linux-gnueabi- -C $(KERNELDIR) M=$(PWD) modules

else

	obj-m := AttackSensor_kernelModule.o
	ccflags-y := -std=gnu99 -Wno-declaration-after-statement -Werror

endif
