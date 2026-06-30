#makefile to automate the various steps of compilation for the videogame
#@author Regy Special
#@date 2026 January 16th Friday, 21:11:03
#@license GNU General Public License to stop private corporation to not share source code

#internal application source code files

#main entry point programms for OS
windows-unix-mainFile=windows-unix/src/main/RegySpecial.cpp
macos-mainFile=apple/src/main/RegySpecial.swift

#Windows resources script
resourceScript=windows-unix/src/res/Windows.rc

#MinGW compilers
MinGWcpp=C:/MinGW/bin/g++.exe
MinGWwindres=C:/MinGW/bin/windres.exe

#libraries source code
bitManipulationLibrary=windows-unix/lib/C++/bitManipulation.cpp
arraysLibrary=windows-unix/lib/C++/DSA/Algorithms/arrays.cpp
lib-cgo-image=windows-unix/lib/CGO/CImage.go
consoleLibrary=windows-unix/lib/C/console.c
beepLibrary=windows-unix/lib/C/audio/beep.c
#library files
lib-bin-cgo-image-a=windows-unix/lib/bin/static/CGO/CImage.a

#binary object files
windowsResources=windows-unix/Windows/src/res/Windows.res

#executable files (final results)
x86_64-elf-obj=windows-unix/bin/elf/linux/x86_64/beep.o
x86_64-pe=windows-unix/bin/pe/windows/x86_64/RegySpecial.exe
x86_64-elf=windows-unix/bin/elf/linux/x86_64/RegySpecial
x86_64-mach-o=apple/bin/x86_64/mach-o/macos/RegySpecial
arm-pe=windows-unix/bin/pe/windows/arm/RegySpecial.exe
arm-elf=windows-unix/bin/elf/linux/arm/RegySpecial
arm-mach-o=apple/bin/arm/mach-o/macos/RegySpecial
riscv-pe=windows-unix/bin/pe/windows/riscv/RegySpecial.exe
riscv-elf=windows-unix/bin/elf/linux/riscv/RegySpecial
riscv-mach-o=apple/bin/riscv/mach-o/macos/RegySpecial

#compile for Windows and Windows-like
build-windows-res: $(resourceScript)
	$(MinGWwindres) $(resourceScript) -O coff -o $(windowsResources)
build-x86_64-pe: $(windows-unix-mainFile) $(windowsResources) $(consoleLibrary)
	$(MinGWcpp) -std=c++26 -O $(windows-unix-mainFile) $(windowsResources) $(consoleLibrary) -o $(x86_64-pe) -lwinmm -lgdiplus -lgdi32 -lodbc32
debug-x86_64-pe: $(windows-unix-mainFile) $(windowsResources) $(consoleLibrary)
	$(MinGWcpp) -std=c++26 -g $(windows-unix-mainFile) $(windowsResources) $(consoleLibrary) -o $(x86_64-pe) -lwinmm -lgdiplus -lgdi32 -lodbc32
sanitize-x86_64-pe: $(windows-unix-mainFile) $(windowsResources) $(consoleLibrary)
	$(MinGWcpp) -std=c++26 -g -fsanitize $(windows-unix-mainFile) $(windowsResources) $(consoleLibrary) -o $(x86_64-pe) -lwinmm -lgdiplus -lgdi32 -lodbc32

#compile for Unix/Unix-like
build-docker-image:
	docker build scripts/build -t docker-armory
build-image-a: $(lib-cgo-image)
	go build  -buildmode=c-archive -o $(lib-bin-cgo-image-a) $(lib-cgo-image)
	mv windows-unix/lib/bin/static/CGO/CImage.h windows-unix/include/CGO

build-x86_64-elf:$(consoleLibrary) $(windows-unix-mainFile) $(bitManipulationLibrary) $(lib-bin-cgo-image-a) $(beepLibrary)
    gcc -c -std=c23 -Wall -O $(beepLibrary) -o $(beepLibrary) \
	g++ -std=c++26 -Wall -O $(consoleLibrary) $(windows-unix-mainFile) $(bitManipulationLibrary) $(lib-bin-cgo-image-a) $(beepLibrary) -o $(x86_64-elf) -lX11 -lodbc -lGL
debug-x86_64-elf:$(consoleLibrary) $(windows-unix-mainFile) $(bitManipulationLibrary) $(lib-bin-cgo-image-a)
	g++ -std=c++26 -Wall -g $(consoleLibrary) $(windows-unix-mainFile) $(bitManipulationLibrary) $(lib-bin-cgo-image-a) $(beepLibrary) -o $(x86_64-elf)-debug -lX11 -lodbc -lGL
sanitize-x86_64-elf:$(consoleLibrary) $(windows-unix-mainFile) $(bitManipulationLibrary) $(lib-bin-cgo-image-a)
	g++ -std=c++26 -Wall -g -fsanitize=address $(consoleLibrary) $(windows-unix-mainFile) $(bitManipulationLibrary) $(lib-bin-cgo-image-a) $(beepLibrary) -o $(x86_64-elf)-sanitize -lX11 -lGL -lodbc

build-x86_64-elf-save-temps:$(consoleLibrary) $(windows-unix-mainFile) $(bitManipulationLibrary) $(lib-bin-cgo-image-a) $(beepLibrary)
	g++ -std=c++26 -Wall -O $(consoleLibrary) $(windows-unix-mainFile) $(bitManipulationLibrary) $(lib-bin-cgo-image-a) $(beepLibrary) -o $(x86_64-elf) -lX11 -lodbc -lGL -save-temps
debug-x86_64-elf-save-temps:$(consoleLibrary) $(windows-unix-mainFile) $(bitManipulationLibrary) $(lib-bin-cgo-image-a) $(beepLibrary)
	g++ -std=c++26 -Wall -g $(consoleLibrary) $(windows-unix-mainFile) $(bitManipulationLibrary) $(lib-bin-cgo-image-a) $(beepLibrary) -o $(x86_64-elf)-debug -lX11 -lodbc -lGL -save-temps
sanitize-x86_64-elf-save-temps:$(consoleLibrary) $(windows-unix-mainFile) $(bitManipulationLibrary) $(lib-bin-cgo-image-a) $(beepLibrary)
	g++ -std=c++26 -Wall -g -fsanitize=address $(consoleLibrary) $(windows-unix-mainFile) $(bitManipulationLibrary) $(lib-bin-cgo-image-a) $(beepLibrary) -o $(x86_64-elf)-sanitize -lX11 -lGL -lodbc -save-temps

#compile for Kernel Mach
build-x86_64-mach-o:$(macos-mainFile)
	swiftc -O $(macos-mainFile) -o $(x86_64-mach-o) -framework Cocoa -framework AppKit
debug-x86_64-mach-o:$(macos-mainFile)
	swiftc -g -sanitize=address $(macos-mainFile) -o $(x86_64-mach-o)-debug -framework Cocoa -framework AppKit
sanitize-x86_64-mach-o:$(macos-mainFile)
	swiftc -g $(macos-mainFile) -o $(x86_64-mach-o)-sanitize -framework Cocoa -framework AppKit

.PHONY: build-x86_64-elf-console-o build-image-a build-x86_64-elf debug-x86_64-elf sanitize-x86_64-elf build-x86_64-mach-o debug-x86_64-mach-o sanitize-x86_64-mach-o