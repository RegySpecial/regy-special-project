#include "../../../src/include/lib/c++/graphic/application/application.hpp"
#include "../../../src/include/lib/c++/graphic/widgets/window.hpp"

int main(int argc, char * argv[], char * envp[])
{
    application app(argc, argv, envp);
    window main_window(&app, "Vaffanculo");
    main_window.show(0);
}