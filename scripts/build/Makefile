#@description makefile to automate the various steps of compilation for the videogame
#@author Regy Special
#@date 2026 January 16th Friday, 21:11:03
#@license GNU General Public License to stop private corporation to not share source code

MinGWc =       C:/MinGW/bin/gcc.exe
MinGWcpp =     C:/MinGW/bin/g++.exe
MinGWwindres = C:/MinGW/bin/windres.exe

cConsoleLibrary = src/lib/c/console.c
cAudioBeepLibrary = src/lib/c/audio/beep.c
manageArguments =   src/main/c/manageArguments.c

x86_64-ios-machO-cConsoleLibrary =    bin/lib/static/c/o/mach-o/ios/x86_64/console.o
x86_64-macos-machO-cConsoleLibrary =  bin/lib/static/c/o/mach-o/macos/x86_64/console.o
aarch64-ios-machO-cConsoleLibrary =   bin/lib/static/c/o/mach-o/ios/aarch64/console.o
aarch64-macos-machO-cConsoleLibrary = bin/lib/static/c/o/mach-o/macos/aarch64/console.o

build-x86_64-ios-machO-cConsoleLibrary: $(cConsoleLibrary)
	gcc -std=c23 -Wall -O -c $(cConsoleLibrary) -o $(x86_64-ios-machO-cConsoleLibrary)
build-x86_64-macos-machO-cConsoleLibrary: $(cConsoleLibrary)
	gcc -std=c23 -Wall -O -c $(cConsoleLibrary) -o $(x86_64-macos-machO-cConsoleLibrary)
build-aarch64-ios-machO-cConsoleLibrary: $(cConsoleLibrary)
	gcc -std=c23 -Wall -O -c $(cConsoleLibrary) -o $(x86_64-ios-machO-cConsoleLibrary)
build-aarch64-macos-machO-cConsoleLibrary: $(cConsoleLibrary)
	gcc -std=c23 -Wall -O -c $(cConsoleLibrary) -o $(x86_64-macos-machO-cConsoleLibrary)

x86_64-ios-machO-cAudioBeepLibrary =    bin/lib/static/c/o/mach-o/ios/x86_64/cAudioBeepLibrary.o
x86_64-macos-machO-cAudioBeepLibrary =  bin/lib/static/c/o/mach-o/macos/x86_64/cAudioBeepLibrary.o
aarch64-ios-machO-cAudioBeepLibrary =   bin/lib/static/c/o/mach-o/ios/aarch64/cAudioBeepLibrary.o
aarch64-macos-machO-cAudioBeepLibrary = bin/lib/static/c/o/mach-o/macos/aarch64/cAudioBeepLibrary.o

build-x86_64-ios-machO-cAudioBeepLibrary: $(cAudioBeepLibrary)
	gcc -std=c23 -Wall -O -c $(cAudioBeepLibrary) -o $(x86_64-ios-machO-cAudioBeepLibrary)
build-x86_64-macos-machO-cAudioBeepLibrary: $(cAudioBeepLibrary)
	gcc -std=c23 -Wall -O -c $(cAudioBeepLibrary) -o $(x86_64-macos-machO-cAudioBeepLibrary)
build-aarch64-ios-machO-cAudioBeepLibrary: $(cAudioBeepLibrary)
	gcc -std=c23 -Wall -O -c $(cAudioBeepLibrary) -o $(x86_64-ios-machO-cAudioBeepLibrary)
build-aarch64-macos-machO-cAudioBeepLibrary: $(cAudioBeepLibrary)
	gcc -std=c23 -Wall -O -c $(cAudioBeepLibrary) -o $(x86_64-macos-machO-cAudioBeepLibrary)

testManageArguments = test/testManageArguments.cpp

x86_64-linux-elf-testManageArguments =     /home/regyspecial/Scrivania/testManageArguments
x86_64-linux-freebsd-testManageArguments = /home/regyspecial/Scrivania/testManageArguments
x86_64-windows-pe-testManageArguments =    /home/regyspecial/Scrivania/testManageArguments
x86_64-ios-machO-testManageArguments =     /home/regyspecial/Scrivania/testManageArguments
x86_64-macos-machO-testManageArguments =   /home/regyspecial/Scrivania/testManageArguments

