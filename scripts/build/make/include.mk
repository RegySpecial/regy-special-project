cConsoleLibrary =   src/lib/c/console.c
cAudioBeepLibrary = src/lib/c/audio/beep.c
cColorsLibrary =    src/lib/c/colors.c
cManageArguments =  src/main/c/manageArguments.c

testManageArguments = test/c++/manageArguments.cpp

goImageLibrary = src/lib/go/CImage.go

amd64-testManageArguments = /home/regyspecial/Scrivania/amd64-testManageArguments
amd64-testVideoGame =       /home/regyspecial/Scrivania/amd64-testVideoGame

build-amd64-testManageArguments: $(cManageArguments) $(cColorsLibrary) $(cConsoleLibrary) $(testManageArguments)
	g++ -std=c++26 -Wall -O $(cManageArguments) $(cColorsLibrary) $(cConsoleLibrary) $(testManageArguments) -o $(amd64-testManageArguments)

cppDynamicArrays =        src/lib/c++/DSA/dataStructures/dynamicArrays.cpp
amd64-testDynamicArrays = /home/regyspecial/Scrivania/amd64-testDynamicArrays
build-amd64-testDynamicArrays: $(cppDynamicArrays)
	g++ -std=c++26 -Wall -Wextra -O3 $(cppDynamicArrays) $(cConsoleLibrary) -o $(amd64-testDynamicArrays)

386-a-goImageLibrary = bin/lib/static/a/go/elf/linux/386/CImage.a

amd64-a-goImageLibrary = bin/lib/static/a/go/elf/linux/amd64/CImage.a

arm-a-goImageLibrary = bin/lib/static/a/go/elf/linux/arm/CImage.a

arm64-a-goImageLibrary = bin/lib/static/a/go/elf/linux/arm64/CImage.a

loong64-a-goImageLibrary = bin/lib/static/a/go/elf/linux/loong64/CImage.a

mips-a-goImageLibrary = bin/lib/static/a/go/elf/linux/mips/CImage.a

mips64-a-goImageLibrary = bin/lib/static/a/go/elf/linux/mips64/CImage.a

mips64le-a-goImageLibrary = bin/lib/static/a/go/elf/linux/mips64le/CImage.a

mipsle-a-goImageLibrary = bin/lib/static/a/go/elf/linux/mipsle/CImage.a

ppc64-a-goImageLibrary = bin/lib/static/a/go/elf/linux/ppc64/CImage.a

ppc64le-a-goImageLibrary = bin/lib/static/a/go/elf/linux/ppc64le/CImage.a

riscv64-a-goImageLibrary = bin/lib/static/a/go/elf/linux/riscv64/CImage.a

s390x-a-goImageLibrary = bin/lib/static/a/go/elf/linux/s390x/CImage.a

mainWindow =        src/main/c++/mainWindow.cpp
mainScreenButtons = src/main/c++/mainScreenButtons.cpp
mainDialogs =       src/main/c++/mainDialogs.cpp
gameModeButtons =   src/main/c++/gameModeButtons.cpp
form =              src/main/c++/form.cpp
formTextBox =       src/main/c++/formTextBox.cpp
testVideoGame =     test/videoGame.cpp