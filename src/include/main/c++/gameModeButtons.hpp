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
    gameModeButton(dialog*root,const char*text,unsigned long color);
    ~gameModeButton();
    int show(unsigned int microseconds);
    int hide(unsigned int microseconds);
    void onClientMessage(XClientMessageEvent*event,void*extraArgs) override;
    void onResize(XResizeRequestEvent*event,void*extraArgs) override;
    void onButtonUp(XButtonReleasedEvent*event,void*extraArgs) override;
    void onButtonDown(XButtonPressedEvent*event,void*extraArgs) override;
    void onKeyUp(XKeyReleasedEvent*event,void*extraArgs) override;
    void onKeyDown(XKeyPressedEvent*event,void*extraArgs) override;
    void onExpose(XExposeEvent*event,void*extraArgs) override;
};