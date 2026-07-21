#@description makefile to automate the various steps of compilation for the videogame
#@author Regy Special
#@date 2026 January 16th Friday, 21:11:03
#@license GNU General Public License to stop private corporation to not share source code

#internal application source code files

#main entry point programms for OS

cConsoleLibrary = src/lib/c/console.c

x86_64-linux-elf-console =   bin/lib/static/c/o/elf/linux/x86_64/console.o
x86_64-windows-pe-console =  bin/lib/static/c/o/pe/windows/x86_64/console.o
x86_64-ios-machO-console =   bin/lib/static/c/o/mach-o/ios/x86_64/console.o
x86_64-macos-machO-console = bin/lib/static/c/o/mach-o/macos/x86_64/console.o

build-x86_64-windows-pe-console:$(cConsoleLibrary)
	$(MinGWc) -c -std=c23 -Wall -O $(cConsoleLibrary) -o $(x86_64-windows-pe-console)
build-x86_64-linux-elf-console:$(cConsoleLibrary)
	gcc -c -std=c23 -Wall -O $(cConsoleLibrary) -o $(x86_64-linux-elf-console)
build-macos-machO-console:$(cConsoleLibrary)
	gcc -c -std=c23 -Wall -O $(cConsoleLibrary) -o $(x86_64-macos-machO-console)

cAudioBeepLibrary = src/lib/c/audio/beep.c

x86_64-linux-elf-audioBeep =   bin/lib/static/c/o/elf/linux/x86_64/beep.o
x86_64-windows-pe-audioBeep =  bin/lib/static/c/o/pe/windows/x86_64/beep.o
x86_64-ios-machO-audioBeep =   bin/lib/static/c/o/mach-o/ios/x86_64/beep.o
x86_64-macos-machO-audioBeep = bin/lib/static/c/o/mach-o/macos/x86_64/beep.o

build-x86_64-windows-pe-audioBeep:$(cAudioBeepLibrary)
	$(MinGWc) -c -std=c23 -Wall -O $(cAudioBeepLibrary) -o $(x86_64-windows-pe-audioBeep)
build-x86_64-linux-elf-audioBeep:$(cAudioBeepLibrary)
	gcc -c -std=c23 -Wall -O $(cAudioBeepLibrary) -o $(x86_64-linux-elf-audioBeep)
build-x86_64-macos-machO-audioBeep:$(cAudioBeepLibrary)
	gcc -c -std=c23 -Wall -O $(cAudioBeepLibrary) -o $(x86_64-macos-machO-audioBeep)

manageArguments=src/main/c/manageArguments.c

x86_64-linux-elf-manageArguments =   bin/lib/static/c/o/elf/linux/x86_64/manageArguments.o
x86_64-windows-pe-manageArguments =  bin/lib/static/c/o/pe/windows/x86_64/manageArguments.o
x86_64-ios-machO-manageArguments =   bin/lib/static/c/o/mach-o/ios/x86_64/manageArguments.o
x86_64-macos-machO-manageArguments = bin/lib/static/c/o/mach-o/macos/x86_64/manageArguments.o

build-x86_64-elf-manageArguments:$(cConsoleLibrary)
	gcc -c -std=c23 -Wall -O $(cConsoleLibrary) -o $(x86_64-linux-elf-console)
build-x86_64-macos-machO-manageArguments:$(cConsoleLibrary)
	gcc -c -std=c23 -Wall -O $(cConsoleLibrary) -o $(x86_64-macos-machO-console)

testManageArguments = test/testManageArguments.cpp

x86_64-linux-elf-testManageArguments =   bin/lib/static/c/o/elf/linux/x86_64/manageArguments
x86_64-windows-pe-testManageArguments =  bin/lib/static/c/o/pe/windows/x86_64/manageArguments
x86_64-ios-machO-testManageArguments =   bin/lib/static/c/o/mach-o/ios/x86_64/manageArguments
x86_64-macos-machO-testManageArguments = bin/lib/static/c/o/mach-o/macos/x86_64/manageArguments

build-x86_64-windows-pe-testManageArguments: $(testManageArguments) $(x86_64-windows-pe-manageArguments)
	$(MinGWc) -std=c++26 -Wall -O $(testManageArguments) $(x86_64-windows-pe-manageArguments) -o $(x86_64-windows-pe-testManageArguments)
build-x86_64-linux-elf-testManageArguments: $(testManageArguments) $(x86_64-linux-elf-manageArguments)
	g++ -std=c++26 -Wall -O $(testManageArguments) $(x86_64-linux-elf-manageArguments) -o $(x86_64-linux-elf-testManageArguments)
