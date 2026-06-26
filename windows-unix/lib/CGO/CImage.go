package main
/*
#include<stdlib.h>
#include<stdio.h>
typedef struct{
  unsigned long
    width,
    height,
    **pixels;
  char*mime;
}image;
*/
import "C"
import "unsafe"
import "image/jpeg"
import "image/png"
import "image"
import "fmt"
import "os"
//export RetrieveImageData
func RetrieveImageData(path*C.char)(width,height int,mime,data*C.char){
  file,err:=os.Open(C.GoString(path))
  if err!=nil{
    fmt.Println("error while loading the file")
    return 0,0,nil,nil
  }
  defer file.Close()
  imgFile,imgType,imgError:=image.Decode(file)
  if imgError!=nil{
    fmt.Println("File decoding failed!")
    return 0,0,nil,nil
  }
  var ImageSize int=imgFile.Bounds().Max.X*imgFile.Bounds().Max.Y*4
  ImageData:=C.malloc(C.size_t(ImageSize))
  if ImageData==nil{
    fmt.Println("Heap allocation failed");
    return 0,0,nil,nil
  }
  copyData:=(*[1 << 30]byte)(unsafe.Pointer(ImageData))[:ImageSize:ImageSize]
  nrgba:=image.NewNRGBA(imgFile.Bounds())
  for y:=0;y<imgFile.Bounds().Dy();y++{
    for x:=0;x<imgFile.Bounds().Dx();x++{
      nrgba.Set(x,y,imgFile.At(x,y))
    }
  }
  copy(copyData,nrgba.Pix)
  return imgFile.Bounds().Max.X,imgFile.Bounds().Max.Y,C.CString(imgType),(*C.char)(ImageData)
}
//export CleanImageData
func CleanImageData(data*C.char){
  if data!=nil{
    C.free(unsafe.Pointer(data))
    data=nil
  }
}

//export RetrieveDataFromJpegImage
func RetrieveDataFromJpegImage(path*C.char)(width,height int,data*C.char){
  file,err:=os.Open(C.GoString(path))
  if err!=nil{
    fmt.Println("error while loading the file")
    return 0,0,nil
  }
  defer file.Close()

  jpegFile,errJpeg:=jpeg.Decode(file)
  if errJpeg!=nil{
    fmt.Println("File decoding failed! ",errJpeg)
    return 0,0,nil
  }

  var ImageSize int=jpegFile.Bounds().Dx()*jpegFile.Bounds().Dy()*4
  ImageData:=C.malloc(C.size_t(ImageSize))
  if ImageData==nil{
    fmt.Println("Heap allocation failed");
    return 0,0,nil
  }
  copyData:=(*[1<<30]byte)(unsafe.Pointer(ImageData))[:ImageSize:ImageSize]
  nrgba:=image.NewNRGBA(jpegFile.Bounds())
  for y:=0;y<jpegFile.Bounds().Dy();y++{
    for x:=0;x<jpegFile.Bounds().Dx();x++{
      nrgba.Set(x,y,jpegFile.At(x,y))
    }
  }
  copy(copyData,nrgba.Pix)
  return jpegFile.Bounds().Dx(),jpegFile.Bounds().Dy(),(*C.char)(ImageData)
}
//export RetrieveDataFromPngImage
func RetrieveDataFromPngImage(path*C.char)(width int,height int,data*C.char){
  file,err:=os.Open(C.GoString(path))
  if err!=nil{
    fmt.Println("error while loading the file")
    return 0,0,nil
  }
  defer file.Close()
  
  pngFile,errPng:=png.Decode(file)
  if errPng!=nil{
    fmt.Println("File decoding failed!")
    return 0,0,nil
  }

  var ImageSize int=pngFile.Bounds().Dx()*pngFile.Bounds().Dy()*4
  ImageData:=C.malloc(C.size_t(ImageSize))
  if ImageData==nil{
    fmt.Println("Heap allocation failed");
    return 0,0,nil
  }

  copyData:=(*[1<<30]byte)(unsafe.Pointer(ImageData))[:ImageSize:ImageSize]
  nrgba:=image.NewNRGBA(pngFile.Bounds())
  for y:=0;y<pngFile.Bounds().Dy();y++{
    for x:=0;x<pngFile.Bounds().Dx();x++{
      nrgba.Set(x,y,pngFile.At(x,y))
    }
  }
  copy(copyData,nrgba.Pix)
  return pngFile.Bounds().Max.X-pngFile.Bounds().Min.X,pngFile.Bounds().Max.Y-pngFile.Bounds().Min.Y,(*C.char)(ImageData)
}
/*
//export RetrieveGifData
func RetrieveGifData(path*C.char)(width,height,frames int,data**C.char){
  file,err:=os.Open(C.GoString(path))
  if err!=nil{
    fmt.Println("error while loading the file")
  }
  
  gifFile,errGif:=gif.DecodeAll(file)
  if errGif!=nil{
    fmt.Println("File decoding failed! ",errGif)
    return 0,0,0,nil
  }
  var frames[]*image.Paletted=gifFile.Image
  var delay[]int=gifFile.Delay
  for frameIndex:=0;frameIndex<len(frames);frameIndex++{
    for *(frames[frameIndex])
  }
  defer file.Close()
  return gifFile.Bounds().Max.X,gifFile.Bounds().Max.Y,(*C.char)(ImageData)
}
//export CleanGifData
func CleanGifData(data*C.char){
  if data!=nil{
    C.free(unsafe.Pointer(data))
    data=nil
  }
}
*/
func main(){}