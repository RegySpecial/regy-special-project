#include "../../../include/lib/c++/audio/mixer.hpp"

mixer::mixer(const char *mixerDriverPath)
{
  int fileDescriptor = open(mixerDriverPath, O_RDONLY);
  if (fileDescriptor == -1)
    return;
  
  struct snd_ctl_elem_info ctlElemInfo;
  
  if (ioctl(fileDescriptor, SNDRV_CTL_ELEM_IFACE_MIXER, &ctlElemInfo) == -1)
    return;
}

mixer::~mixer()
{

}