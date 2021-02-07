LDFLAGS := -subsystem:efi_application -nodefaultlib -subsystem:efi_application -dll

default:
	make by-clang
	make run

clean:
	rm -f *.s *.o *.lib *.efi

run: bios/RELEASEX64_OVMF.fd mnt/EFI/BOOT/BOOTx64.EFI
	qemu-system-x86_64 --bios bios/RELEASEX64_OVMF.fd -drive format=raw,file=fat:rw:mnt

bios/RELEASEX64_OVMF.fd:
	mkdir -p bios
	wget "https://github.com/retrage/edk2-nightly/raw/master/bin/RELEASEX64_OVMF.fd" -O $@

mnt/EFI/BOOT/BOOTx64.EFI: main.efi
	mkdir -p mnt/EFI/BOOT
	cp $< $@

main.s: main.c efi.h
	$(CC) $(CFLAGS) $<

main.o: main.s
	x86_64-w64-mingw32-gcc -c $< -o $@

main.efi: main.o
	lld-link $(LDFLAGS) -entry:efi_main $^ -out:$@

by-clang:
	make main.efi CC=clang CFLAGS="-S -target x86_64-pc-win32-coff -no-integrated-as"

by-azcc: azcc
	make main.efi CC=./azcc/bin/gen1/azcc CFLAGS="--target=x86_64-w64-windows-gnu > main.s"

azcc:
	make -C azcc
