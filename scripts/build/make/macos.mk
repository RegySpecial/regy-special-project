#@description makefile to automate the various steps of compilation for the videogame
#@author Regy Special
#@date 2026 January 16th Friday, 21:11:03
#@license GNU General Public License to stop private corporation to not share source code
cConsoleLibrary = src/lib/c/console.c

amd64-ios-machO-cConsoleLibrary =    bin/lib/static/c/o/mach-o/ios/amd64/console.o
amd64-macos-machO-cConsoleLibrary =  bin/lib/static/c/o/mach-o/macos/amd64/console.o
arm64-ios-machO-cConsoleLibrary =   bin/lib/static/c/o/mach-o/ios/arm64/console.o
arm64-macos-machO-cConsoleLibrary = bin/lib/static/c/o/mach-o/macos/arm64/console.o

build-amd64-ios-machO-cConsoleLibrary: $(cConsoleLibrary)
	gcc -std=c23 -Wall -O -c $(cConsoleLibrary) -o $(amd64-ios-machO-cConsoleLibrary)
build-amd64-macos-machO-cConsoleLibrary: $(cConsoleLibrary)
	gcc -std=c23 -Wall -O -c $(cConsoleLibrary) -o $(amd64-macos-machO-cConsoleLibrary)
build-arm64-ios-machO-cConsoleLibrary: $(cConsoleLibrary)
	gcc -std=c23 -Wall -O -c $(cConsoleLibrary) -o $(amd64-ios-machO-cConsoleLibrary)
build-arm64-macos-machO-cConsoleLibrary: $(cConsoleLibrary)
	gcc -std=c23 -Wall -O -c $(cConsoleLibrary) -o $(amd64-macos-machO-cConsoleLibrary)

cAudioBeepLibrary = src/lib/c/audio/beep.c

amd64-ios-machO-cAudioBeepLibrary =    bin/lib/static/c/o/mach-o/ios/amd64/audioBeepLibrary.o
amd64-macos-machO-cAudioBeepLibrary =  bin/lib/static/c/o/mach-o/macos/amd64/audioBeepLibrary.o
arm64-ios-machO-cAudioBeepLibrary =   bin/lib/static/c/o/mach-o/ios/arm64/audioBeepLibrary.o
arm64-macos-machO-cAudioBeepLibrary = bin/lib/static/c/o/mach-o/macos/arm64/audioBeepLibrary.o

build-amd64-ios-machO-cAudioBeepLibrary: $(cAudioBeepLibrary)
	gcc -std=c23 -Wall -O -c $(cAudioBeepLibrary) -o $(amd64-ios-machO-cAudioBeepLibrary)
build-amd64-macos-machO-cAudioBeepLibrary: $(cAudioBeepLibrary)
	gcc -std=c23 -Wall -O -c $(cAudioBeepLibrary) -o $(amd64-macos-machO-cAudioBeepLibrary)
build-arm64-ios-machO-cAudioBeepLibrary: $(cAudioBeepLibrary)
	gcc -std=c23 -Wall -O -c $(cAudioBeepLibrary) -o $(amd64-ios-machO-cAudioBeepLibrary)
build-arm64-macos-machO-cAudioBeepLibrary: $(cAudioBeepLibrary)
	gcc -std=c23 -Wall -O -c $(cAudioBeepLibrary) -o $(amd64-macos-machO-cAudioBeepLibrary)

cColorsLibrary =    src/lib/c/colors.c

amd64-ios-machO-cColorsLibrary =    bin/lib/static/c/o/mach-o/ios/amd64/colors.o
amd64-macos-machO-cColorsLibrary =  bin/lib/static/c/o/mach-o/macos/amd64/colors.o
arm64-ios-machO-cColorsLibrary =   bin/lib/static/c/o/mach-o/ios/arm64/colors.o
arm64-macos-machO-cColorsLibrary = bin/lib/static/c/o/mach-o/macos/arm64/colors.o

build-amd64-ios-machO-cManageArguments: $(cColorsLibrary)
	gcc -std=c23 -Wall -O -c $(cColorsLibrary) -o $(amd64-ios-machO-cColorsLibrary)
build-amd64-macos-machO-cManageArguments: $(cColorsLibrary)
	gcc -std=c23 -Wall -O -c $(cColorsLibrary) -o $(amd64-macos-machO-cColorsLibrary)
build-arm64-ios-machO-cManageArguments: $(cColorsLibrary)
	gcc -std=c23 -Wall -O -c $(cColorsLibrary) -o $(amd64-ios-machO-cColorsLibrary)
build-arm64-macos-machO-cAudioBeepLibrary: $(cManageArguments)
	gcc -std=c23 -Wall -O -c $(cColorsLibrary) -o $(amd64-macos-machO-cColorsLibrary)

cManageArguments =   src/main/c/manageArguments.c

amd64-ios-machO-cManageArguments =    bin/lib/static/c/o/mach-o/ios/amd64/manageArguments.o
amd64-macos-machO-cManageArguments =  bin/lib/static/c/o/mach-o/macos/amd64/manageArguments.o
arm64-ios-machO-cManageArguments =   bin/lib/static/c/o/mach-o/ios/arm64/manageArguments.o
arm64-macos-machO-cManageArguments = bin/lib/static/c/o/mach-o/macos/arm64/manageArguments.o

