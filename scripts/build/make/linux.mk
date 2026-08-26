cConsoleLibrary =   src/lib/c/console.c
cAudioBeepLibrary = src/lib/c/audio/beep.c
cManageArguments =  src/main/c/manageArguments.c

testManageArguments = test/testManageArguments.cpp

amd64-testManageArguments = /home/regyspecial/Scrivania/testManageArguments

build-amd64-testManageArguments: $(manageArguments) $(cConsoleLibrary) $(testManageArguments)
	g++ -std=c++26 -Wall -O $(manageArguments) $(cConsoleLibrary) $(testManageArguments) -o $(amd64-testManageArguments)

386-a-goImageLibrary = bin/lib/static/a/go/elf/linux/386/CImage.a

build-386-a-goImageLibrary: $(goImageLibrary)
	GOOS=linux GOARCH=386 go build -buildmode=c-archive -o $(goImageLibrary) $(386-a-goImageLibrary)
	mv bin/lib/static/a/elf/linux/386/Cimage.h src/include/lib/go

amd64-a-goImageLibrary = bin/lib/static/a/go/elf/linux/amd64/CImage.a

build-amd64-a-goImageLibrary: $(goImageLibrary)
	GOOS=linux GOARCH=amd64 go build -buildmode=c-archive -o $(goImageLibrary) $(amd64-a-goImageLibrary)
	mv bin/lib/static/a/elf/linux/amd64/Cimage.h src/include/lib/go

arm-a-goImageLibrary = bin/lib/static/a/go/elf/linux/arm/CImage.a

build-arm-a-goImageLibrary: $(goImageLibrary)
	GOOS=linux GOARCH=arm go build -buildmode=c-archive -o $(goImageLibrary) $(arm-a-goImageLibrary)
	mv bin/lib/static/a/elf/linux/arm/Cimage.h src/include/lib/go

arm64-a-goImageLibrary = bin/lib/static/a/go/elf/linux/arm64/CImage.a

build-arm64-a-goImageLibrary: $(goImageLibrary)
	GOOS=linux GOARCH=arm64 go build -buildmode=c-archive -o $(goImageLibrary) $(arm64-a-goImageLibrary)
	mv bin/lib/static/a/elf/linux/arm64/Cimage.h src/include/lib/go

loong64-a-goImageLibrary = bin/lib/static/a/go/elf/linux/loong64/CImage.a

build-loong64-a-goImageLibrary: $(goImageLibrary)
	GOOS=linux GOARCH=loong64 go build -buildmode=c-archive -o $(goImageLibrary) $(loong64-a-goImageLibrary)
	mv bin/lib/static/a/elf/linux/loong64/Cimage.h src/include/lib/go

mips-a-goImageLibrary = bin/lib/static/a/go/elf/linux/mips/CImage.a

build-mips-a-goImageLibrary: $(goImageLibrary)
	GOOS=linux GOARCH=mips go build -buildmode=c-archive -o $(goImageLibrary) $(mips-a-goImageLibrary)
	mv bin/lib/static/a/elf/linux/mips/Cimage.h src/include/lib/go

mips64-a-goImageLibrary = bin/lib/static/a/go/elf/linux/mips64/CImage.a

build-mips64-a-goImageLibrary: $(goImageLibrary)
	GOOS=linux GOARCH=mips64 go build -buildmode=c-archive -o $(goImageLibrary) $(mips64-a-goImageLibrary)
	mv bin/lib/static/a/elf/linux/mips64/Cimage.h src/include/lib/go

mips64le-a-goImageLibrary = bin/lib/static/a/go/elf/linux/mips64le/CImage.a

build-mips64le-a-goImageLibrary: $(goImageLibrary)
	GOOS=linux GOARCH=mips64le go build -buildmode=c-archive -o $(goImageLibrary) $(mips64le-a-goImageLibrary)
	mv bin/lib/static/a/elf/linux/mips64le/Cimage.h src/include/lib/go

mipsle-a-goImageLibrary = bin/lib/static/a/go/elf/linux/mipsle/CImage.a

build-mipsle-a-goImageLibrary: $(goImageLibrary)
	GOOS=linux GOARCH=mipsle go build -buildmode=c-archive -o $(goImageLibrary) $(mipsle-a-goImageLibrary)
	mv bin/lib/static/a/elf/linux/mipsle/Cimage.h src/include/lib/go

ppc64-a-goImageLibrary = bin/lib/static/a/go/elf/linux/ppc64/CImage.a

build-ppc64-a-goImageLibrary: $(goImageLibrary)
	GOOS=linux GOARCH=ppc64 go build -buildmode=c-archive -o $(goImageLibrary) $(ppc64-a-goImageLibrary)
	mv bin/lib/static/a/elf/linux/ppc64/Cimage.h src/include/lib/go

ppc64le-a-goImageLibrary = bin/lib/static/a/go/elf/linux/ppc64le/CImage.a

