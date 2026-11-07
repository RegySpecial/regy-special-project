#include "../../include/main/c++/application.hpp"

#if defined __WIN32 || defined __WIN64
application::application(HINSTANCE hInst, HINSTANCE hInstPrev, char *cmdline, int cmdshow)
{
  this->hInst = hInst;
  this->hInstPrev = hInstPrev;
  this->cmdline = cmdline;
  this->cmdshow = cmdshow;
}
#else
application::application(int argc, char **argv, char **envp)
{
  this->argc = argc;
  this->argv = argv;
  this->envp = envp;

  this->gameContextContainer = manageCommandLineArguments(this->argc, this->argv);

  this->display = 
  #ifdef WaylandEnabled
  wl_display_connect
  #else
  XOpenDisplay
  #endif
  (0);

  if (!this->display)
  {
    errorMessage
    (
      "Cannot establish a connection with the "
      #ifdef WaylandEnabled
      "Wayland"
      #else
      "X"
      #endif
      " Graphic Server"
    );
    abort();
  }

  this->screen = XDefaultScreenOfDisplay(this->display);

  if (!this->screen)
  {
    errorMessage("cannot get informations about the screen");
    abort();
  }
}
#endif

application::~application()
{
  #if defined __WIN32 || defined __WIN64
  #else
  #ifdef WaylandEnabled
  wl_display_disconnect
  #else
  XCloseDisplay
  #endif
  (this->display);
  #endif
}

void application::eventLoop(unsigned int microseconds)
{
  #if defined __WIN32 || defined __WIN64
  Sleep
  #else
  usleep
  #endif
  (microseconds);

  for (XEvent eventStructure; readBit<unsigned char>(this->gameContextContainer.generalPurposeMask, generalPurposeMaskBits_eventLoop);)
  {
    XNextEvent(this->display, &eventStructure);
    for (unsigned long long eventQueueIndex = 0; eventQueueIndex < this->eventQueue.size; eventQueueIndex++)
    {
      switch (eventStructure.type)
      {
        case KeyPress:
          this->eventQueue.at(eventQueueIndex).target;
          break;
        
        default:
          break;
      }
    }
  }
}