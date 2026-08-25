#@description makefile to automate the various steps of compilation for the videogame
#@author Regy Special
#@date 2026 January 16th Friday, 21:11:03
#@license GNU General Public License to stop private corporation to not share source code

MinGWc =       C:/MinGW/bin/gcc.exe
MinGWcpp =     C:/MinGW/bin/g++.exe
MinGWwindres = C:/MinGW/bin/windres.exe

cConsoleLibrary = src/lib/c/console.c

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

cAudioBeepLibrary = src/lib/c/audio/beep.c

x86_64-ios-machO-cAudioBeepLibrary =    bin/lib/static/c/o/mach-o/ios/x86_64/audioBeepLibrary.o
x86_64-macos-machO-cAudioBeepLibrary =  bin/lib/static/c/o/mach-o/macos/x86_64/audioBeepLibrary.o
aarch64-ios-machO-cAudioBeepLibrary =   bin/lib/static/c/o/mach-o/ios/aarch64/audioBeepLibrary.o
aarch64-macos-machO-cAudioBeepLibrary = bin/lib/static/c/o/mach-o/macos/aarch64/audioBeepLibrary.o

build-x86_64-ios-machO-cAudioBeepLibrary: $(cAudioBeepLibrary)
	gcc -std=c23 -Wall -O -c $(cAudioBeepLibrary) -o $(x86_64-ios-machO-cAudioBeepLibrary)
build-x86_64-macos-machO-cAudioBeepLibrary: $(cAudioBeepLibrary)
	gcc -std=c23 -Wall -O -c $(cAudioBeepLibrary) -o $(x86_64-macos-machO-cAudioBeepLibrary)
build-aarch64-ios-machO-cAudioBeepLibrary: $(cAudioBeepLibrary)
	gcc -std=c23 -Wall -O -c $(cAudioBeepLibrary) -o $(x86_64-ios-machO-cAudioBeepLibrary)
build-aarch64-macos-machO-cAudioBeepLibrary: $(cAudioBeepLibrary)
	gcc -std=c23 -Wall -O -c $(cAudioBeepLibrary) -o $(x86_64-macos-machO-cAudioBeepLibrary)

cManageArguments =   src/main/c/manageArguments.c

x86_64-ios-machO-cManageArguments =    bin/lib/static/c/o/mach-o/ios/x86_64/manageArguments.o
x86_64-macos-machO-cManageArguments =  bin/lib/static/c/o/mach-o/macos/x86_64/manageArguments.o
aarch64-ios-machO-cManageArguments =   bin/lib/static/c/o/mach-o/ios/aarch64/manageArguments.o
aarch64-macos-machO-cManageArguments = bin/lib/static/c/o/mach-o/macos/aarch64/manageArguments.o

build-x86_64-ios-machO-cManageArguments: $(cManageArguments)
	gcc -std=c23 -Wall -O -c $(cManageArguments) -o $(x86_64-ios-machO-cManageArguments)
build-x86_64-macos-machO-cManageArguments: $(cManageArguments)
	gcc -std=c23 -Wall -O -c $(cManageArguments) -o $(x86_64-macos-machO-cManageArguments)
build-aarch64-ios-machO-cManageArguments: $(cManageArguments)
	gcc -std=c23 -Wall -O -c $(cManageArguments) -o $(x86_64-ios-machO-cManageArguments)
build-aarch64-macos-machO-cAudioBeepLibrary: $(cManageArguments)
	gcc -std=c23 -Wall -O -c $(cManageArguments) -o $(x86_64-macos-machO-cManageArguments)

testManageArguments = test/testManageArguments.cpp

