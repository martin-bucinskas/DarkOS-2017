#!/bin/sh

nasm -f elf32 src/bootloader/bootloader.asm -o bin/bootloader/bootloader.o

i686-elf-gcc -c src/kernel/kernel.c -o bin/kernel/kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra

i686-elf-gcc -T src/linker.ld -o bin/darkos.bin -ffreestanding -O2 -nostdlib bin/bootloader/bootloader.o bin/kernel/kernel.o -lgcc

if grub-file --is-x86-multiboot bin/darkos.bin; then
	echo OS seems to be multiboot.
else
	echo OS is not a multiboot system!
fi

cp bin/darkos.bin darkos-iso/boot/darkos.bin
cp grub.cfg darkos-iso/boot/grub/grub.cfg

grub-mkrescue -o build/darkos.iso darkos-iso
