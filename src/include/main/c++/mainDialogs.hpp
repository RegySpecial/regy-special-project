/*
*@description Main entry point of the videogame
*@author Regy Special
*@date (First version [Linux]) 2026 July 19th Sunday, 16:02:19
*@license GNU General Public License to stop private corporation to not share source code
*/
#ifndef mainDialogsHpp
#define mainDialogsHpp
#include "mainWindow.hpp"
#include "../c/dialogOrganization.h"
#include "../c/info/user/byteOrder.h"
#include "../c/info/user/cpu.h"
#include "../c/info/user/os.h"
#include "../c/info/vendor/compiler.h"
class dialog:public commonWidgetInterface{
public:
  mainWindow*root;
  unsigned char type;
  dialog(mainWindow*root,unsigned char type);
  ~dialog();
  int show(unsigned int microseconds) override;
  int hide(unsigned int microseconds) override;
  void onClientMessage(XClientMessageEvent*event,void*extraArgs) override;
  void onResize(XResizeRequestEvent*event,void*extraArgs) override;
  void onButtonUp(XButtonReleasedEvent*event,void*extraArgs) override;
  void onButtonDown(XButtonPressedEvent*event,void*extraArgs) override;
  void onKeyUp(XKeyReleasedEvent*event,void*extraArgs) override;
  void onKeyDown(XKeyPressedEvent*event,void*extraArgs) override;
  void onExpose(XExposeEvent*event,void*extraArgs) override;
};
#endif