build-x86_64-windows-pe-testManageArguments: $(manageArguments) $(cConsoleLibrary) $(testManageArguments)
	$(MinGWcpp) -std=c++26 -Wall -O $(manageArguments) $(cConsoleLibrary) $(testManageArguments) -o $(x86_64-windows-pe-testManageArguments)
build-x86_64-linux-elf-testManageArguments: $(manageArguments) $(cConsoleLibrary) $(testManageArguments)
	g++ -std=c++26 -Wall -O $(manageArguments) $(cConsoleLibrary) $(testManageArguments) -o $(x86_64-linux-elf-testManageArguments)
build-x86_64-freebsd-elf-testManageArguments: $(manageArguments) $(cConsoleLibrary) $(testManageArguments)
	c++ -std=c++26 -Wall -O $(manageArguments) $(cConsoleLibrary) $(testManageArguments) -o $(x86_64-freebsd-elf-testManageArguments)
build-x86_64-macos-machO-testManageArguments: $(testManageArguments) $(x86_64-macos-machO-manageArguments)
	g++ -std=c++26 -Wall -O $(testManageArguments) $(x86_64-macos-machO-manageArguments) -o $(x86_64-macos-machO-testManageArguments)

goImageLibrary =                  src/lib/go/CImage.go

x86_64-linux-elf-imageLibrary =   bin/lib/static/go/a/elf/linux/x86_64/CImage.a
x86_64-freebsd-elf-imageLibrary = bin/lib/static/go/a/elf/freebsd/amd64/CImage.a
arm-linux-elf-imageLibrary =      bin/lib/static/go/a/elf/linux/arm/CImage.a
arm-freebsd-elf-imageLibrary =    bin/lib/static/go/a/elf/freebsd/arm7/CImage.a

build-x86_64-linux-elf-image-a: $(goImageLibrary)
	GOOS=linux GOARCH=x86_64 go build  -buildmode=c-archive -o $(goImageLibraryArchive) $(goImageLibrary)
	mv bin/lib/static/go/a/linux/elf/x86_64/CImage.h src/include/lib/go
build-x86_64-freebsd-elf-image-a: $(goImageLibrary)
	GOOS=freebsd GOARCH=x86_64 go build  -buildmode=c-archive -o $(goImageLibraryArchive) $(goImageLibrary)
	mv bin/lib/static/go/a/freebsd/elf/x86_64/CImage.h src/include/lib/go
build-arm-linux-elf-image-a: $(goImageLibrary)
	GOOS=linux GOARCH=arm go build  -buildmode=c-archive -o $(goImageLibraryArchive) $(goImageLibrary)
	mv bin/lib/static/go/a/linux/elf/x86_64/CImage.h src/include/lib/go
build-arm-freebsd-elf-image-a: $(goImageLibrary)
	GOOS=freebsd GOARCH=arm go build  -buildmode=c-archive -o $(goImageLibraryArchive) $(goImageLibrary)
	mv bin/lib/static/go/a/linux/elf/x86_64/CImage.h src/include/lib/go

mainWindow =        src/main/c++/mainWindow.cpp
mainScreenButtons = src/main/c++/mainScreenButtons.cpp
mainDialogs =       src/main/c++/mainDialogs.cpp
gameModeButtons =   src/main/c++/gameModeButtons.cpp
form =              src/main/c++/form.cpp
formTextBox =       src/main/c++/formTextBox.cpp

apple-mainWindow =        src/main/swift/mainWindow.swift
apple-mainScreenButtons = src/main/swift/mainScreenButtons.swift
apple-mainDialogs =       src/main/swift/mainDialogs.swift
apple-gameModeButtons =   src/main/swift/gameModeButtons.swift
apple-form =              src/main/swift/form.swift
apple-formTextBox =       src/main/swift/formTextBox.swift

build-x86_64-windows-pe-testVideoGame: $(mainWindow) $(mainScreenButtons) $(mainDialogs) $(gameModeButtons) $(form) $(formTextBox)
	$(MinGWcpp) -std=c++26 -Wall -O $(mainWindow) $(mainScreenButtons) $(mainDialogs) $(gameModeButtons) $(form) $(formTextBox) -o $(x86_64-windows-pe-testManageArguments)
