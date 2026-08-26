cConsoleLibrary =   src/lib/c/console.c
cAudioBeepLibrary = src/lib/c/audio/beep.c
cManageArguments =  src/main/c/manageArguments.c

testManageArguments = test/testManageArguments.cpp

amd64-testManageArguments = /home/regyspecial/Scrivania/testManageArguments

build-amd64-testManageArguments: $(manageArguments) $(cConsoleLibrary) $(testManageArguments)
	c++ -std=c++26 -Wall -O $(manageArguments) $(cConsoleLibrary) $(testManageArguments) -o $(amd64-testManageArguments)

goImageLibrary = src/lib/go/CImage.go

386-a-goImageLibrary = bin/lib/static/a/go/elf/openbsd/386/CImage.a

build-386-a-goImageLibrary: $(goImageLibrary)
	GOOS=openbsd GOARCH=386 go build -buildmode=c-archive -o $(goImageLibrary) $(386-a-goImageLibrary)
	mv bin/lib/static/a/elf/openbsd/386/Cimage.h src/include/lib/go

amd64-a-goImageLibrary = bin/lib/static/a/go/elf/openbsd/amd64/CImage.a

build-amd64-a-goImageLibrary: $(goImageLibrary)
	GOOS=openbsd GOARCH=amd64 go build -buildmode=c-archive -o $(goImageLibrary) $(amd64-a-goImageLibrary)
	mv bin/lib/static/a/elf/openbsd/amd64/Cimage.h src/include/lib/go

arm-a-goImageLibrary = bin/lib/static/a/go/elf/openbsd/arm/CImage.a

build-arm-a-goImageLibrary: $(goImageLibrary)
	GOOS=openbsd GOARCH=arm go build -buildmode=c-archive -o $(goImageLibrary) $(arm-a-goImageLibrary)
	mv bin/lib/static/a/elf/openbsd/arm/Cimage.h src/include/lib/go

arm64-a-goImageLibrary = bin/lib/static/a/go/elf/openbsd/arm64/CImage.a

build-arm64-a-goImageLibrary: $(goImageLibrary)
	GOOS=openbsd GOARCH=arm64 go build -buildmode=c-archive -o $(goImageLibrary) $(arm64-a-goImageLibrary)
	mv bin/lib/static/a/elf/openbsd/arm64/Cimage.h src/include/lib/go

ppc64-a-goImageLibrary = bin/lib/static/a/go/elf/openbsd/ppc64/CImage.a

build-ppc64-a-goImageLibrary: $(goImageLibrary)
	GOOS=openbsd GOARCH=ppc64 go build -buildmode=c-archive -o $(goImageLibrary) $(ppc64-a-goImageLibrary)
	mv bin/lib/static/a/elf/openbsd/ppc64/Cimage.h src/include/lib/go

riscv64-a-goImageLibrary = bin/lib/static/a/go/elf/openbsd/riscv64/CImage.a

build-riscv64-a-goImageLibrary: $(goImageLibrary)
	GOOS=openbsd GOARCH=riscv64 go build -buildmode=c-archive -o $(goImageLibrary) $(riscv64-a-goImageLibrary)
	mv bin/lib/static/a/elf/openbsd/riscv64/Cimage.h src/include/lib/go

mainWindow =        src/main/c++/mainWindow.cpp
mainScreenButtons = src/main/c++/mainScreenButtons.cpp
mainDialogs =       src/main/c++/mainDialogs.cpp
gameModeButtons =   src/main/c++/gameModeButtons.cpp
form =              src/main/c++/form.cpp
formTextBox =       src/main/c++/formTextBox.cpp

build-amd64-testVideoGame: $(mainWindow) $(mainScreenButtons) $(mainDialogs) $(gameModeButtons) $(form) $(formTextBox)
	c++ -std=c++26 -Wall -O $(manageArguments) $(cConsoleLibrary) $(testManageArguments) -o $(amd64-testManageArguments)

main = src/main/c++/main.cpp

amd64-regyspecial =  bin/exec/elf/openbsd/amd64/RegySpecial
arm-regyspecial =  bin/exec/elf/openbsd/arm/RegySpecial
riscv-regyspecial =  bin/exec/elf/openbsd/riscv/RegySpecial

build-amd64-linux-elf:$(cAudioBeepLibrary) $(cConsoleLibrary) $(mainFile) $(cppBitManipulationLibrary) $(goImageLibraryArchive)
	c++ -std=c++26 -Wall -O \
	$(cConsoleLibrary) \
	$(mainFile) \
	$(bitManipulationLibrary) \
	$(goImageLibraryArchive) \
	$(beepLibrary) \
	-o $(amd64-elf) \
	-lX11 -lodbc -lGL

debug-amd64-linux-elf:$(cAudioBeepLibrary) $(cConsoleLibrary) $(mainFile) $(cppBitManipulationLibrary) $(goImageLibraryArchive)
	c++ -std=c++26 -Wall -g \
	$(cConsoleLibrary) \
	$(mainFile) \
	$(bitManipulationLibrary) \
	$(goImageLibraryArchive) \
	$(beepLibrary) \
	-o $(amd64-elf) \
	-lX11 -lodbc -lGL

sanitize-amd64-linux-elf:$(cAudioBeepLibrary) $(cConsoleLibrary) $(mainFile) $(cppBitManipulationLibrary) $(goImageLibraryArchive)
	c++ -std=c++26 -Wall -g -fsanitize=address \
	$(cConsoleLibrary) \
	$(mainFile) \
	$(bitManipulationLibrary) \
	$(goImageLibraryArchive) \
	$(beepLibrary) \
	-o $(amd64-elf) \
	-lX11 -lodbc -lGL

build-amd64-save-temps: 
	c++ -std=c++26 -Wall -O \
	$(cConsoleLibrary) \
	$(mainFile) \
	$(bitManipulationLibrary) \
	$(goImageLibraryArchive) \
	$(beepLibrary) \
	-o $(amd64-elf) \
	-lX11 -lodbc -lGL -save-temps

debug-amd64-save-temps:$(cAudioBeepLibrary) $(cConsoleLibrary) $(mainFile) $(cppBitManipulationLibrary) $(goImageLibraryArchive)
	c++ -std=c++26 -Wall -g \
	$(cConsoleLibrary) \
	$(mainFile) \
	$(bitManipulationLibrary) \
	$(goImageLibraryArchive) \
	$(beepLibrary) \
	-o $(amd64-elf) \
	-lX11 -lodbc -lGL -save-temps

sanitize-amd64-save-temps:$(cAudioBeepLibrary) $(cConsoleLibrary) $(mainFile) $(cppBitManipulationLibrary) $(goImageLibraryArchive)
	c++ -std=c++26 -Wall -g \
	$(cConsoleLibrary) \
	$(mainFile) \
	$(bitManipulationLibrary) \
	$(goImageLibraryArchive) \
	$(beepLibrary) \
	-o $(amd64-elf) \
	-lX11 -lodbc -lGL -save-temps