build-x86_64-macos-machO-testManageArguments: $(testManageArguments) $(x86_64-macos-machO-manageArguments)
	g++ -std=c++26 -Wall -O $(testManageArguments) $(x86_64-macos-machO-manageArguments) -o $(x86_64-macos-machO-testManageArguments)

goImageLibrary =                src/lib/go/CImage.go
x86_64-linux-elf-imageLibrary = bin/lib/static/go/a/CImage.a

build-x86_64-linux-elf-image-a: $(goImageLibrary)
	GOOS=linux GOARCH=x86_64 go build  -buildmode=c-archive -o $(goImageLibraryArchive) $(goImageLibrary)
	mv bin/lib/static/go/a/CImage.h src/include/lib/go

main =      src/main/c++/main.cpp
appleMain = src/main/swift/main.swift

resourceScript = scripts/build/windows.rc

MinGWc =       C:/MinGW/bin/gcc.exe
MinGWcpp =     C:/MinGW/bin/g++.exe
MinGWwindres = C:/MinGW/bin/windres.exe

#binary object files
x86_64-windowsResources = bin/exec/pe/windows/x86_64/windows.res

#object files
macos-machO = bin/exec/macos/mach-o/x86_64/RegySpecial
ios-machO =   bin/exec/ios/mach-o/x86_64/RegySpecial

#executable files (final results)
x86_64-windows-pe = bin/exec/pe/windows/x86_64/RegySpecial.exe
x86_64-linux-elf =  bin/exec/elf/linux/x86_64/RegySpecial

arm-windows-pe =  bin/exec/pe/windows/arm/RegySpecial.exe
arm-linux-elf =   bin/exec/elf/linux/arm/RegySpecial
arm-macos-machO = bin/exec/mach-o/macos/arm/RegySpecial
arm-ios-machO =   bin/exec/mach-o/macos/arm/RegySpecial

riscv-windows-pe =  bin/exec/pe/windows/riscv/RegySpecial.exe
riscv-linux-elf =   bin/exec/elf/linux/riscv/RegySpecial
riscv-macos-machO = bin/exec/riscv/mach-o/macos/RegySpecial

build-image-a: $(goImageLibrary)
	go build -buildmode=c-archive -o $(goImageLibraryArchive) $(goImageLibrary)
	mv bin/lib/static/go/a/CImage.h src/include/lib/go

build-docker-image:
	docker build scripts/build -t docker-armory

build-windows-res: $(resourceScript)
	$(MinGWwindres) $(resourceScript) -O coff -o $(windowsResources)

build-x86_64-pe: $(mainFile) $(windowsResources) $(consoleLibrary)
	$(MinGWcpp) -std=c++26 -O $(mainFile) $(windowsResources) $(consoleLibrary) -o $(x86_64-pe) -lwinmm -lgdiplus -lgdi32 -lodbc32

debug-x86_64-pe: $(mainFile) $(windowsResources) $(consoleLibrary)
	$(MinGWcpp) -std=c++26 -g $(mainFile) $(windowsResources) $(consoleLibrary) -o $(x86_64-pe) -lwinmm -lgdiplus -lgdi32 -lodbc32

sanitize-x86_64-pe: $(mainFile) $(windowsResources) $(consoleLibrary)
	$(MinGWcpp) -std=c++26 -g -fsanitize $(mainFile) $(windowsResources) $(consoleLibrary) -o $(x86_64-pe) -lwinmm -lgdiplus -lgdi32 -lodbc32

build-x86_64-linux-elf:$(x86_64-linux-elf-audioBeep) $(x86_64-linux-elf-console) $(mainFile) $(cppBitManipulationLibrary) $(goImageLibraryArchive)
	g++ -std=c++26 -Wall -O \
	$(x86_64-linux-elf-console) \
	$(mainFile) \
	$(bitManipulationLibrary) \
	$(goImageLibraryArchive) \
	$(beepLibrary) \
	-o $(x86_64-elf) \
	-lX11 -lodbc -lGL

debug-x86_64-linux-elf:$(x86_64-linux-elf-audioBeep) $(x86_64-linux-elf-console) $(mainFile) $(cppBitManipulationLibrary) $(goImageLibraryArchive)
	g++ -std=c++26 -Wall -g \
	$(x86_64-linux-elf-console) \
	$(mainFile) \
	$(bitManipulationLibrary) \
	$(goImageLibraryArchive) \
	$(beepLibrary) \
	-o $(x86_64-elf) \
	-lX11 -lodbc -lGL

