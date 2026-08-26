MinGWc =       C:/MinGW/bin/gcc.exe
MinGWcpp =     C:/MinGW/bin/g++.exe
MinGWwindres = C:/MinGW/bin/windres.exe

cConsoleLibrary = src/lib/c/console.c
cAudioBeepLibrary = src/lib/c/audio/beep.c
cManageArguments =   src/main/c/manageArguments.c

testManageArguments = test/testManageArguments.cpp

amd64-testManageArguments =    C:/Users/*/Desktop/testManageArguments.exe

build-amd64-testManageArguments: $(manageArguments) $(cConsoleLibrary) $(testManageArguments)
	$(MinGWcpp) -std=c++26 -Wall -O $(manageArguments) $(cConsoleLibrary) $(testManageArguments) -o $(amd64-testManageArguments)

mainWindow =        src/main/c++/mainWindow.cpp
mainScreenButtons = src/main/c++/mainScreenButtons.cpp
mainDialogs =       src/main/c++/mainDialogs.cpp
gameModeButtons =   src/main/c++/gameModeButtons.cpp
form =              src/main/c++/form.cpp
formTextBox =       src/main/c++/formTextBox.cpp

build-amd64-testVideoGame: $(mainWindow) $(mainScreenButtons) $(mainDialogs) $(gameModeButtons) $(form) $(formTextBox)
	$(MinGWcpp) -std=c++26 -Wall -O $(mainWindow) $(mainScreenButtons) $(mainDialogs) $(gameModeButtons) $(form) $(formTextBox) -o $(amd64-testManageArguments)

resourceScript = scripts/build/windows.rc

#binary object files
amd64-windowsResources = bin/exec/pe/windows/amd64/windows.res

386-pe =   bin/exec/pe/windows/386/RegySpecial.exe
amd64-pe = bin/exec/pe/windows/amd64/RegySpecial.exe
arm64-pe =  bin/exec/pe/windows/arm64/RegySpecial.exe

build-windows-res: $(resourceScript)
	$(MinGWwindres) $(resourceScript) -O coff -o $(windowsResources)

build-amd64-windows-pe: $(mainFile) $(windowsResources) $(consoleLibrary)
	$(MinGWcpp) -std=c++26 -O $(mainFile) $(windowsResources) $(consoleLibrary) -o $(amd64-pe) -lwinmm -lgdiplus -lgdi32 -lodbc32

debug-amd64-windows-pe: $(mainFile) $(windowsResources) $(consoleLibrary)
	$(MinGWcpp) -std=c++26 -g $(mainFile) $(windowsResources) $(consoleLibrary) -o $(amd64-pe) -lwinmm -lgdiplus -lgdi32 -lodbc32

sanitize-amd64-windows-pe: $(mainFile) $(windowsResources) $(consoleLibrary)
	$(MinGWcpp) -std=c++26 -g -fsanitize $(mainFile) $(windowsResources) $(consoleLibrary) -o $(amd64-pe) -lwinmm -lgdiplus -lgdi32 -lodbc32

build-amd64-save-temps: $(mainFile) $(windowsResources) $(consoleLibrary)
	$(MinGWcpp) -std=c++26 -O $(mainFile) $(windowsResources) $(consoleLibrary) -o $(amd64-pe) -lwinmm -lgdiplus -lgdi32 -lodbc32 -save-temps

debug-amd64-save-temps: $(mainFile) $(windowsResources) $(consoleLibrary)
	$(MinGWcpp) -std=c++26 -g $(mainFile) $(windowsResources) $(consoleLibrary) -o $(amd64-pe) -lwinmm -lgdiplus -lgdi32 -lodbc32 -save-temps

sanitize-amd64-save-temps: $(mainFile) $(windowsResources) $(consoleLibrary)
	$(MinGWcpp) -std=c++26 -g -fsanitize $(mainFile) $(windowsResources) $(consoleLibrary) -o $(amd64-pe) -lwinmm -lgdiplus -lgdi32 -lodbc32 -save-temps