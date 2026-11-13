#ifndef conceptsHpp
#define conceptsHpp

template <typename signedDataType>
concept signedNumber = (signedDataType)-1 < 0;

template <typename unsignedDataType>
concept unsignedNumber = !signedNumber<unsignedDataType>;
#endif