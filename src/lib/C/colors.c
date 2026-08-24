#include "../../include/lib/c/colors.h"

rgba  rgbToRgba(rgb rgbStruct)
{
  rgba rgbaStruct = {
    rgbStruct.red,
    rgbStruct.green,
    rgbStruct.blue,
    -1
  };
  return rgbaStruct;
}
cmyk  rgbToCmyk(rgb rgbStruct)
{
  cmyk cmykStruct;
  unsigned char max = 0; 
  for (unsigned char i = 0; i < 2; i++)
  {
    unsigned char color[3]=(unsigned char*) &rgbStruct;
    if (color[i] > color[0])
      max = color[i];
  }
  cmykStruct.black = 255 - max;
  cmykStruct.cyan = 255 - rgbStruct.red / (255 * (255 - cmykStruct.black));
  cmykStruct.magenta = 255 - rgbStruct.green / (255 * (255 - cmykStruct.black));
  cmykStruct.yellow = 255 - rgbStruct.blue / (255 * (255 - cmykStruct.black));
  return cmykStruct;
}
cmyka rgbToCmyka(rgb rgbStruct){
  cmyk cmykStruct = rgbToCmyk(rgbStruct);
  cmyka cmykaStruct = {
    cmykStruct.cyan,
    cmykStruct.magenta,
    cmykStruct.yellow,
    cmykStruct.black,
    -1
  };
  return cmykaStruct;
}
hsl  rgbToHsl(rgb rgbStruct)
{
  hsl hslStruct;
  unsigned char colorsInInterval01[] = {rgbStruct.red / 255, rgbStruct.green / 255, rgbStruct.blue / 255},
                a = colorsInInterval01[2] >= colorsInInterval01[1] ? 1 : -1,
                min = 0,
                max = 0,
                delta = 0;

  for (unsigned char i = 0; i < 3; i++)
    if (*colorsInInterval01 < colorsInInterval01[i])
      max = colorsInInterval01[i];
    else
      min = colorsInInterval01[i];
  
  delta = max - min;
  
  hslStruct.lightness = (rgbStruct.red + rgbStruct.green + rgbStruct.blue) / 3;
  hslStruct.saturation = delta == 0 ? 0 : (delta / (1 - abs(2 * hslStruct.lightness / 255 - 1))) * 255;
  hslStruct.hue = a * acos((*colorsInInterval01 - hslStruct.lightness) / (hslStruct.saturation * sqrt(2))) + (1 - a) * acos(-1);
  return hslStruct;
}
hsla  rgbToHsla(rgb rgbStruct)
{
  hsl hslStruct = rgbToHsl(rgbStruct);
  hsla hslaStruct = {
    hslStruct.hue,
    hslStruct.saturation,
    hslStruct.lightness,
    -1
  };
  return hslaStruct;
}
rgb   rgbaToRgb(rgba rgbaStruct)
{
  rgb rgbStruct = {
    rgbaStruct.red,
    rgbaStruct.green,
    rgbaStruct.blue
  };
  return rgbStruct;
}
cmyk  rgbaToCmyk(rgba rgbaStruct)
{
  cmyk cmykStruct;
  unsigned char max = 0; 
  for (unsigned char i = 0; i < 2; i++)
  {
    unsigned char color[3]=(unsigned char*) &rgbaStruct;
    if (color[i] > color[0])
      max = color[i];
  }
  cmykStruct.black = 255 - max;
  cmykStruct.cyan = 255 - rgbaStruct.red / (255 * (255 - cmykStruct.black));
  cmykStruct.magenta = 255 - rgbaStruct.green / (255 * (255 - cmykStruct.black));
  cmykStruct.yellow = 255 - rgbaStruct.blue / (255 * (255 - cmykStruct.black));
  return cmykStruct;
}
cmyka rgbaToCmyka(rgba rgbaStruct)
{
  cmyka cmykaStruct = {.alpha = rgbaStruct.alpha};
  unsigned char max = 0; 
  for (unsigned char i = 0; i < 2; i++)
  {
    unsigned char color[3]=(unsigned char*) &rgbaStruct;
    if (color[i] > color[0])
      max = color[i];
  }
  cmykaStruct.black = 255 - max;
  cmykaStruct.cyan = 255 - rgbaStruct.red / (255 * (255 - cmykaStruct.black));
  cmykaStruct.magenta = 255 - rgbaStruct.green / (255 * (255 - cmykaStruct.black));
  cmykaStruct.yellow = 255 - rgbaStruct.blue / (255 * (255 - cmykaStruct.black));
  return cmykaStruct;
}
hsl   rgbaToHsl(rgba rgbaStruct)
{
  hsl hslStruct;
  unsigned char colorsInInterval01[] = {rgbaStruct.red / 255, rgbaStruct.green / 255, rgbaStruct.blue / 255},
                a = colorsInInterval01[2] >= colorsInInterval01[1] ? 1 : -1,
                min = 0,
                max = 0,
                delta = 0;

  for (unsigned char i = 0; i < 3; i++)
    if (*colorsInInterval01 < colorsInInterval01[i])
      max = colorsInInterval01[i];
    else
      min = colorsInInterval01[i];
  
  delta = max - min;
  
  hslStruct.lightness = (rgbaStruct.red + rgbaStruct.green + rgbaStruct.blue) / 3;
  hslStruct.saturation = delta == 0 ? 0 : (delta / (1 - abs(2 * hslStruct.lightness / 255 - 1))) * 255;
  hslStruct.hue = a * acos((*colorsInInterval01 - hslStruct.lightness) / (hslStruct.saturation * sqrt(2))) + (1 - a) * acos(-1);
  return hslStruct;
}
hsla  rgbaToHsla(rgba rgbaStruct)
{
  hsla hslaStruct = {.alpha = rgbaStruct.alpha};
  unsigned char colorsInInterval01[] = {rgbaStruct.red / 255, rgbaStruct.green / 255, rgbaStruct.blue / 255},
                a = colorsInInterval01[2] >= colorsInInterval01[1] ? 1 : -1,
                min = 0,
                max = 0,
                delta = 0;

  for (unsigned char i = 0; i < 3; i++)
    if (*colorsInInterval01 < colorsInInterval01[i])
      max = colorsInInterval01[i];
    else
      min = colorsInInterval01[i];
  
  delta = max - min;
  
  hslaStruct.lightness = (rgbaStruct.red + rgbaStruct.green + rgbaStruct.blue) / 3;
  hslaStruct.saturation = delta == 0 ? 0 : (delta / (1 - abs(2 * hslaStruct.lightness / 255 - 1))) * 255;
  hslaStruct.hue = a * acos((*colorsInInterval01 - hslaStruct.lightness) / (hslaStruct.saturation * sqrt(2))) + (1 - a) * acos(-1);
  return hslaStruct;
}
rgb   cmykToRgb(cmyk cmykStruct)
{
  rgb rgbStruct = {
    255 * (255 - cmykStruct.cyan) * (255 - cmykStruct.black),
    255 * (255 - cmykStruct.magenta) * (255 - cmykStruct.black),
    255 * (255 - cmykStruct.yellow) * (255 - cmykStruct.black)
  };
  return rgbStruct;
}
rgba  cmykToRgba(cmyk cmykStruct)
{
  return rgbToRgba(cmykToRgb(cmykStruct));
}
cmyka cmykToCmyka(cmyk cmykStruct)
{
  cmyka cmykaStruct = {
    cmykStruct.cyan,
    cmykStruct.magenta,
    cmykStruct.yellow,
    -1
  };
  return cmykaStruct;
}
hsl   cmykToHsl(cmyk cmykStruct)
{
  return rgbToHsl(cmykToRgb(cmykStruct));
}
hsla  cmykToHsla(cmyk cmykStruct)
{
  return rgbaToHsla(cmykToRgba(cmykStruct));
}
rgb   cmykaToRgb(cmyka cmykaStruct)
{
  rgb rgbStruct = {
    255 * (255 - cmykaStruct.cyan) * (255 - cmykaStruct.black),
    255 * (255 - cmykaStruct.magenta) * (255 - cmykaStruct.black),
    255 * (255 - cmykaStruct.yellow) * (255 - cmykaStruct.black)
  };
  return rgbStruct;
}
rgba  cmykaToRgba(cmyka cmykaStruct)
{
  rgba rgbaStruct = {
    255 * (255 - cmykaStruct.cyan) * (255 - cmykaStruct.black),
    255 * (255 - cmykaStruct.magenta) * (255 - cmykaStruct.black),
    255 * (255 - cmykaStruct.yellow) * (255 - cmykaStruct.black),
    cmykaStruct.alpha
  };
  return rgbaStruct;
}
cmyk  cmykaToCmyk(cmyka cmykaStruct)
{
  cmyk cmykStruct = {
    cmykaStruct.cyan,
    cmykaStruct.magenta,
    cmykaStruct.yellow
  };
  return cmykStruct;
}
hsl   cmykaToHsl(cmyka cmykaStruct){
  return rgbToHsl(cmykaToRgb(cmykaStruct));
}
hsla  cmykaToHsla(cmyka cmykaStruct)
{
  return rgbaToHsla(cmykaToRgba(cmykaStruct));
}
rgb   hslToRgb(hsl hslStruct)
{
  rgb rgbStruct;
  unsigned char hueInRadiants = (2 * acos(-1) * hslStruct.hue) / 255,
                saturationInInterval01 = hslStruct.saturation / 255,
                lightnessInInterval01 = hslStruct.lightness / 255;
  rgbStruct.red = (lightnessInInterval01 + saturationInInterval01 * sqrt(2) * cos(hueInRadiants)) * 255;
  rgbStruct.green = (lightnessInInterval01 + saturationInInterval01 * sqrt(2) * cos(hueInRadiants + 4 / 3 * acos(-1))) * 255;
  rgbStruct.blue = (lightnessInInterval01 + saturationInInterval01 * sqrt(2) * cos(hueInRadiants + 2 / 3 * acos(-1))) * 255;
  return rgbStruct;
}
rgba  hslToRgba(hsl hslStruct)
{
  return rgbToRgba(hslToRgb(hslStruct));
}
cmyk  hslToCmyk(hsl hslStruct)
{
  return rgbToCmyk(hslToRgb(hslStruct));
}
cmyka hslToCmyka(hsl hslStruct)
{
  return rgbToCmyka(hslToRgb(hslStruct));
}
hsla  hslToHsla(hsl hslStruct)
{
  return rgbToHsla(hslToRgb(hslStruct));
}
rgb   hslaToRgb(hsla hslaStruct)
{
  return hslToRgb(hslaToHsl(hslaStruct));
}
rgba  hslaToRgba(hsla hslaStruct)
{
  rgba rgbaStruct = {.alpha = hslaStruct.alpha};
  unsigned char hueInRadiants = (2 * acos(-1) * hslaStruct.hue) / 255,
                saturationInInterval01 = hslaStruct.saturation / 255,
                lightnessInInterval01 = hslaStruct.lightness / 255;
  rgbaStruct.red = (lightnessInInterval01 + saturationInInterval01 * sqrt(2) * cos(hueInRadiants)) * 255;
  rgbaStruct.green = (lightnessInInterval01 + saturationInInterval01 * sqrt(2) * cos(hueInRadiants + 4 / 3 * acos(-1))) * 255;
  rgbaStruct.blue = (lightnessInInterval01 + saturationInInterval01 * sqrt(2) * cos(hueInRadiants + 2 / 3 * acos(-1))) * 255;
  return rgbaStruct;
}
cmyk  hslaToCmyk(hsla hslaStruct)
{
  return rgbToCmyk(hslaToRgb(hslaStruct));
}
cmyka hslaToCmyka(hsla hslaStruct)
{
  return rgbaToCmyka(hslaToRgba(hslaStruct));
}
hsl   hslaToHsl(hsla hslaStruct)
{
  hsl hslStruct = {
    hslaStruct.hue,
    hslaStruct.saturation,
    hslaStruct.lightness
  };
  return hslStruct;
}