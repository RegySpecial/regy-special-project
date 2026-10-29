#include "../../src/include/main/c++/formTextBox.hpp"
#include "../../src/include/main/c++/mainScreenButtons.hpp"
int main(int argc, char * argv[], char * envp[])
{
    application app(argc, argv, envp);
    window main_window(&app, "Vaffanculo");
    mainScreenButton coso(&main_window, "coso");
    main_window.show(0);
}