build-ppc64le-a-goImageLibrary: $(goImageLibrary)
	GOOS=linux GOARCH=ppc64le go build -buildmode=c-archive -o $(goImageLibrary) $(ppc64le-a-goImageLibrary)
	mv bin/lib/static/a/elf/linux/ppc64le/Cimage.h src/include/lib/go

riscv64-a-goImageLibrary = bin/lib/static/a/go/elf/linux/riscv64/CImage.a

build-riscv64-a-goImageLibrary: $(goImageLibrary)
	GOOS=linux GOARCH=riscv64 go build -buildmode=c-archive -o $(goImageLibrary) $(riscv64-a-goImageLibrary)
	mv bin/lib/static/a/elf/linux/riscv64/Cimage.h src/include/lib/go

s390x-a-goImageLibrary = bin/lib/static/a/go/elf/linux/s390x/CImage.a

build-s390x-a-goImageLibrary: $(goImageLibrary)
	GOOS=linux GOARCH=s390x go build -buildmode=c-archive -o $(goImageLibrary) $(s390x-a-goImageLibrary)
	mv bin/lib/static/a/elf/linux/s390x/Cimage.h src/include/lib/go

mainWindow =        src/main/c++/mainWindow.cpp
mainScreenButtons = src/main/c++/mainScreenButtons.cpp
mainDialogs =       src/main/c++/mainDialogs.cpp
gameModeButtons =   src/main/c++/gameModeButtons.cpp
form =              src/main/c++/form.cpp
formTextBox =       src/main/c++/formTextBox.cpp

build-amd64-testVideoGame: $(mainWindow) $(mainScreenButtons) $(mainDialogs) $(gameModeButtons) $(form) $(formTextBox)
	g++ -std=c++26 -Wall -O $(manageArguments) $(cConsoleLibrary) $(testManageArguments) -o $(amd64-testManageArguments)

main = src/main/c++/main.cpp

amd64-regyspecial =  bin/exec/elf/linux/amd64/RegySpecial
arm-regyspecial =  bin/exec/elf/linux/arm/RegySpecial
riscv-regyspecial =  bin/exec/elf/linux/riscv/RegySpecial

build-amd64-linux-elf:$(cAudioBeepLibrary) $(cConsoleLibrary) $(mainFile) $(cppBitManipulationLibrary) $(goImageLibraryArchive)
	g++ -std=c++26 -Wall -O \
	$(cConsoleLibrary) \
	$(mainFile) \
	$(bitManipulationLibrary) \
	$(goImageLibraryArchive) \
	$(beepLibrary) \
	-o $(amd64-elf) \
	-lX11 -lodbc -lGL

debug-amd64-linux-elf:$(cAudioBeepLibrary) $(cConsoleLibrary) $(mainFile) $(cppBitManipulationLibrary) $(goImageLibraryArchive)
	g++ -std=c++26 -Wall -g \
	$(cConsoleLibrary) \
	$(mainFile) \
	$(bitManipulationLibrary) \
	$(goImageLibraryArchive) \
	$(beepLibrary) \
	-o $(amd64-elf) \
	-lX11 -lodbc -lGL

sanitize-amd64-linux-elf:$(cAudioBeepLibrary) $(cConsoleLibrary) $(mainFile) $(cppBitManipulationLibrary) $(goImageLibraryArchive)
	g++ -std=c++26 -Wall -g -fsanitize=address \
	$(cConsoleLibrary) \
	$(mainFile) \
	$(bitManipulationLibrary) \
	$(goImageLibraryArchive) \
	$(beepLibrary) \
	-o $(amd64-elf) \
	-lX11 -lodbc -lGL

build-amd64-save-temps: 
	g++ -std=c++26 -Wall -O \
	$(cConsoleLibrary) \
	$(mainFile) \
	$(bitManipulationLibrary) \
	$(goImageLibraryArchive) \
	$(beepLibrary) \
	-o $(amd64-elf) \
	-lX11 -lodbc -lGL -save-temps

debug-amd64-save-temps:$(cAudioBeepLibrary) $(cConsoleLibrary) $(mainFile) $(cppBitManipulationLibrary) $(goImageLibraryArchive)
	g++ -std=c++26 -Wall -g \
	$(cConsoleLibrary) \
	$(mainFile) \
	$(bitManipulationLibrary) \
	$(goImageLibraryArchive) \
	$(beepLibrary) \
	-o $(amd64-elf) \
	-lX11 -lodbc -lGL -save-temps

sanitize-amd64-save-temps:$(cAudioBeepLibrary) $(cConsoleLibrary) $(mainFile) $(cppBitManipulationLibrary) $(goImageLibraryArchive)
	g++ -std=c++26 -Wall -g \
	$(cConsoleLibrary) \
	$(mainFile) \
	$(bitManipulationLibrary) \
	$(goImageLibraryArchive) \
	$(beepLibrary) \
	-o $(amd64-elf) \
	-lX11 -lodbc -lGL -save-temps