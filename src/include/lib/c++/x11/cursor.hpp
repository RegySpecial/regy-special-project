#ifndef cursorHpp
#define cursorHpp
#include "window.hpp"
namespace x11{
  class cursor:drawable{
    public:
      x11::display*display;
      Cursor id;
      unsigned int shape;
      struct{
        unsigned long color:24;
        unsigned char enableMask:3;
      }foreground;
      cursor(x11::display*display,unsigned int shape);
      cursor(x11::display*display,Font sourceFont,Font maskFont,char sourceChar,char maskChar,XColor*foreground,XColor*background);
      ~cursor();
  };
}
#endif