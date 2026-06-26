#include<stdlib.h>
#include<stdio.h>
#include<string.h>
typedef struct{
  unsigned int width,height;
  unsigned long**pixels;
  char*mime;
}image;
int main(){
  image*img=(image*)malloc(sizeof(image));
  img->width=1920;
  img->height=1080;
  img->pixels=(unsigned long**)malloc(sizeof(unsigned long*)*img->height);
  for(unsigned int y=0;y<img->height;y++){
    *(img->pixels+y)=(long*)calloc(img->width,sizeof(unsigned long));
  }
  img->mime=(char*)malloc(14);
  strcpy(img->mime,"image/jpeg");
  for(unsigned int y=0;y<img->height;y++){
    for(unsigned int x=0;x<img->width;x++){
      printf("%li",img->pixels[y][x]);
      if(x<(img->width-1))putchar(',');
    }
    putchar('\n');
  }
  free(img->mime);
  for(unsigned int y=0;y<img->height;y++)free(*(img->pixels+y));
  free(img->pixels);
  free(img);
}
