#makefile to automate the various steps of compilation for the videogame
#@author Regy Special
#@date 2026 January 16th Friday, 21:11:03
#@license GNU General Public License to stop private corporation to not share source code

#internal application source code files

#main entry point programms for OS
manageArguments=src/main/c/manageArguments.c
main=src/main/c++/main.cpp
appleMain=src/main/swift/appleMain.swift

#Windows resources script
resourceScript=scripts/build/windows.rc

#MinGW compilers
MinGWcpp=C:/MinGW/bin/g++.exe
MinGWwindres=C:/MinGW/bin/windres.exe

#libraries source code

#c++ custom libraries
cppBitManipulationLibrary=src/lib/c++/bitManipulation.cpp
cppArraysLibrary=src/lib/c++/DSA/Algorithms/arrays.cpp

#go custom libraries
goImageLibrary=src/lib/go/CImage.go

#c custom libraries
cConsoleLibrary=src/lib/c/console.c
cAudioBeepLibrary=src/lib/c/audio/beep.c

#library files
goImageLibraryArchive=bin/lib/static/go/a/CImage.a

#binary object files
x86_64-windowsResources=bin/exec/pe/windows/x86_64/windows.res

#object files
x86_64-linux-elf-audioBeep=bin/lib/static/c/o/elf/linux/x86_64/beep.o
x86_64-pe-windows-audioBeep=bin/exec/pe/windows/x86_64/beep.o
x86_64-ios-machO-audioBeep=bin/exec/mach-o/ios/x86_64/beep.o
x86_64-macos-machO-audioBeep=bin/exec/mach-o/macos/x86_64/beep.o

x86_64-linux-elf-console=bin/lib/static/c/o/elf/linux/x86_64/console.o
x86_64-pe-windows-console=bin/exec/pe/windows/x86_64/console.o
x86_64-ios-machO-console=bin/exec/mach-o/ios/x86_64/console.o
x86_64-macos-machO-console=bin/exec/mach-o/macos/x86_64/console.o

x86_64-linux-elf-manageArguments=bin/lib/static/c/o/elf/linux/x86_64/beep.o
x86_64-pe-windows-manageArguments=bin/exec/pe/windows/x86_64/beep.o
x86_64-ios-machO-manageArguments=bin/exec/mach-o/ios/x86_64/beep.o
x86_64-macos-machO-manageArguments=bin/exec/mach-o/macos/x86_64/beep.o

#executable files (final results)
x86_64-pe=bin/exec/pe/windows/x86_64/RegySpecial.exe
x86_64-elf=bin/exec/elf/linux/x86_64/RegySpecial
x86_64-mach-o=bin/exec/x86_64/mach-o/macos/RegySpecial

arm-pe=bin/exec/pe/windows/arm/RegySpecial.exe
arm-elf=bin/exec/elf/linux/arm/RegySpecial
arm-mach-o=bin/exec/arm/mach-o/macos/RegySpecial

riscv-pe=bin/exec/pe/windows/riscv/RegySpecial.exe
riscv-elf=bin/exec/elf/linux/riscv/RegySpecial
riscv-mach-o=bin/exec/riscv/mach-o/macos/RegySpecial

build-docker-image:
	docker build scripts/build -t docker-armory

build-x86_64-elf-console-o:$(cConsoleLibrary)
	gcc -c -std=c23 -Wall -O $(cConsoleLibrary) -o $(x86_64-linux-elf-console)
build-x86_64-elf-audioBeep-o:$(cAudioBeepLibrary)
	gcc -c -std=c23 -Wall -O $(cAudioBeepLibrary) -o $(x86_64-linux-elf-audioBeep)

build-image-a: $(goImageLibrary)
	go build  -buildmode=c-archive -o $(goImageLibraryArchive) $(goImageLibrary)
	mv bin/lib/static/go/a/CImage.h src/include/lib/go

build-windows-res: $(resourceScript)
	$(MinGWwindres) $(resourceScript) -O coff -o $(windowsResources)

build-x86_64-pe: $(mainFile) $(windowsResources) $(consoleLibrary)
	$(MinGWcpp) -std=c++26 -O $(mainFile) $(windowsResources) $(consoleLibrary) -o $(x86_64-pe) -lwinmm -lgdiplus -lgdi32 -lodbc32

debug-x86_64-pe: $(mainFile) $(windowsResources) $(consoleLibrary)
	$(MinGWcpp) -std=c++26 -g $(mainFile) $(windowsResources) $(consoleLibrary) -o $(x86_64-pe) -lwinmm -lgdiplus -lgdi32 -lodbc32