build-amd64-ios-machO-cManageArguments: $(cManageArguments)
	gcc -std=c23 -Wall -O -c $(cManageArguments) -o $(amd64-ios-machO-cManageArguments)
build-amd64-macos-machO-cManageArguments: $(cManageArguments)
	gcc -std=c23 -Wall -O -c $(cManageArguments) -o $(amd64-macos-machO-cManageArguments)
build-arm64-ios-machO-cManageArguments: $(cManageArguments)
	gcc -std=c23 -Wall -O -c $(cManageArguments) -o $(amd64-ios-machO-cManageArguments)
build-arm64-macos-machO-cAudioBeepLibrary: $(cManageArguments)
	gcc -std=c23 -Wall -O -c $(cManageArguments) -o $(amd64-macos-machO-cManageArguments)

testManageArguments = test/testManageArguments.cpp

amd64-ios-machO-testManageArguments =   /home/regyspecial/Scrivania/testManageArguments
amd64-macos-machO-testManageArguments = /Users/*/Desktop/testManageArguments

build-amd64-macos-machO-testManageArguments: $(testManageArguments) $(amd64-macos-machO-cManageArguments) $(amd64-macos-machO-cColorsLibrary) $(amd64-macos-machO-cAudioBeepLibrary)
	g++ -std=c++26 -Wall -O $(testManageArguments) $(amd64-macos-machO-cManageArguments) $(amd64-macos-machO-cColorsLibrary) $(amd64-macos-machO-cAudioBeepLibrary) -o $(amd64-macos-machO-testManageArguments)

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

build-amd64-macos-machO-testManageArguments: $(mainWindow) $(mainScreenButtons) $(mainDialogs) $(gameModeButtons) $(form) $(formTextBox)
	g++ -std=c++26 -Wall -O $(testManageArguments) $(amd64-macos-machO-manageArguments) -o $(amd64-macos-machO-testManageArguments)

apple-main = src/main/swift/main.swift

#object files
macos-machO = bin/exec/macos/mach-o/amd64/RegySpecial
ios-machO =   bin/exec/ios/mach-o/amd64/RegySpecial

arm-macos-machO = bin/exec/mach-o/macos/arm/RegySpecial
arm-ios-machO =   bin/exec/mach-o/macos/arm/RegySpecial

build-docker-image:
	docker build scripts/build -t docker-armory

#compile for Kernel Mach
build-amd64-macos-machO:$(macos-mainFile)
	swiftc -O -target amd64-apple-macosx10.15 $(macos-mainFile) -o $(amd64-mach-o) -framework Cocoa -framework AppKit
debug-amd64-macos-machO:$(macos-mainFile)
	swiftc -g -target amd64-apple-macosx10.15 $(macos-mainFile) -o $(amd64-mach-o)-debug -framework Cocoa -framework AppKit
sanitize-amd64-macos-machO:$(macos-mainFile)
	swiftc -g -target amd64-apple-macosx10.15 -sanitize=address $(macos-mainFile) -o $(amd64-mach-o)-sanitize -framework Cocoa -framework AppKit
build-arm64-macos-machO:$(macos-mainFile)
	swiftc -O -target arm64-apple-macosx10.15 $(macos-mainFile) -o $(amd64-mach-o) -framework Cocoa -framework AppKit
debug-arm64-macos-machO:$(macos-mainFile)
	swiftc -g -target arm64-apple-macosx10.15 $(macos-mainFile) -o $(amd64-mach-o)-debug -framework Cocoa -framework AppKit
sanitize-arm64-macos-machO:$(macos-mainFile)
	swiftc -g -target arm64-apple-macosx10.15 -sanitize=address $(macos-mainFile) -o $(amd64-mach-o)-sanitize -framework Cocoa -framework AppKit


clean:
	rm -r bin/lib/static/c/audio
	rm -r bin/main/c/manageArguments.o

all:
	build-amd64-elf-console \
	build-macos-machO-console \
	build-amd64-elf-audioBeep \
	build-amd64-macos-machO-audioBeep \
	build-amd64-elf-manageArguments \
	build-amd64-macos-machO-manageArguments \
	build-amd64-linux-elf-testManageArguments \
	build-image-a \
	build-docker-image \
	build-windows-res \
	build-amd64-pe \
	debug-amd64-pe \
	sanitize-amd64-pe \
	build-amd64-linux-elf \
	debug-amd64-linux-elf \
	sanitize-amd64-linux-elf \
	build-amd64-elf-save-temps \
	debug-amd64-elf-save-temps \
	sanitize-amd64-elf-save-temps \
	build-macOS-mach-o \
	debug-macos-machO \
	sanitize-mach-o \
	clean

.PHONY:
	build-amd64-elf-console \
	build-macos-machO-console \
	build-amd64-elf-audioBeep \
	build-amd64-macos-machO-audioBeep \
	build-amd64-elf-manageArguments \
	build-amd64-macos-machO-manageArguments \
	build-amd64-linux-elf-testManageArguments \
	build-image-a \
	build-docker-image \
	build-windows-res \
	build-amd64-pe \
	debug-amd64-pe \
	sanitize-amd64-pe \
	build-amd64-linux-elf \
	debug-amd64-linux-elf \
	sanitize-amd64-linux-elf \
	build-amd64-elf-save-temps \
	debug-amd64-elf-save-temps \
	sanitize-amd64-elf-save-temps \
	build-macOS-mach-o \
	debug-macos-machO \
	sanitize-mach-o \
	clean \
	all
