cConsole =   src/main/c/console.c
cAudioBeepLibrary = src/lib/c/audio/beep.c
cColorsLibrary =    src/lib/c/colors.c
cManageArguments =  src/main/c/manageArguments.c

testManageArguments = test/c++/manageArguments.cpp

goImageLibrary = src/lib/go/CImage.go

amd64-testManageArguments = /home/regyspecial/Scrivania/amd64-testManageArguments
amd64-testVideoGame =       /home/regyspecial/Scrivania/amd64-testVideoGame

build-amd64-testManageArguments: $(cManageArguments) $(cColorsLibrary) $(cConsole) $(testManageArguments)
	g++ -std=c++26 -Wall -Wextra -O $(cManageArguments) $(cColorsLibrary) $(cConsole) $(testManageArguments) -o $(amd64-testManageArguments)

cppDynamicArrays =        src/lib/c++/DSA/dataStructures/dynamicArray.cpp
amd64-testDynamicArrays = /home/regyspecial/Scrivania/amd64-testDynamicArrays
build-amd64-testDynamicArrays: $(cppDynamicArrays) $(cConsole)
	g++ -std=c++26 -Wall -Wextra -O3 $(cppDynamicArrays) $(cConsole) -o $(amd64-testDynamicArrays)

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

mainWindow =        src/lib/c++/graphic/widgets/window.cpp
mainScreenButtons = src/lib/c++/graphic/widgets/mainScreenButtons.cpp
mainDialogs =       src/lib/c++/graphic/widgets/dialog.cpp
gameModeButtons =   src/lib/c++/graphic/widgets/gameModeButtons.cpp
form =              src/lib/c++/graphic/widgets/form.cpp
formTextBox =       src/lib/c++/graphic/widgets/formTextBox.cpp
testVideoGame =     test/src/c++/videoGame.cpp

main = src/main/c++/main.cpp

testBeep = test/src/c/beep.c

test-amd64-beep-and-console: $(testBeep) $(cConsole) $(cAudioBeepLibrary)
	gcc -std=c23 -Wall -Wextra -O3 $(testBeep) $(cConsole) $(cAudioBeepLibrary) -o /home/regyspecial/Scrivania/test-beep

test-amd64-videoGame:

operatingSystem := $(shell uname -o)