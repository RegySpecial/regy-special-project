#include "../../../src/include/lib/c/audio/beep.h"
#include "../../../src/include/main/c/console.h"

int main()
{
  bool beepExit = beep(1000, 100);

  if (!beepExit)
  {
    errorMessage("Failed to beep at frequency of %lu Hz and for %lu ms!", 1000, 100);
    return 1;
  }
  
  successMessage("Beep at frequency of %lu Hz and for %lu ms succeded!", 1000, 100);
  
  return 0;
}