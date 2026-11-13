#include "../../../include/lib/c++/audio/pcm.hpp"

pulseCodeModulation::pulseCodeModulation(const char *pulseCodeModulationDriverPath)
{
  this->errorNumber = 0;
  this->fileDescriptor = open(pulseCodeModulationDriverPath, O_RDONLY);

  if (this->fileDescriptor == -1)
  {
    this->errorNumber = errno;
    return;
  }
  
  struct snd_pcm_info pulseCodeModulationInformation;
  if (ioctl(this->fileDescriptor, SNDRV_PCM_IOCTL_INFO, &pulseCodeModulationInformation) == -1)
  {
    this->errorNumber = errno;
    return;
  }
  
  this->deviceNumber = pulseCodeModulationInformation.device;
	this->subdeviceNumber = pulseCodeModulationInformation.subdevice;
  this->subdevicesCount = pulseCodeModulationInformation.subdevices_count;
  this->subdevicesAvailables = pulseCodeModulationInformation.subdevices_avail;
  this->streamDirection = pulseCodeModulationInformation.stream;
	this->cardNumber = pulseCodeModulationInformation.card;
  this->cClass = pulseCodeModulationInformation.dev_class;
  this->subclass = pulseCodeModulationInformation.dev_subclass;

  unsigned char i = 0;

  for (; i < sizeof pulseCodeModulationInformation.id / sizeof *pulseCodeModulationInformation.id; i++)
	  this->id[i] = pulseCodeModulationInformation.id[i];
  
  for (i = 0; i < sizeof pulseCodeModulationInformation.name / sizeof *pulseCodeModulationInformation.name; i++)
	  this->deviceName[i] = pulseCodeModulationInformation.name[i];
  
	for (i = 0; i < sizeof pulseCodeModulationInformation.subname / sizeof *pulseCodeModulationInformation.subname; i++)
	  this->subdeviceName[i] = pulseCodeModulationInformation.subname[i];
  
  for (i = 0; i < sizeof pulseCodeModulationInformation.pad1 / sizeof *pulseCodeModulationInformation.pad1; i++)
    this->pad1[i] = pulseCodeModulationInformation.pad1[i];
  
  for (i = 0; i < sizeof pulseCodeModulationInformation.reserved / sizeof *pulseCodeModulationInformation.reserved; i++)
    this->reserved[i] = pulseCodeModulationInformation.reserved[i];
}

pulseCodeModulation::~pulseCodeModulation()
{
  if (close(this->fileDescriptor) == -1)
  {
    this->errorNumber = errno;
    return;
  }
}

bool pulseCodeModulation::start(unsigned int microseconds)
{
  if (usleep(microseconds) == -1)
  {
    this->errorNumber = errno;
    return 0;
  }
  struct snd_pcm_info pulseCodeModulationInformation;
  if (ioctl(this->fileDescriptor, SNDRV_PCM_IOCTL_START, &pulseCodeModulationInformation) != -1)
  {
    this->errorNumber = errno;
    return 0;
  }
  return 1;
}

bool pulseCodeModulation::pause(unsigned int microseconds, int enable)
{
  if (usleep(microseconds) == -1)
  {
    this->errorNumber = errno;
    return 0;
  }
  if (ioctl(this->fileDescriptor, SNDRV_PCM_IOCTL_PAUSE, &enable) != -1)
  {
    this->errorNumber = errno;
    return 0;
  }
  return 1;
}

bool pulseCodeModulation::resume(unsigned int microseconds)
{
  if (usleep(microseconds) == -1)
  {
    this->errorNumber = errno;
    return 0;
  }
  if (ioctl(this->fileDescriptor, SNDRV_PCM_IOCTL_RESUME) != -1)
  {
    this->errorNumber = errno;
    return 0;
  }
  return 1;
}

bool pulseCodeModulation::drop(unsigned int microseconds)
{
  if (usleep(microseconds) == -1)
  {
    this->errorNumber = errno;
    return 0;
  }
  if (ioctl(this->fileDescriptor, SNDRV_PCM_IOCTL_DROP) != -1)
  {
    this->errorNumber = errno;
    return 0;
  }
  return 1;
}

bool pulseCodeModulation::drain(unsigned int microseconds)
{
  if (usleep(microseconds) == -1)
  {
    this->errorNumber = errno;
    return 0;
  }
  if (ioctl(this->fileDescriptor, SNDRV_PCM_IOCTL_DRAIN) != -1)
  {
    this->errorNumber = errno;
    return 0;
  }
  return 1;
}

bool pulseCodeModulation::reset(unsigned int microseconds)
{
  if (usleep(microseconds) == -1)
  {
    this->errorNumber = errno;
    return 0;
  }
  if (ioctl(this->fileDescriptor, SNDRV_PCM_IOCTL_RESET) != -1)
  {
    this->errorNumber = errno;
    return 0;
  }
  return 1;
}

bool pulseCodeModulation::xrun(unsigned int microseconds)
{
  if (usleep(microseconds) == -1)
  {
    this->errorNumber = errno;
    return 0;
  }
  if (ioctl(this->fileDescriptor, SNDRV_PCM_IOCTL_XRUN) != -1)
  {
    this->errorNumber = errno;
    return 0;
  }
  return 1;
}