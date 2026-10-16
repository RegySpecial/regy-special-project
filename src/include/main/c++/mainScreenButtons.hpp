#include "mainWindow.hpp"
#include "mainDialogs.hpp"
class mainScreenButton : public widget
{
  public:
    mainWindow *root;
    mainScreenButton(mainWindow *root, const char *text);
    ~mainScreenButton();
    int show(unsigned int microseconds) override;
    int hide(unsigned int microseconds) override;
};