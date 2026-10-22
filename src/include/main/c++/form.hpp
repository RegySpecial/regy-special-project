#ifndef formHpp
#define formHpp
#include "mainWindow.hpp"
class form : public widget
{
  public:
    window *root;
    form(window *root);
    ~form();
    int show(unsigned int microseconds) override;
    int hide(unsigned int microseconds) override;
};
#endif
