NASM=nasm
NASMFLAGS=-f elf32

ARCH=i686-elf
CC=$(ARCH)-gcc
CFLAGS=-std=gnu99 -ffreestanding -O2 -Wall -Wextra

LINKER=linker.ld
LDFLAGS=-ffreestanding -O2 -nostdlib

BOOT_PATH=src/bootloader
KERNEL_PATH=src/kernel

ASM_SOURCES=$(BOOT_PATH)/bootloader.asm
ASM_OBJECTS=$(ASM_SOURCES:.asm=.o)

C_SOURCES=$(KERNEL_PATH)/kernel.c
C_OBJECTS=$(C_SOURCES:.c=.o)

OUT=darkos

all: $(ASM_SOURCES) $(C_SOURCES) $(OUT)

$(OUT): $(ASM_OBJECTS) $(C_OBJECTS)
	$(CC) -T $(LINKER) -o $@ $(LDFLAGS) $(ASM_OBJECTS) $(C_OBJECTS) -lgcc

$(ASM_OBJECTS): $(ASM_SOURCES)
	$(NASM) $(NASMFLAGS) $< -o $@
#.asm.o:
#	$(NASM) $(NASMFLAGS) $< -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@
