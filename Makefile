#
#
#

#   *** MACROS
BOOTPATH=./isodir/boot
LINKFLAGS=-ffreestanding -fno-builtin -nostartfiles -nostdlib
COMPILERPATH=~/opt/cross/bin/


all: boot.o kernel.o app copybins

boot.o: boot.S
	$(COMPILERPATH)i586-elf-gcc -c boot.S

kernel.o: kernel.c
	$(COMPILERPATH)i586-elf-gcc -c kernel.c

app: linker.ld boot.o kernel.o
	$(COMPILERPATH)i586-elf-gcc -T linker.ld -o myos.bin $(LINKFLAGS) boot.o kernel.o -lgcc
         
copybins:
	-@cp *.bin $(BOOTPATH) 2>/dev/null

clean:
	-@rm -f *.o
	-@rm -f *.bin
	-@rm -f ./isodir/boot/*.bin

