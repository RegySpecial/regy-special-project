#ifndef formHpp
#define formHpp
#include"mainWindow.hpp"
class form : public widget
{
  public:
    mainWindow *root;
    form(mainWindow *root);
    ~form();
    int show(unsigned int microseconds) override;
    int hide(unsigned int microseconds) override;
};
#endif
