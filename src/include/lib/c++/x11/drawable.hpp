#include"display.hpp"
namespace x11{
  class drawable{
    public:
      XID id;
      x11::display*display;
      unsigned int x,y,width,height;
      int gravity=1;
      struct{
        unsigned long color:24=0;
      }background;
      struct{
        unsigned long color:24=0;
        unsigned int width=1;
      }border;
      long propertyMask=0,
                   eventMask=0,
                   doNotPropagateMask=0;
  };
}