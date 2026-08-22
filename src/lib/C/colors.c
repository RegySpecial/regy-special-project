#include "../../include/lib/c/colors.h"

hsla rgbaToHsla(rgba* rgbaStruct)
{
  hsla hslaStruct;
  hslaStruct.alpha = rgbaStruct->alpha;
  unsigned char colorsInInterval01[] = {rgbaStruct->red / 255, rgbaStruct->green / 255, rgbaStruct->blue / 255},
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
  
  hslaStruct.lightness = (rgbaStruct->red + rgbaStruct->green + rgbaStruct->blue) / 3;
  hslaStruct.saturation = delta == 0 ? 0 : (delta / (1 - abs(2 * hslaStruct.lightness / 255 - 1))) * 255;
  hslaStruct.hue = a * acos((*colorsInInterval01 - hslaStruct.lightness) / (hslaStruct.saturation * sqrt(2))) + (1 - a) * acos(-1);
  return hslaStruct;
}

hsla rgbToHsl(rgba* rgbaStruct)
{
  rgbaStruct->alpha = 255;
  return rgbaToHsla(rgbaStruct);
}

cmyka rgbaToCmyka(rgba* rgbaStruct)
{
  cmyka cmykaStruct;
  cmykaStruct.alpha = rgbaStruct->alpha;
  unsigned char max = 0; 
  for (unsigned char i = 0; i < 2; i++){
    unsigned char color[3]=(unsigned char*) rgbaStruct;
    if (color[i] > color[0])
      max = color[i];
  }
  cmykaStruct.black = 255 - max;
  cmykaStruct.cyan = 255 - rgbaStruct->red / (255 * (255 - cmykaStruct.black));
  cmykaStruct.magenta = 255 - rgbaStruct->green / (255 * (255 - cmykaStruct.black));
  cmykaStruct.yellow = 255 - rgbaStruct->blue / (255 * (255 - cmykaStruct.black));
  return cmykaStruct;
}

cmyka rgbToCmyk(rgba* rgbaStruct)
{
  rgbaStruct->alpha = 255;
  return rgbaToCmyka(rgbaStruct);
}

rgba cmykaToRgba(cmyka* cmykaStruct)
{
  rgba rgbaStruct;
  rgbaStruct.alpha = cmykaStruct->alpha;
  rgbaStruct.red = 255 * (255 - cmykaStruct->cyan) * (255 - cmykaStruct->black);
  rgbaStruct.green = 255 * (255 - cmykaStruct->magenta) * (255 - cmykaStruct->black);
  rgbaStruct.blue = 255 * (255 - cmykaStruct->yellow) * (255 - cmykaStruct->black);
  return rgbaStruct;
}

rgba cmykToRgb(cmyka* cmykaStruct)
{
  cmykaStruct->alpha = 255;
  return cmykaToRgba(cmykaStruct);
}

hsla cmykaToHsla(cmyka* cmykaStruct)
{
  rgba rgbaStruct = cmykaToRgba(cmykaStruct);
  return rgbaToHsla(&rgbaStruct);
}

hsla cmykToHsl(cmyka* cmykaStruct)
{
  cmykaStruct->alpha = 255;
  return cmykaToHsla(cmykaStruct);
}

rgba hslaToRgba(hsla* hslaStruct)
{
  rgba rgbaStruct;
  rgbaStruct.alpha = hslaStruct->alpha;
  unsigned char hueInRadiants = (2 * acos(-1) * hslaStruct->hue) / 255,
                saturationInInterval01 = hslaStruct->saturation / 255,
                lightnessInInterval01 = hslaStruct->lightness / 255;
  rgbaStruct.red = (lightnessInInterval01 + saturationInInterval01 * sqrt(2) * cos(hueInRadiants)) * 255;
  rgbaStruct.green = (lightnessInInterval01 + saturationInInterval01 * sqrt(2) * cos(hueInRadiants + 4 / 3 * acos(-1))) * 255;
  rgbaStruct.blue = (lightnessInInterval01 + saturationInInterval01 * sqrt(2) * cos(hueInRadiants + 2 / 3 * acos(-1))) * 255;
  return rgbaStruct;
}

rgba hslToRgb(hsla* hslaStruct)
{
  hslaStruct->alpha = 255;
  return hslaToRgba(hslaStruct);
}

cmyka hslaToCmyka(hsla* hslaStruct)
{
  rgba rgbaStruct = hslaToRgba(hslaStruct);
  return rgbaToCmyka(&rgbaStruct);
}

cmyka hslToCmyk(hsla* hslaStruct)
{
  hslaStruct->alpha = 255;
  return hslaToCmyka(hslaStruct);
}