package main
/*
#include<stdio.h>
#include<stdlib.h>
*/
import "C"
import "unsafe"
import "image/jpeg"
import "fmt"
import "os"
//export jpg
func jpg(path*C.char)(width,height int,data*C.char){
  file,err:=os.Open(C.GoString(path))
  if err!=nil{
 	fmt.Println("error while loading the file")
 	return 0,0,nil
  }
  jpegFile,errJpeg:=jpeg.Decode(file)
  if errJpeg!=nil{
	fmt.Println("File decoding failed! ",errJpeg)
 	return 0,0,nil
  }
  var ImageSize int=jpegFile.Bounds().Dy()*jpegFile.Bounds().Dx()*4
  Cdata:=C.malloc(C.size_t(ImageSize))
  pixels:=(*[1 << 30]byte)(unsafe.Pointer(Cdata))[:ImageSize:ImageSize]
  var index int=0;
  for y:=0;y<jpegFile.Bounds().Dy();y++{
	for x:=0;x<jpegFile.Bounds().Dx();x++{
	  r,g,b,a:=jpegFile.At(x,y).RGBA()
	  pixels[index]=byte(r>>8)
	  pixels[index+1]=byte(g>>8)
	  pixels[index+2]=byte(b>>8)
	  pixels[index+3]=byte(a>>8)
	}
	index+=4
  }
  defer file.Close()
  return jpegFile.Bounds().Dx(),jpegFile.Bounds().Dy(),(*C.char)(Cdata)
}
func main(){
    file,err:=os.Open("/usr/share/backgrounds/lorikeet.jpg")
	if err!=nil{
		fmt.Println("error while loading the file")
		os.Exit(1)
	}
	jpegFile,errJpeg:=jpeg.Decode(file)
	if errJpeg!=nil{
		fmt.Println("File decoding failed! ",errJpeg)
		os.Exit(1)
	}
	for y:=0;y<jpegFile.Bounds().Dy();y++{
		for x:=0;x<jpegFile.Bounds().Dx();x++{
			r,g,b,a:=jpegFile.At(x,y).RGBA()
            fmt.Printf("%v %v %v %v\n",r>>8,g>>8,b>>8,a>>8)
		}
	}
	defer file.Close()
}
