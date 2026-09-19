#include "../src/include/main/c++/formTextBox.hpp"
#include "../src/include/main/c++/mainScreenButtons.hpp"
int main(int argc, char* argv[], char* envp[])
{
    mainWindow main_window(argc, argv, envp, "Vaffanculo");
    mainScreenButton coso(&main_window, "coso");
    main_window.show(0);
}