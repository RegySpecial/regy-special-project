/*
*@description Main entry point of the videogame
*@author Regy Special
*@date (First version [Linux]) 2026 July 20th Sunday, 15:46:00
*@license GNU General Public License to stop private corporation to not share source code
*/
#include "mainDialogs.hpp"
class gameModeButton:public commonWidgetInterface{
  public:
    dialog*root;
    gameModeButton(dialog*root,const char*text);
    void onclick(XEvent*event,void*extraArgs);
};