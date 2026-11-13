#ifndef audioPcmHpp
#define audioPcmHpp
#include "../../c/audio/core.h"

class pulseCodeModulation
{
  private:
    int fileDescriptor,
        errorNumber;
    unsigned int deviceNumber,
                 subdeviceNumber,
                 subdevicesCount,
                 subdevicesAvailables,
                 channelNumber,
                 channelFirst,
                 channelStep;
    int streamDirection,
        cardNumber,
        cClass,
        subclass;
    unsigned char id[64],
                  deviceName[80],
                  subdeviceName[32],
                  pad1[16],
                  reserved[64];
    
	  long memoryMapOffset;

  public:
    pulseCodeModulation(const char *pulseCodeModulationDriverPath);
    ~pulseCodeModulation();

    inline int getFileDescriptor() const
    {
      return this->fileDescriptor;
    }

    inline int getErrorNumber() const
    {
      return this->errorNumber;
    }

    inline unsigned int getDeviceNumber() const
    {
      return this->deviceNumber;
    }

    inline unsigned int getSubdeviceNumber() const
    {
      return this->subdeviceNumber;
    }
    
    inline unsigned int getSubdevicesCount() const
    {
      return this->subdevicesCount;
    }
    
    inline unsigned int getSubdevicesAvailables() const
    {
      return this->subdevicesAvailables;
    }
    
    inline int getStreamDirection() const
    {
      return this->streamDirection;
    }

    inline int getCardNumber() const
    {
      return this->cardNumber;
    }

    inline int getClass() const
    {
      return this->cClass;
    }

    inline int getSubclass() const
    {
      return this->subclass;
    }

    bool start(unsigned int microseconds);
    bool pause(unsigned int microseconds, int enable);
    bool resume(unsigned int microseconds);
    bool drop(unsigned int microseconds);
    bool drain(unsigned int microseconds);
    bool reset(unsigned int microseconds);
    bool xrun(unsigned int microseconds);
};
#endif