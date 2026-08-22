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
    hsl   HSL;
    hsla  HSLA;
    cmyk  CMYK;
    cmyka CMYKA;
  } colorFunction;

  hsla  rgbaToHsla(rgba* rgbaStruct);
  hsla  rgbToHsl(rgba* rgbaStruct);
  cmyka rgbaToCmyka(rgba* rgbaStruct);
  cmyka rgbToCmyk(rgba* rgbaStruct);

  rgba cmykaToRgba(cmyka* cmykaStruct);
  rgba cmykToRgb(cmyka* cmykaStruct);
  hsla cmykaToHsla(cmyka* cmykaStruct);
  hsla cmykToHsl(cmyka* cmykaStruct);

  rgba  hslaToRgba(hsla* hslaStruct);
  rgba  hslToRgb(hsla* hslaStruct);
  cmyka hslaToCmyka(hsla* hslaStruct);
  cmyka hslToCmyk(hsla* hslaStruct);
#if defined __cplusplus || defined c_plusplus
}
#endif
#endif