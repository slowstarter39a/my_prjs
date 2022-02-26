
MODULE_NAME := virt_driver

#If KERNELRELEASE is defined, we've been invoked from the kernel build system
ifneq ($(KERNELRELEASE,)
obj-m += $(MODULE_NAME).o

else
ARCH ?= arm64
PWD := $(shell pwd)

all : default

modules:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) $@

clean:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) $@
endif

