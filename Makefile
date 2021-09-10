CROSS_COMPILE := riscv64-unknown-elf-
TOOLCHAIN_PATH ?= /opt/riscv/bin

CC := $(TOOLCHAIN_PATH)/$(CROSS_COMPILE)gcc
AS := $(TOOLCHAIN_PATH)/$(CROSS_COMPILE)as
LD := $(TOOLCHAIN_PATH)/$(CROSS_COMPILE)ld
OBJCOPY := $(TOOLCHAIN_PATH)/$(CROSS_COMPILE)objcopy

baremetal.bin : baremetal
	$(OBJCOPY) -O binary $^ $@

baremetal: start.o baremetal.o
	$(LD) -T ld.script -o $@ $^

baremetal.o: baremetal.c
	$(CC) -c -g -mcmodel=medany -o $@ $^

start.o: start.S
	$(AS) -g -o $@ $^

.PHONY: clean
clean:
	@rm baremetal *.o
