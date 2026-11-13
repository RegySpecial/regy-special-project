#include "../../../src/include/lib/c/audio/beep.h"
#include "../../../src/include/main/c/console.h"
#include <sound/asound.h>
#include <sound/asequencer.h>

int main()
{
  bool beepExit = beep(1000, 100);

  if (!beepExit)
  {
    errorMessage("Failed to beep at frequency of %lu Hz and for %lu ms!", 1000, 100);
    return 1;
  }
  
  struct snd_pcm_info pcmInfo;

  successMessage("Beep at frequency of %lu Hz and for %lu ms succeded!", 1000, 100);
  int a = open("/dev/snd/pcmC0D0c", O_RDONLY);
  printf("%d\n", ioctl(a, SNDRV_PCM_IOCTL_INFO, &pcmInfo));
  printf("%s\n", pcmInfo.name);
  close(a);
  
  return 0;
}