
MODULE_NAME := virt_driver

#If KERNELRELEASE is defined, we've been invoked from the kernel build system
ifneq ($(KERNELRELEASE),)
obj-m += $(MODULE_NAME).o

else
ARCH ?= arm64
PWD := $(shell pwd)

all : modules

modules:
	$(MAKE) -C $(KERNEL_SRC) M=$(PWD) ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) $@

modules_install: modules
	$(MAKE) -C $(KERNEL_SRC) M=$(PWD) INSTALL_MOD_PATH=$(INSTALL_DIR) $@

clean:
	$(MAKE) -C $(KERNEL_SRC) M=$(PWD) ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) $@
endif