sanitize-x86_64-linux-elf:$(x86_64-linux-elf-audioBeep) $(x86_64-linux-elf-console) $(mainFile) $(cppBitManipulationLibrary) $(goImageLibraryArchive)
	g++ -std=c++26 -Wall -g -fsanitize=address \
	$(x86_64-linux-elf-console) \
	$(mainFile) \
	$(bitManipulationLibrary) \
	$(goImageLibraryArchive) \
	$(beepLibrary) \
	-o $(x86_64-elf) \
	-lX11 -lodbc -lGL
build-x86_64-linux-elf-save-temps: 
	g++ -std=c++26 -Wall -O \
	$(x86_64-linux-elf-console) \
	$(mainFile) \
	$(bitManipulationLibrary) \
	$(goImageLibraryArchive) \
	$(beepLibrary) \
	-o $(x86_64-elf) \
	-lX11 -lodbc -lGL -save-temps

debug-x86_64-linux-elf-save-temps:$(x86_64-linux-elf-audioBeep) $(x86_64-linux-elf-console) $(mainFile) $(cppBitManipulationLibrary) $(goImageLibraryArchive)
	g++ -std=c++26 -Wall -g \
	$(x86_64-linux-elf-console) \
	$(mainFile) \
	$(bitManipulationLibrary) \
	$(goImageLibraryArchive) \
	$(beepLibrary) \
	-o $(x86_64-elf) \
	-lX11 -lodbc -lGL -save-temps

sanitize-x86_64-linux-elf-save-temps:$(x86_64-linux-elf-audioBeep) $(x86_64-linux-elf-console) $(mainFile) $(cppBitManipulationLibrary) $(goImageLibraryArchive)
	g++ -std=c++26 -Wall -g \
	$(x86_64-linux-elf-console) \
	$(mainFile) \
	$(bitManipulationLibrary) \
	$(goImageLibraryArchive) \
	$(beepLibrary) \
	-o $(x86_64-elf) \
	-lX11 -lodbc -lGL -save-temps

#compile for Kernel Mach
build-macos-machO:$(macos-mainFile)
	swiftc -O -arch x86_64 -arch arm $(macos-mainFile) -o $(x86_64-mach-o) -framework Cocoa -framework AppKit
debug-macos-machO:$(macos-mainFile)
	swiftc -g  -arch x86_64 -arch arm $(macos-mainFile) -o $(x86_64-mach-o)-debug -framework Cocoa -framework AppKit
sanitize-machO-machO:$(macos-mainFile)
	swiftc -g -sanitize=address $(macos-mainFile) -o $(x86_64-mach-o)-sanitize -framework Cocoa -framework AppKit

clean:
	rm -r bin/lib/static/c/audio
	rm -r bin/main/c/manageArguments.o

all:
	build-x86_64-elf-console \
	build-macos-machO-console \
	build-x86_64-elf-audioBeep \
	build-x86_64-macos-machO-audioBeep \
	build-x86_64-elf-manageArguments \
	build-x86_64-macos-machO-manageArguments \
	build-x86_64-linux-elf-testManageArguments \
	build-image-a \
	build-docker-image \
	build-windows-res \
	build-x86_64-pe \
	debug-x86_64-pe \
	sanitize-x86_64-pe \
	build-x86_64-linux-elf \
	debug-x86_64-linux-elf \
	sanitize-x86_64-linux-elf \
	build-x86_64-elf-save-temps \
	debug-x86_64-elf-save-temps \
	sanitize-x86_64-elf-save-temps \
	build-macOS-mach-o \
	debug-macos-machO \
	sanitize-mach-o \
	clean

.PHONY:
	build-x86_64-elf-console \
	build-macos-machO-console \
	build-x86_64-elf-audioBeep \
	build-x86_64-macos-machO-audioBeep \
	build-x86_64-elf-manageArguments \
	build-x86_64-macos-machO-manageArguments \
	build-x86_64-linux-elf-testManageArguments \
	build-image-a \
	build-docker-image \
	build-windows-res \
	build-x86_64-pe \
	debug-x86_64-pe \
	sanitize-x86_64-pe \
	build-x86_64-linux-elf \
	debug-x86_64-linux-elf \
	sanitize-x86_64-linux-elf \
	build-x86_64-elf-save-temps \
	debug-x86_64-elf-save-temps \
	sanitize-x86_64-elf-save-temps \
	build-macOS-mach-o \
	debug-macos-machO \
	sanitize-mach-o \
	clean \
	all