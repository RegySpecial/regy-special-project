#ifndef lib_cpp_graphic_widgets_styles_fontHpp
#define lib_cpp_graphic_widgets_styles_fontHpp
#include "../widget.hpp"
class font
{
  private:
	  Font identifier;
		char *foundry,
		     *family;
    unsigned int size,
		             weight,
								 slant,
								 style;
  public:
    font(widget *wgt, char *family, unsigned int size, unsigned int weight)
		{
			this->identifier = XLoadFont(wgt->app->display, family);
			this->family = family;
			this->size = size;
			this->weight = weight;
		}
};
#endif