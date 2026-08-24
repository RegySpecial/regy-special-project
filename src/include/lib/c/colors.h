#ifndef colorsH
#define colorsH
#include <math.h>
#include <stdlib.h>
#if defined __cplusplus || defined c_plusplus
extern "C"{
#endif
  typedef enum
  {
    colorFunctionType_rgb,
    colorFunctionType_rgba,
    colorFunctionType_hsl,
    colorFunctionType_hsla,
    colorFunctionType_cmyk,
    colorFunctionType_cmyka
  } colorFunctionType;

  typedef struct
  {
    unsigned char red,
                  green,
                  blue;
  } rgb;

  typedef struct
  {
    unsigned char red,
                  green,
                  blue,
                  alpha;
  } rgba;
  
  typedef struct
  {
    unsigned char cyan,
                  yellow,
                  magenta,
                  black;
  } cmyk;

  typedef struct
  {
    unsigned char cyan,
                  yellow,
                  magenta,
                  black,
                  alpha;
  } cmyka;

  typedef struct
  {
    unsigned char hue,
                  saturation,
                  lightness;
  } hsl;

  typedef struct
  {
    unsigned char hue,
                  saturation,
                  lightness,
                  alpha;
  } hsla;

  typedef union
  {
    rgb   RGB;
    rgba  RGBA;
    cmyk  CMYK;
    cmyka CMYKA;
    hsl   HSL;
    hsla  HSLA;
  } colorFunction;

  rgba  rgbToRgba(rgb rgbStruct);
  cmyk  rgbToCmyk(rgb rgbStruct);
  cmyka rgbToCmyka(rgb rgbStruct);
  hsl   rgbToHsl(rgb rgbStruct);
  hsla  rgbToHsla(rgb rgbStruct);
  rgb   rgbaToRgb(rgba rgbaStruct);
  cmyk  rgbaToCmyk(rgba rgbaStruct);
  cmyka rgbaToCmyka(rgba rgbaStruct);
  hsl   rgbaToHsl(rgba rgbaStruct);
  hsla  rgbaToHsla(rgba rgbaStruct);
  rgb   cmykToRgb(cmyk cmykStruct);
  rgba  cmykToRgba(cmyk cmykStruct);
  cmyka cmykToCmyka(cmyk cmykStruct);
  hsl   cmykToHsl(cmyk cmykStruct);
  hsla  cmykToHsla(cmyk cmykStruct);
  rgb   cmykaToRgb(cmyka cmykaStruct);
  rgba  cmykaToRgba(cmyka cmykaStruct);
  cmyk  cmykaToCmyk(cmyka cmykaStruct);
  hsl   cmykaToHsl(cmyka cmykaStruct);
  hsla  cmykaToHsla(cmyka cmykaStruct);
  rgb   hslToRgb(hsl hslStruct);
  rgba  hslToRgba(hsl hslStruct);
  cmyk  hslToCmyk(hsl hslStruct);
  cmyka hslToCmyka(hsl hslStruct);
  hsla  hslToHsla(hsl hslStruct);
  rgb   hslaToRgb(hsla hslaStruct);
  rgba  hslaToRgba(hsla hslaStruct);
  cmyk  hslaToCmyk(hsla hslaStruct);
  cmyka hslaToCmyka(hsla hslaStruct);
  hsl   hslaToHsl(hsla hslaStruct);

#if defined __cplusplus || defined c_plusplus
}
#endif
#endif