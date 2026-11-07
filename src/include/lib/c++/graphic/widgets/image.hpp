#include <stdio.h>

class image
{
  public:
    unsigned long color : 24 = 0,
                  *pixels;
    unsigned int x = 0,
                 y = 0;
    int width =  0,
        height = 0;
    
    image(const char *path);
		image(unsigned int x, unsigned int y, int width, int height, unsigned long *pixels);
		image(unsigned int x, unsigned int y, const char *path);
		image(unsigned int x, unsigned int y, int width, int height, const char *path);
		image(int width, int height, const char *path);
		~image();
};