#ifndef screenHpp 
#define screenHpp

#include "../core.hpp"

class screen
{
	public:
	  application *app;
	  unsigned int width,
	               height;
	  int depth;
		dynamicArray<int> availableDepths;
		screen(application *app);
};
#endif