build-x86_64-linux-elf-testManageArguments: $(mainWindow) $(mainScreenButtons) $(mainDialogs) $(gameModeButtons) $(form) $(formTextBox)
	g++ -std=c++26 -Wall -O $(manageArguments) $(cConsoleLibrary) $(testManageArguments) -o $(x86_64-linux-elf-testManageArguments)
build-x86_64-freebsd-elf-testManageArguments: $(mainWindow) $(mainScreenButtons) $(mainDialogs) $(gameModeButtons) $(form) $(formTextBox)
	c++ -std=c++26 -Wall -O $(manageArguments) $(cConsoleLibrary) $(testManageArguments) -o $(x86_64-freebsd-elf-testManageArguments)
build-x86_64-macos-machO-testManageArguments: $(mainWindow) $(mainScreenButtons) $(mainDialogs) $(gameModeButtons) $(form) $(formTextBox)
	g++ -std=c++26 -Wall -O $(testManageArguments) $(x86_64-macos-machO-manageArguments) -o $(x86_64-macos-machO-testManageArguments)

main =       src/main/c++/main.cpp
apple-main = src/main/swift/main.swift

resourceScript = scripts/build/windows.rc

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

build-x86_64-windows-pe: $(mainFile) $(windowsResources) $(consoleLibrary)
	$(MinGWcpp) -std=c++26 -O $(mainFile) $(windowsResources) $(consoleLibrary) -o $(x86_64-pe) -lwinmm -lgdiplus -lgdi32 -lodbc32

debug-x86_64-windows-pe: $(mainFile) $(windowsResources) $(consoleLibrary)
	$(MinGWcpp) -std=c++26 -g $(mainFile) $(windowsResources) $(consoleLibrary) -o $(x86_64-pe) -lwinmm -lgdiplus -lgdi32 -lodbc32

sanitize-x86_64-windows-pe: $(mainFile) $(windowsResources) $(consoleLibrary)
	$(MinGWcpp) -std=c++26 -g -fsanitize $(mainFile) $(windowsResources) $(consoleLibrary) -o $(x86_64-pe) -lwinmm -lgdiplus -lgdi32 -lodbc32

build-x86_64-windows-pe-save-temps: $(mainFile) $(windowsResources) $(consoleLibrary)
	$(MinGWcpp) -std=c++26 -O $(mainFile) $(windowsResources) $(consoleLibrary) -o $(x86_64-pe) -lwinmm -lgdiplus -lgdi32 -lodbc32

debug-x86_64-windows-pe-save-temps: $(mainFile) $(windowsResources) $(consoleLibrary)
	$(MinGWcpp) -std=c++26 -g $(mainFile) $(windowsResources) $(consoleLibrary) -o $(x86_64-pe) -lwinmm -lgdiplus -lgdi32 -lodbc32

sanitize-x86_64-windows-pe-save-temps: $(mainFile) $(windowsResources) $(consoleLibrary)
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
build-x86_64-macos-machO:$(macos-mainFile)
	swiftc -O -target x86_64-apple-macosx10.15 $(macos-mainFile) -o $(x86_64-mach-o) -framework Cocoa -framework AppKit
debug-x86_64-macos-machO:$(macos-mainFile)
	swiftc -g -target x86_64-apple-macosx10.15 $(macos-mainFile) -o $(x86_64-mach-o)-debug -framework Cocoa -framework AppKit
sanitize-x86_64-macos-machO:$(macos-mainFile)
	swiftc -g -target x86_64-apple-macosx10.15 -sanitize=address $(macos-mainFile) -o $(x86_64-mach-o)-sanitize -framework Cocoa -framework AppKit
build-arm64-macos-machO:$(macos-mainFile)
	swiftc -O -target arm64-apple-macosx10.15 $(macos-mainFile) -o $(x86_64-mach-o) -framework Cocoa -framework AppKit
debug-arm64-macos-machO:$(macos-mainFile)
	swiftc -g -target arm64-apple-macosx10.15 $(macos-mainFile) -o $(x86_64-mach-o)-debug -framework Cocoa -framework AppKit
sanitize-arm64-macos-machO:$(macos-mainFile)
	swiftc -g -target arm64-apple-macosx10.15 -sanitize=address $(macos-mainFile) -o $(x86_64-mach-o)-sanitize -framework Cocoa -framework AppKit


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
