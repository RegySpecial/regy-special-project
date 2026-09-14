#ifndef formTextBoxHpp
#define formTextBoxHpp
#include "form.hpp"
class formTextBox:public commonWidgetInterface{
public:
  form*root;
	unsigned char pointer=0,
	              min=1,
	              max=40,
								textSize=0;
  formTextBox(form*root);
  ~formTextBox();
  int show(unsigned int microseconds);
  int hide(unsigned int microseconds);
};
#endif