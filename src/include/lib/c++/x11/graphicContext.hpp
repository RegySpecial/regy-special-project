#ifndef graphicContextHpp
#define graphicContextHpp
#include "pixmap.hpp"
namespace x11{
  class graphicContext{
    public:
      GC id;
      Font font;
      unsigned long background:24,
                    foreground:24;
      x11::drawable*drawable;
      unsigned int propertyMask=0;
      struct string{
        int x,y;
        char*string;
        int length;
      }string;
      graphicContext(x11::drawable*drawable);
      inline void flush();
      int drawString(int x,int y,char*string,int length);
      ~graphicContext();
  };
}
#endif