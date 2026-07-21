/*
*@description Main entry point of the videogame
*@author Regy Special
*@date (First version [Linux]) 2026 July 19th Sunday, 16:02:19
*@license GNU General Public License to stop private corporation to not share source code
*/
#ifndef mainDialogsHpp
#define mainDialogsHpp
#include "mainScreenButtons.hpp"
#include "../c/dialogOrganization.h"
class dialog:public commonWidgetInterface{
public:
  mainWindow*root;
  unsigned char type;
  dialog(mainWindow*root,unsigned char type);
  ~dialog();
};
#endif