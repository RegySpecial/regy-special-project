#ifndef audioMixerHpp
#define audioMixerHpp
#include "../../c/audio/core.h"
#include <sound/asequencer.h>
class mixer
{
  public:
    mixer(const char *mixerDriverPath);
    ~mixer();
};
#endif