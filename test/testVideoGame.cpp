#include "../src/include/main/c++/formTextBox.hpp"
#include "../src/include/main/c++/mainScreenButtons.hpp"
int main(int argc, char* argv[], char* envp[])
{
    mainWindow window(argc, argv, envp, "Vaffanculo");
    mainScreenButton coso(&window, "coso");
    window.show(0);
}