x86_64-freebsd-elf-testManageArguments = /home/regyspecial/Scrivania/testManageArguments
x86_64-ios-machO-testManageArguments =   /home/regyspecial/Scrivania/testManageArguments
x86_64-macos-machO-testManageArguments = /Users/*/Desktop/testManageArguments

build-x86_64-freebsd-elf-testManageArguments: $(manageArguments) $(cConsoleLibrary) $(testManageArguments)
	c++ -std=c++26 -Wall -O $(manageArguments) $(cConsoleLibrary) $(testManageArguments) -o $(x86_64-freebsd-elf-testManageArguments)
build-x86_64-macos-machO-testManageArguments: $(testManageArguments) $(x86_64-macos-machO-manageArguments)
	g++ -std=c++26 -Wall -O $(testManageArguments) $(x86_64-macos-machO-manageArguments) -o $(x86_64-macos-machO-testManageArguments)

goImageLibrary = src/lib/go/CImage.go

ppc64-aix-elf-a-goImageLibrary = bin/lib/static/a/go/elf/aix/ppc64/CImage.a

build-ppc64-aix-elf-a-goImageLibrary: $(goImageLibrary)
	GOOS=aix GOARCH=ppc64 go build -buildmode=c-archive -o $(goImageLibrary) $(ppc64-aix-elf-a-goImageLibrary)
	mv bin/lib/static/a/elf/aix/ppc64/Cimage.h src/include/lib/go

386-android-elf-a-goImageLibrary = bin/lib/static/a/go/elf/android/386/CImage.a

build-386-android-elf-a-goImageLibrary: $(goImageLibrary)
	GOOS=android GOARCH=386 go build -buildmode=c-archive -o $(goImageLibrary) $(386-android-elf-a-goImageLibrary)
	mv bin/lib/static/a/elf/android/386/Cimage.h src/include/lib/go

amd64-android-elf-a-goImageLibrary = bin/lib/static/a/go/elf/android/amd64/CImage.a

build-amd64-android-elf-a-goImageLibrary: $(goImageLibrary)
	GOOS=android GOARCH=amd64 go build -buildmode=c-archive -o $(goImageLibrary) $(amd64-android-elf-a-goImageLibrary)
	mv bin/lib/static/a/elf/android/amd64/Cimage.h src/include/lib/go

arm-android-elf-a-goImageLibrary = bin/lib/static/a/go/elf/android/arm/CImage.a

build-arm-android-elf-a-goImageLibrary: $(goImageLibrary)
	GOOS=android GOARCH=arm go build -buildmode=c-archive -o $(goImageLibrary) $(arm-android-elf-a-goImageLibrary)
	mv bin/lib/static/a/elf/android/arm/Cimage.h src/include/lib/go

arm64-android-elf-a-goImageLibrary = bin/lib/static/a/go/elf/android/arm64/CImage.a

build-arm64-android-elf-a-goImageLibrary: $(goImageLibrary)
	GOOS=android GOARCH=arm64 go build -buildmode=c-archive -o $(goImageLibrary) $(arm64-android-elf-a-goImageLibrary)
	mv bin/lib/static/a/elf/android/arm64/Cimage.h src/include/lib/go

amd64-darwin-machO-a-goImageLibrary = bin/lib/static/a/go/machO/darwin/amd64/CImage.a

build-amd64-darwin-machO-a-goImageLibrary: $(goImageLibrary)
	GOOS=darwin GOARCH=amd64 go build -buildmode=c-archive -o $(goImageLibrary) $(amd64-darwin-machO-a-goImageLibrary)
	mv bin/lib/static/a/machO/darwin/amd64/Cimage.h src/include/lib/go

arm64-darwin-machO-a-goImageLibrary = bin/lib/static/a/go/machO/darwin/arm64/CImage.a

build-arm64-darwin-machO-a-goImageLibrary: $(goImageLibrary)
	GOOS=darwin GOARCH=arm64 go build -buildmode=c-archive -o $(goImageLibrary) $(arm64-darwin-machO-a-goImageLibrary)
	mv bin/lib/static/a/machO/darwin/arm64/Cimage.h src/include/lib/go

amd64-dragonfly-elf-a-goImageLibrary = bin/lib/static/a/go/elf/dragonfly/amd64/CImage.a

build-amd64-dragonfly-elf-a-goImageLibrary: $(goImageLibrary)
	GOOS=dragonfly GOARCH=amd64 go build -buildmode=c-archive -o $(goImageLibrary) $(amd64-dragonfly-elf-a-goImageLibrary)
	mv bin/lib/static/a/elf/dragonfly/amd64/Cimage.h src/include/lib/go

386-freebsd-elf-a-goImageLibrary = bin/lib/static/a/go/elf/freebsd/386/CImage.a

build-386-freebsd-elf-a-goImageLibrary: $(goImageLibrary)
	GOOS=freebsd GOARCH=386 go build -buildmode=c-archive -o $(goImageLibrary) $(386-freebsd-elf-a-goImageLibrary)
	mv bin/lib/static/a/elf/freebsd/386/Cimage.h src/include/lib/go

amd64-freebsd-elf-a-goImageLibrary = bin/lib/static/a/go/elf/freebsd/amd64/CImage.a

build-amd64-freebsd-elf-a-goImageLibrary: $(goImageLibrary)
	GOOS=freebsd GOARCH=amd64 go build -buildmode=c-archive -o $(goImageLibrary) $(amd64-freebsd-elf-a-goImageLibrary)
	mv bin/lib/static/a/elf/freebsd/amd64/Cimage.h src/include/lib/go

arm-freebsd-elf-a-goImageLibrary = bin/lib/static/a/go/elf/freebsd/arm/CImage.a

build-arm-freebsd-elf-a-goImageLibrary: $(goImageLibrary)
	GOOS=freebsd GOARCH=arm go build -buildmode=c-archive -o $(goImageLibrary) $(arm-freebsd-elf-a-goImageLibrary)
	mv bin/lib/static/a/elf/freebsd/arm/Cimage.h src/include/lib/go

arm64-freebsd-elf-a-goImageLibrary = bin/lib/static/a/go/elf/freebsd/arm64/CImage.a

build-arm64-freebsd-elf-a-goImageLibrary: $(goImageLibrary)
	GOOS=freebsd GOARCH=arm64 go build -buildmode=c-archive -o $(goImageLibrary) $(arm64-freebsd-elf-a-goImageLibrary)
	mv bin/lib/static/a/elf/freebsd/arm64/Cimage.h src/include/lib/go

amd64-illumos-elf-a-goImageLibrary = bin/lib/static/a/go/elf/illumos/amd64/CImage.a

build-amd64-illumos-elf-a-goImageLibrary: $(goImageLibrary)
	GOOS=illumos GOARCH=amd64 go build -buildmode=c-archive -o $(goImageLibrary) $(amd64-illumos-elf-a-goImageLibrary)
	mv bin/lib/static/a/elf/illumos/amd64/Cimage.h src/include/lib/go

amd64-ios-machO-a-goImageLibrary = bin/lib/static/a/go/machO/ios/amd64/CImage.a

build-amd64-ios-machO-a-goImageLibrary: $(goImageLibrary)
	GOOS=ios GOARCH=amd64 go build -buildmode=c-archive -o $(goImageLibrary) $(amd64-ios-machO-a-goImageLibrary)
	mv bin/lib/static/a/machO/ios/amd64/Cimage.h src/include/lib/go

arm64-ios-machO-a-goImageLibrary = bin/lib/static/a/go/machO/ios/arm64/CImage.a

build-arm64-ios-machO-a-goImageLibrary: $(goImageLibrary)
	GOOS=ios GOARCH=arm64 go build -buildmode=c-archive -o $(goImageLibrary) $(arm64-ios-machO-a-goImageLibrary)
	mv bin/lib/static/a/machO/ios/arm64/Cimage.h src/include/lib/go

wasm-js-wasm-a-goImageLibrary = bin/lib/static/a/go/wasm/js/wasm/CImage.a

build-wasm-js-wasm-a-goImageLibrary: $(goImageLibrary)
	GOOS=js GOARCH=wasm go build -buildmode=c-archive -o $(goImageLibrary) $(wasm-js-wasm-a-goImageLibrary)
	mv bin/lib/static/a/wasm/js/wasm/Cimage.h src/include/lib/go

386-netbsd-elf-a-goImageLibrary = bin/lib/static/a/go/elf/netbsd/386/CImage.a

build-386-netbsd-elf-a-goImageLibrary: $(goImageLibrary)
	GOOS=netbsd GOARCH=386 go build -buildmode=c-archive -o $(goImageLibrary) $(386-netbsd-elf-a-goImageLibrary)
	mv bin/lib/static/a/elf/netbsd/386/Cimage.h src/include/lib/go

amd64-netbsd-elf-a-goImageLibrary = bin/lib/static/a/go/elf/netbsd/amd64/CImage.a

build-amd64-netbsd-elf-a-goImageLibrary: $(goImageLibrary)
	GOOS=netbsd GOARCH=amd64 go build -buildmode=c-archive -o $(goImageLibrary) $(amd64-netbsd-elf-a-goImageLibrary)
	mv bin/lib/static/a/elf/netbsd/amd64/Cimage.h src/include/lib/go

arm-netbsd-elf-a-goImageLibrary = bin/lib/static/a/go/elf/netbsd/arm/CImage.a

build-arm-netbsd-elf-a-goImageLibrary: $(goImageLibrary)
	GOOS=netbsd GOARCH=arm go build -buildmode=c-archive -o $(goImageLibrary) $(arm-netbsd-elf-a-goImageLibrary)
	mv bin/lib/static/a/elf/netbsd/arm/Cimage.h src/include/lib/go

arm64-netbsd-elf-a-goImageLibrary = bin/lib/static/a/go/elf/netbsd/arm64/CImage.a

build-arm64-netbsd-elf-a-goImageLibrary: $(goImageLibrary)
	GOOS=netbsd GOARCH=arm64 go build -buildmode=c-archive -o $(goImageLibrary) $(arm64-netbsd-elf-a-goImageLibrary)
	mv bin/lib/static/a/elf/netbsd/arm64/Cimage.h src/include/lib/go

386-openbsd-elf-a-goImageLibrary = bin/lib/static/a/go/elf/openbsd/386/CImage.a

build-386-openbsd-elf-a-goImageLibrary: $(goImageLibrary)
	GOOS=openbsd GOARCH=386 go build -buildmode=c-archive -o $(goImageLibrary) $(386-openbsd-elf-a-goImageLibrary)
	mv bin/lib/static/a/elf/openbsd/386/Cimage.h src/include/lib/go

amd64-openbsd-elf-a-goImageLibrary = bin/lib/static/a/go/elf/openbsd/amd64/CImage.a

build-amd64-openbsd-elf-a-goImageLibrary: $(goImageLibrary)
	GOOS=openbsd GOARCH=amd64 go build -buildmode=c-archive -o $(goImageLibrary) $(amd64-openbsd-elf-a-goImageLibrary)
	mv bin/lib/static/a/elf/openbsd/amd64/Cimage.h src/include/lib/go

arm-openbsd-elf-a-goImageLibrary = bin/lib/static/a/go/elf/openbsd/arm/CImage.a

build-arm-openbsd-elf-a-goImageLibrary: $(goImageLibrary)
	GOOS=openbsd GOARCH=arm go build -buildmode=c-archive -o $(goImageLibrary) $(arm-openbsd-elf-a-goImageLibrary)
	mv bin/lib/static/a/elf/openbsd/arm/Cimage.h src/include/lib/go

arm64-openbsd-elf-a-goImageLibrary = bin/lib/static/a/go/elf/openbsd/arm64/CImage.a

build-arm64-openbsd-elf-a-goImageLibrary: $(goImageLibrary)
	GOOS=openbsd GOARCH=arm64 go build -buildmode=c-archive -o $(goImageLibrary) $(arm64-openbsd-elf-a-goImageLibrary)
	mv bin/lib/static/a/elf/openbsd/arm64/Cimage.h src/include/lib/go

ppc64-openbsd-elf-a-goImageLibrary = bin/lib/static/a/go/elf/openbsd/ppc64/CImage.a

build-ppc64-openbsd-elf-a-goImageLibrary: $(goImageLibrary)
	GOOS=openbsd GOARCH=ppc64 go build -buildmode=c-archive -o $(goImageLibrary) $(ppc64-openbsd-elf-a-goImageLibrary)
	mv bin/lib/static/a/elf/openbsd/ppc64/Cimage.h src/include/lib/go

riscv64-openbsd-elf-a-goImageLibrary = bin/lib/static/a/go/elf/openbsd/riscv64/CImage.a

build-riscv64-openbsd-elf-a-goImageLibrary: $(goImageLibrary)
	GOOS=openbsd GOARCH=riscv64 go build -buildmode=c-archive -o $(goImageLibrary) $(riscv64-openbsd-elf-a-goImageLibrary)
	mv bin/lib/static/a/elf/openbsd/riscv64/Cimage.h src/include/lib/go

386-plan9-elf-a-goImageLibrary = bin/lib/static/a/go/elf/plan9/386/CImage.a

build-386-plan9-elf-a-goImageLibrary: $(goImageLibrary)
	GOOS=plan9 GOARCH=386 go build -buildmode=c-archive -o $(goImageLibrary) $(386-plan9-elf-a-goImageLibrary)
	mv bin/lib/static/a/elf/plan9/386/Cimage.h src/include/lib/go

amd64-plan9-elf-a-goImageLibrary = bin/lib/static/a/go/elf/plan9/amd64/CImage.a

build-amd64-plan9-elf-a-goImageLibrary: $(goImageLibrary)
	GOOS=plan9 GOARCH=amd64 go build -buildmode=c-archive -o $(goImageLibrary) $(amd64-plan9-elf-a-goImageLibrary)
	mv bin/lib/static/a/elf/plan9/amd64/Cimage.h src/include/lib/go

arm-plan9-elf-a-goImageLibrary = bin/lib/static/a/go/elf/plan9/arm/CImage.a

build-arm-plan9-elf-a-goImageLibrary: $(goImageLibrary)
	GOOS=plan9 GOARCH=arm go build -buildmode=c-archive -o $(goImageLibrary) $(arm-plan9-elf-a-goImageLibrary)
	mv bin/lib/static/a/elf/plan9/arm/Cimage.h src/include/lib/go

amd64-solaris-elf-a-goImageLibrary = bin/lib/static/a/go/elf/solaris/amd64/CImage.a

build-amd64-solaris-elf-a-goImageLibrary: $(goImageLibrary)
	GOOS=solaris GOARCH=amd64 go build -buildmode=c-archive -o $(goImageLibrary) $(amd64-solaris-elf-a-goImageLibrary)
	mv bin/lib/static/a/elf/solaris/amd64/Cimage.h src/include/lib/go

wasm-wasip1-wasm-a-goImageLibrary = bin/lib/static/a/go/wasm/wasip1/wasm/CImage.a

build-wasm-wasip1-wasm-a-goImageLibrary: $(goImageLibrary)
	GOOS=wasip1 GOARCH=wasm go build -buildmode=c-archive -o $(goImageLibrary) $(wasm-wasip1-wasm-a-goImageLibrary)
	mv bin/lib/static/a/wasm/wasip1/wasm/Cimage.h src/include/lib/go

386-windows-pe-a-goImageLibrary = bin/lib/static/a/go/pe/windows/386/CImage.a

build-386-windows-pe-a-goImageLibrary: $(goImageLibrary)
	GOOS=windows GOARCH=386 go build -buildmode=c-archive -o $(goImageLibrary) $(386-windows-pe-a-goImageLibrary)
	mv bin/lib/static/a/pe/windows/386/Cimage.h src/include/lib/go

amd64-windows-pe-a-goImageLibrary = bin/lib/static/a/go/pe/windows/amd64/CImage.a

build-amd64-windows-pe-a-goImageLibrary: $(goImageLibrary)
	GOOS=windows GOARCH=amd64 go build -buildmode=c-archive -o $(goImageLibrary) $(amd64-windows-pe-a-goImageLibrary)
	mv bin/lib/static/a/pe/windows/amd64/Cimage.h src/include/lib/go

arm64-windows-pe-a-goImageLibrary = bin/lib/static/a/go/pe/windows/arm64/CImage.a

build-arm64-windows-pe-a-goImageLibrary: $(goImageLibrary)
	GOOS=windows GOARCH=arm64 go build -buildmode=c-archive -o $(goImageLibrary) $(arm64-windows-pe-a-goImageLibrary)
	mv bin/lib/static/a/pe/windows/arm64/Cimage.h src/include/lib/go

apple-mainWindow =        src/main/swift/mainWindow.swift
apple-mainScreenButtons = src/main/swift/mainScreenButtons.swift
apple-mainDialogs =       src/main/swift/mainDialogs.swift
apple-gameModeButtons =   src/main/swift/gameModeButtons.swift
apple-form =              src/main/swift/form.swift
apple-formTextBox =       src/main/swift/formTextBox.swift

build-x86_64-freebsd-elf-testManageArguments: $(mainWindow) $(mainScreenButtons) $(mainDialogs) $(gameModeButtons) $(form) $(formTextBox)
	c++ -std=c++26 -Wall -O $(manageArguments) $(cConsoleLibrary) $(testManageArguments) -o $(x86_64-freebsd-elf-testManageArguments)
build-x86_64-macos-machO-testManageArguments: $(mainWindow) $(mainScreenButtons) $(mainDialogs) $(gameModeButtons) $(form) $(formTextBox)
	g++ -std=c++26 -Wall -O $(testManageArguments) $(x86_64-macos-machO-manageArguments) -o $(x86_64-macos-machO-testManageArguments)

apple-main = src/main/swift/main.swift

#object files
macos-machO = bin/exec/macos/mach-o/x86_64/RegySpecial
ios-machO =   bin/exec/ios/mach-o/x86_64/RegySpecial

arm-windows-pe =  bin/exec/pe/windows/arm/RegySpecial.exe
arm-macos-machO = bin/exec/mach-o/macos/arm/RegySpecial
arm-ios-machO =   bin/exec/mach-o/macos/arm/RegySpecial

build-docker-image:
	docker build scripts/build -t docker-armory

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
