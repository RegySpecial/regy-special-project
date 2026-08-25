MinGWc =       C:/MinGW/bin/gcc.exe
MinGWcpp =     C:/MinGW/bin/g++.exe
MinGWwindres = C:/MinGW/bin/windres.exe

cConsoleLibrary = src/lib/c/console.c
cAudioBeepLibrary = src/lib/c/audio/beep.c
cManageArguments =   src/main/c/manageArguments.c

testManageArguments = test/testManageArguments.cpp

x86_64-testManageArguments =    C:/Users/*/Desktop/testManageArguments.exe

build-x86_64-testManageArguments: $(manageArguments) $(cConsoleLibrary) $(testManageArguments)
	$(MinGWcpp) -std=c++26 -Wall -O $(manageArguments) $(cConsoleLibrary) $(testManageArguments) -o $(x86_64-testManageArguments)

mainWindow =        src/main/c++/mainWindow.cpp
mainScreenButtons = src/main/c++/mainScreenButtons.cpp
mainDialogs =       src/main/c++/mainDialogs.cpp
gameModeButtons =   src/main/c++/gameModeButtons.cpp
form =              src/main/c++/form.cpp
formTextBox =       src/main/c++/formTextBox.cpp

build-x86_64-testVideoGame: $(mainWindow) $(mainScreenButtons) $(mainDialogs) $(gameModeButtons) $(form) $(formTextBox)
	$(MinGWcpp) -std=c++26 -Wall -O $(mainWindow) $(mainScreenButtons) $(mainDialogs) $(gameModeButtons) $(form) $(formTextBox) -o $(x86_64-testManageArguments)

resourceScript = scripts/build/windows.rc

#binary object files
x86_64-windowsResources = bin/exec/pe/windows/x86_64/windows.res

i386-pe =   bin/exec/pe/windows/i386/RegySpecial.exe
x86_64-pe = bin/exec/pe/windows/x86_64/RegySpecial.exe
arm64-pe =  bin/exec/pe/windows/arm64/RegySpecial.exe

build-windows-res: $(resourceScript)
	$(MinGWwindres) $(resourceScript) -O coff -o $(windowsResources)

build-x86_64-windows-pe: $(mainFile) $(windowsResources) $(consoleLibrary)
	$(MinGWcpp) -std=c++26 -O $(mainFile) $(windowsResources) $(consoleLibrary) -o $(x86_64-pe) -lwinmm -lgdiplus -lgdi32 -lodbc32

debug-x86_64-windows-pe: $(mainFile) $(windowsResources) $(consoleLibrary)
	$(MinGWcpp) -std=c++26 -g $(mainFile) $(windowsResources) $(consoleLibrary) -o $(x86_64-pe) -lwinmm -lgdiplus -lgdi32 -lodbc32

sanitize-x86_64-windows-pe: $(mainFile) $(windowsResources) $(consoleLibrary)
	$(MinGWcpp) -std=c++26 -g -fsanitize $(mainFile) $(windowsResources) $(consoleLibrary) -o $(x86_64-pe) -lwinmm -lgdiplus -lgdi32 -lodbc32

build-x86_64-save-temps: $(mainFile) $(windowsResources) $(consoleLibrary)
	$(MinGWcpp) -std=c++26 -O $(mainFile) $(windowsResources) $(consoleLibrary) -o $(x86_64-pe) -lwinmm -lgdiplus -lgdi32 -lodbc32 -save-temps

debug-x86_64-save-temps: $(mainFile) $(windowsResources) $(consoleLibrary)
	$(MinGWcpp) -std=c++26 -g $(mainFile) $(windowsResources) $(consoleLibrary) -o $(x86_64-pe) -lwinmm -lgdiplus -lgdi32 -lodbc32 -save-temps

sanitize-x86_64-save-temps: $(mainFile) $(windowsResources) $(consoleLibrary)
	$(MinGWcpp) -std=c++26 -g -fsanitize $(mainFile) $(windowsResources) $(consoleLibrary) -o $(x86_64-pe) -lwinmm -lgdiplus -lgdi32 -lodbc32 -save-temps