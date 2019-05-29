# OculuS
Hobby operating system
# Set up
## GCC Cross Compiler for i686-elf
To set up the cross compiler download and untar http://newos.org/toolchains/i686-elf-4.9.1-Linux-x86_64.tar.xz<br>
Inside i686-elf-4.9.1-Linux-x86_64/bin there are two executables that will be used
to get a minimal OS running: `i686-elf-as` and `i686-elf-gcc` <br>
It is best to set up an alias that can be used to run these tools.

# Bootstrap Assembly
Assemble boot.s using `i686-elf-as boot.s -o boot.o` You can replace i686-elf-as
with the alias for that executable

# Compiling the Kernel
The kernel is written in C and can be compiled using 
`i686-elf-gcc -c kernel.c -o kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra`

# Linking the Kernel
Link the kernel using
`i686-elf-gcc -T linker.ld -o myos.bin -ffreestanding -O2 -nostdlib boot.o kernel.o -lgcc`

# Booting the Kernel 
Upon first set up run these commands
```
mkdir -p isodir/boot/grub
cp myos.bin isodir/boot/myos.bin
cp grub.cfg isodir/boot/grub/grub.cfg
grub-mkrescue -o myos.iso isodir
```
If you have already set these up just run these two commands
```
cp myos.bin isodir/boot/myos.bin
grub-mkrescue -o myos.iso isodir
```

# Running the OS via QEMU
`qemu-system-i386 -cdrom myos.iso`
## Boot failed: Could not read from CDROM (code 0009)
If your development system is booted from EFI it may be that you don't have the PC-BIOS version of the grub binaries installed anywhere. If you install them then grub-mkrescue will by default produce a hybrid ISO that will work in QEMU. On Ubuntu this can be achieved with: apt-get install grub-pc-bin.

# Developing
If you are editing kernel.c just run the compile.sh script and it will rebuild the project and launch the OS