sanitize-x86_64-pe: $(mainFile) $(windowsResources) $(consoleLibrary)
	$(MinGWcpp) -std=c++26 -g -fsanitize $(mainFile) $(windowsResources) $(consoleLibrary) -o $(x86_64-pe) -lwinmm -lgdiplus -lgdi32 -lodbc32

build-x86_64-elf:$(x86_64-linux-elf-audioBeep) $(x86_64-linux-elf-console) $(mainFile) $(cppBitManipulationLibrary) $(goImageLibraryArchive)
	g++ -std=c++26 -Wall -O \
	  $(x86_64-linux-elf-console) \
	  $(mainFile) \
	  $(bitManipulationLibrary) \
	  $(goImageLibraryArchive) \
	  $(beepLibrary) \
	  -o $(x86_64-elf) \
	  -lX11 -lodbc -lGL

debug-x86_64-elf:$(x86_64-linux-elf-audioBeep) $(x86_64-linux-elf-console) $(mainFile) $(cppBitManipulationLibrary) $(goImageLibraryArchive)
	g++ -std=c++26 -Wall -g \
	  $(x86_64-linux-elf-console) \
	  $(mainFile) \
	  $(bitManipulationLibrary) \
	  $(goImageLibraryArchive) \
	  $(beepLibrary) \
	  -o $(x86_64-elf) \
	  -lX11 -lodbc -lGL

sanitize-x86_64-elf:$(x86_64-linux-elf-audioBeep) $(x86_64-linux-elf-console) $(mainFile) $(cppBitManipulationLibrary) $(goImageLibraryArchive)
	g++ -std=c++26 -Wall -g \
	  $(x86_64-linux-elf-console) \
	  $(mainFile) \
	  $(bitManipulationLibrary) \
	  $(goImageLibraryArchive) \
	  $(beepLibrary) \
	  -o $(x86_64-elf) \
	  -lX11 -lodbc -lGL

build-x86_64-elf:$(x86_64-linux-elf-audioBeep) $(x86_64-linux-elf-console) $(mainFile) $(cppBitManipulationLibrary) $(goImageLibraryArchive)
	g++ -std=c++26 -Wall -O \
	  $(x86_64-linux-elf-console) \
	  $(mainFile) \
	  $(bitManipulationLibrary) \
	  $(goImageLibraryArchive) \
	  $(beepLibrary) \
	  -o $(x86_64-elf) \
	  -lX11 -lodbc -lGL -save-temps
debug-x86_64-elf:$(x86_64-linux-elf-audioBeep) $(x86_64-linux-elf-console) $(mainFile) $(cppBitManipulationLibrary) $(goImageLibraryArchive)
	g++ -std=c++26 -Wall -g \
	  $(x86_64-linux-elf-console) \
	  $(mainFile) \
	  $(bitManipulationLibrary) \
	  $(goImageLibraryArchive) \
	  $(beepLibrary) \
	  -o $(x86_64-elf) \
	  -lX11 -lodbc -lGL -save-temps
sanitize-x86_64-elf:$(x86_64-linux-elf-audioBeep) $(x86_64-linux-elf-console) $(mainFile) $(cppBitManipulationLibrary) $(goImageLibraryArchive)
	g++ -std=c++26 -Wall -g \
	  $(x86_64-linux-elf-console) \
	  $(mainFile) \
	  $(bitManipulationLibrary) \
	  $(goImageLibraryArchive) \
	  $(beepLibrary) \
	  -o $(x86_64-elf) \
	  -lX11 -lodbc -lGL -save-temps

#compile for Kernel Mach
build-mach-o:$(macos-mainFile)
	swiftc -O -arch x86_64 -arch arm $(macos-mainFile) -o $(x86_64-mach-o) -framework Cocoa -framework AppKit
debug-x86_64-mach-o:$(macos-mainFile)
	swiftc -g -sanitize=address $(macos-mainFile) -o $(x86_64-mach-o)-debug -framework Cocoa -framework AppKit
sanitize-x86_64-mach-o:$(macos-mainFile)
	swiftc -g $(macos-mainFile) -o $(x86_64-mach-o)-sanitize -framework Cocoa -framework AppKit

clean:
	rm -r bin/lib/static/c/audio
	rm -r bin/main/c/manageArguments.o

all:
	build-x86_64-elf-console-o \
	build-image-a build-x86_64-elf \
	debug-x86_64-elf \
	sanitize-x86_64-elf \
	build-x86_64-mach-o \
	debug-x86_64-mach-o \
	sanitize-x86_64-mach-o \
	clean

.PHONY:
	all \
	build-x86_64-elf-console-o \
	build-image-a build-x86_64-elf \
	debug-x86_64-elf \
	sanitize-x86_64-elf \
	build-x86_64-mach-o \
	debug-x86_64-mach-o \
	sanitize-x86_64-mach-o \
	clean