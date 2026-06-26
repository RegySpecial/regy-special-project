/*
*@description Main entry point of the videogame
*@author Regy Special
*@date (First version [Windows]) 2024 October 17th Thursday, 01:20:17
*@license GNU General Public License to stop private corporation to not share source code
*/
#if defined __WIN32||defined __WIN64
#include<windows.h>
#include<mmsystem.h>
#include<gdiplus.h>
#include<windowsx.h>
#include<commctrl.h>
#else
//include X11 libraries
#include<GL/glx.h>
#include<X11/Xlib.h>
#include<X11/Xutil.h>
#include<X11/XKBlib.h>
#include<X11/keysym.h>
#include<X11/Xatom.h>
#ifdef __linux__
#include<getopt.h>
#endif
#include<sys/wait.h>
#include<sys/time.h>
#include<pthread.h>
#endif
#include<chrono>
#include<thread>
//include SQL ODBC or Database Connection libraries
#include<sql.h>
#include<sqlext.h>
//include C/C++ standard input/output libraries
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<signal.h>
//include C/C++ string manipulation libraries
#include<string.h>//C
#include<string>//C++
//inlcude C/C++ math library
#include<math.h>//C
#include<assert.h>
//include CGO image functions for image manipulation contained in CImage.go
#include"../../include/CGO/CImage.h"
//include bit manipulation functions contained in bitManipulation.cpp
#include"../../include/C++/bitManipulation.hpp"
//include arrays manipulation functions contained in arrays.cpp
#include"../../include/C++/DSA/algorithms/arrays.hpp"
#include"../../include/C++/dialogOrganization.h"
#include"../../include/C/info/user/cpu.h"
#include"../../include/C/info/user/os.h"
#include"../../include/C/info/user/byteOrder.h"
#include"../../include/C/info/vendor/compiler.h"
#include"../../include/C/generalPurposeMaskBits.h"
#include"../../include/C/audio/beep.h"
typedef enum MainWindowId{
  MainWindow_MainWindow,
  MainWindow_UsernameTextView,
  MainWindow_PlayButton,
  MainWindow_ExitButton,
  MainWindow_OptionsButton,
  MainWindow_MoreInformationButton
}MainWindowElementId;
typedef enum PlayDialogElementId{
  PlayDialog_Title,
  PlayDialog_EasyDifficultyButton,
  PlayDialog_IntermediateDifficultyButton,
  PlayDialog_AdvancedDifficultyButton,
  PlayDialog_ExtremeDifficultyButton,
  PlayDialog_DifficultyExplaination,
  PlayDialog_ConfirmButton,
  PlayDialog_DoNotConfirmButton
}PlayDialogElementId;
typedef enum OptionsDialogElementId{
  OptionsDialog_Title,
  OptionsDialog_EasyDifficultyButton,
  OptionsDialog_IntermediateDifficultyButton,
  OptionsDialog_AdvancedDifficultyButton,
  OptionsDialog_ExtremeDifficultyButton,
  OptionsDialog_DifficultyExplaination,
  OptionsDialog_ConfirmButton,
  OptionsDialog_DoNotConfirmButton
}OptionsDialogElementId;

void PrintSQLDiagnosticError(void* SQLHandle,SQLSMALLINT type,const char* text){
  SQLCHAR state[6],message[256];
  SQLINTEGER nativeError;
  SQLSMALLINT size;
  SQLGetDiagRecA(type,SQLHandle,1,state,&nativeError,message,sizeof(message),&size);
  std::cerr<<text<<": "<<message<<"\n";
}
#if defined __WIN32||defined __WIN64
const struct DialogSize{
  int width=GetSystemMetrics(SM_CXFULLSCREEN)-40;
  int height=GetSystemMetrics(SM_CYFULLSCREEN)-40;
}DialogSize;
const unsigned long colors[4]={0xff00ff00,0xffffff00,0xffff8000,0xffff0000};
const wchar_t *text[4]={L"Semplice",L"Intermedia",L"Avanzata",L"Estrema"};
int __stdcall formCallback(HWND form,unsigned int message,unsigned int wParam,long lParam){
  switch(message){
    default:
      return DefDlgProcA(form,message,wParam,lParam);
  }
}
void MainScreen(HWND MainScreenWindow){
  PAINTSTRUCT mainScreenPaintStructure;
  HDC mainScreenPaint=BeginPaint(MainScreenWindow,&mainScreenPaintStructure);
  Gdiplus::Graphics graphics(mainScreenPaint);
  for(float transparency=255;transparency>0;transparency--){
    graphics.Clear(0);
    Gdiplus::ColorMatrix matrix={
      1,0,0,0,0,
      0,1,0,0,0,
      0,0,1,0,0,
      0,0,0,transparency/255,0,
      0,0,0,0,1
    };
    Gdiplus::ImageAttributes imageAttributes;
    imageAttributes.SetColorMatrix(&matrix,Gdiplus::ColorMatrixFlagsDefault,Gdiplus::ColorAdjustTypeBitmap);
    Gdiplus::Rect rect(0,0,GetSystemMetrics(SM_CXFULLSCREEN),GetSystemMetrics(SM_CYFULLSCREEN));
    Gdiplus::Image image(L"F:/Regy Special/Regy Special Project/blob/images/author-4745750_1280.jpg",0);
    graphics.DrawImage(&image,rect,0,0,image.GetWidth(),image.GetHeight(),Gdiplus::UnitPixel,&imageAttributes);
    Sleep(60/255);
  }
  EndPaint(MainScreenWindow,&mainScreenPaintStructure);
}
void PaintTheIntro(HWND IntroMainWindow){
  PAINTSTRUCT windowBackground;
  HDC Paint=BeginPaint(IntroMainWindow,&windowBackground);
  Gdiplus::Graphics graphics(Paint);
  Gdiplus::Image image(L"F:/Regy Special/Regy Special Project/blob/images/author-4745750_1280.jpg",0),logo(L"F:/Regy Special/RegySpecial.jpg",0);
  Gdiplus::FontFamily fontFamily(L"Magneto");
  Gdiplus::Font font(&fontFamily,50,Gdiplus::FontStyleRegular,Gdiplus::UnitPixel);
  Gdiplus::StringFormat stringAlignment;
  stringAlignment.SetAlignment(Gdiplus::StringAlignmentCenter);
  stringAlignment.SetLineAlignment(Gdiplus::StringAlignmentCenter);
  Gdiplus::RectF fontPosition(0,GetSystemMetrics(SM_CYFULLSCREEN)*9/10,GetSystemMetrics(SM_CXFULLSCREEN),font.GetSize()*2);
  for(float transparency=0,dimensions=0;transparency<=255&&dimensions<=logo.GetWidth()/2;transparency++,dimensions++){
    graphics.Clear(0);
    Gdiplus::SolidBrush authorStringForeground(Gdiplus::Color(transparency,255,255,255));
    Gdiplus::ColorMatrix logoColorMatrix={
      transparency/255,0,0,0,0,
      0,transparency/255,0,0,0,
      0,0,transparency/255,0,0,
      0,0,0,transparency/255,0,
      0,0,0,0,1
    };
    Gdiplus::ImageAttributes logoAttributes;
    logoAttributes.SetColorMatrix(&logoColorMatrix,Gdiplus::ColorMatrixFlagsDefault,Gdiplus::ColorAdjustTypeBitmap);
    Gdiplus::Rect LogoArea(GetSystemMetrics(SM_CXSCREEN)/2-dimensions,GetSystemMetrics(SM_CYSCREEN)/2-dimensions,dimensions,dimensions);
    graphics.DrawImage(&logo,LogoArea,0,0,dimensions,dimensions,Gdiplus::UnitPixel,&logoAttributes);
    graphics.DrawString(L"RegySpecial",wcslen(L"RegySpecial"),&font,fontPosition,&stringAlignment,&authorStringForeground);
    Sleep(60/255);
  }
  graphics.DrawImage(&image,0,0,GetSystemMetrics(SM_CXSCREEN),GetSystemMetrics(SM_CYSCREEN));
  EndPaint(IntroMainWindow,&windowBackground);
}
int __stdcall PlayDialogProcedure(HWND hwnd,unsigned int uMsg,unsigned int wParam,long lParam){
  switch(uMsg){
    case WM_INITDIALOG:
      AnimateWindow(hwnd,1,AW_BLEND);
      SetWindowLongPtr(hwnd,GWL_STYLE,WS_POPUP);
      MoveWindow(hwnd,20,20,DialogSize.width,DialogSize.height,1);
      MoveWindow(GetDlgItem(hwnd,6),25,DialogSize.width/2-125,DialogSize.width/2-25,100,1);
      MoveWindow(GetDlgItem(hwnd,7),DialogSize.width/2+12.5,DialogSize.width/2-125,DialogSize.width/2-25,100,1);
      MoveWindow(GetDlgItem(hwnd,0),20,20,DialogSize.width-40,20,1);
      for(int difficultyButtonID=1;difficultyButtonID<5;difficultyButtonID++)MoveWindow(GetDlgItem(hwnd,difficultyButtonID),20+((DialogSize.width-40)/4)*(difficultyButtonID-1),40,(DialogSize.width-40)/4,20,1);
      MoveWindow(GetDlgItem(hwnd,5),20,60,DialogSize.width-40,200,1);
      break;
    case WM_COMMAND:
      switch(LOWORD(wParam)){
        case 6:
          void*SQLEnvironment,*SQLStatement,*SQLConnection,*SQLDescription;
          signed short SQLReturn;
          SQLReturn=SQLAllocHandle(SQL_HANDLE_ENV,SQL_NULL_HANDLE,&SQLEnvironment);
          if(SQLReturn!=SQL_SUCCESS&&SQLReturn!=SQL_SUCCESS_WITH_INFO)
            PrintSQLDiagnosticError(SQLEnvironment,SQL_HANDLE_ENV,"Errore nell'iniziazione dell'ambiente");
          SQLReturn=SQLSetEnvAttr(SQLEnvironment,SQL_ATTR_ODBC_VERSION,(void*)SQL_OV_ODBC3,0);
          if(SQLReturn!=SQL_SUCCESS&&SQLReturn!=SQL_SUCCESS_WITH_INFO)
            PrintSQLDiagnosticError(SQLEnvironment,SQL_HANDLE_ENV,"Errore nell'attribuzione della connessione");
          SQLReturn=SQLAllocHandle(SQL_HANDLE_DBC, SQLEnvironment, &SQLConnection);
          if(SQLReturn!=SQL_SUCCESS&&SQLReturn!=SQL_SUCCESS_WITH_INFO)
            PrintSQLDiagnosticError(SQLEnvironment,SQL_HANDLE_ENV,"Errore nello stabilire della connessione");
          SQLReturn=SQLDriverConnectA(SQLConnection,NULL,(SQLCHAR*)"DSN=MySQLiteDB;",SQL_NTS,NULL,0,NULL,SQL_DRIVER_COMPLETE);
          if(SQLReturn!=SQL_SUCCESS&&SQLReturn!=SQL_SUCCESS_WITH_INFO)
            PrintSQLDiagnosticError(SQLEnvironment,SQL_HANDLE_ENV,"Errore nella connessione al driver");
          SQLReturn=SQLAllocHandle(SQL_HANDLE_STMT,SQLConnection,&SQLStatement);
          if(SQLReturn!=SQL_SUCCESS&&SQLReturn!=SQL_SUCCESS_WITH_INFO)
            PrintSQLDiagnosticError(SQLEnvironment,SQL_HANDLE_ENV,"Errore nella connessione al driver");
          SQLReturn=SQLExecDirectA(SQLStatement,(SQLCHAR*)"select * from User", SQL_NTS);
          if(SQLFetch(SQLStatement)==SQL_SUCCESS){
            AnimateWindow(hwnd,100,AW_HIDE|AW_BLEND);
            EndDialog(hwnd,6);
            mciSendStringW(L"stop DarkRage",NULL,0,NULL);
            while(SQLFetch(SQLStatement)==SQL_SUCCESS){
              unsigned char name[256];
              long indicator;
              SQLGetData(SQLStatement,2,SQL_C_CHAR,name,sizeof(name),&indicator);
              std::cout<<name<<"\n";
            }
          }else
            PrintSQLDiagnosticError(SQLStatement,SQL_HANDLE_STMT,"Errore nell'esecuzione della query");
          SQLFreeHandle(SQL_HANDLE_STMT,SQLStatement);
          SQLDisconnect(SQLConnection);
          SQLFreeHandle(SQL_HANDLE_DBC,SQLConnection);
          SQLFreeHandle(SQL_HANDLE_ENV,SQLEnvironment);
          break;
        case 7:
          AnimateWindow(hwnd,100,AW_HIDE|AW_BLEND);
          EndDialog(hwnd,7);
          break;
        default:
          const char*modeInformationArray[]={
            "1.I pulsanti di suggerimento e per saltare i rompicapi si ricaricano più velocemente (30 secondi)","2.I rompicapi non richiedono competenze particolari","3.Le azioni disponibili sono presenti all'interno della mappa",
            "1.I pulsanti di suggerimento e per saltare i rompicapi si ricaricano più lentamente (2 minuti)","2.I rompicapi richiedono competenze leggermente più avanzate","3.Le azioni disponibili sono presenti all'interno della mappa",
            "1.I pulsanti di suggerimento e per saltare i rompicapi si ricaricano ancora più lentamente (5 minuti)","2.I rompicapi richiedono competenze più avanzate (livello scuola superiore)","3.Nessuna azione disponibili all'interno della mappa",
            "1.Nessun suggerimento o possibilità di saltare un rompicapo","2.I rompicapi richiedono competenze specifiche (livello scuola superiore/università)","3.Nessuna azione disponibili all'interno della mappa"
          };
          SetWindowTextA(GetDlgItem(hwnd,5),modeInformationArray[LOWORD(wParam)-1]);
          break;
      }
      break;
    case WM_PAINT:
      PAINTSTRUCT paintStructure,titlePaint;

      const HDC paintDC=BeginPaint(hwnd,&paintStructure),
                titleDC=BeginPaint(GetDlgItem(hwnd,0),&titlePaint);

      Gdiplus::Graphics buttonGraphics(paintDC),
                        titleGraphics(titleDC);

      const Gdiplus::SolidBrush brush(0xff000000),
                                titleBrush(Gdiplus::Color::Gold);

      const Gdiplus::Pen pen(0xff808080,5);
      const Gdiplus::FontFamily Magneto(L"Magneto");
      const Gdiplus::Font font(&Magneto,20,Gdiplus::FontStyleRegular,Gdiplus::UnitPixel);
      Gdiplus::StringFormat titleAlign;
      const Gdiplus::RectF titleRect(0,0,DialogSize.width-40,20);
      titleAlign.SetAlignment(Gdiplus::StringAlignmentCenter);
      titleAlign.SetLineAlignment(Gdiplus::StringAlignmentCenter);
      buttonGraphics.FillRectangle(&brush,0,0,DialogSize.width,DialogSize.height);
      buttonGraphics.DrawRectangle(&pen,0,0,DialogSize.width,DialogSize.height);
      titleGraphics.FillRectangle(&brush,0,0,DialogSize.width-40,20);
      titleGraphics.DrawString(L"Difficoltà gioco",-1,&font,titleRect,&titleAlign,&titleBrush);
      EndPaint(hwnd,&paintStructure);
      EndPaint(GetDlgItem(hwnd,0),&titlePaint);
      for(unsigned char INDEX=1;INDEX<5;INDEX++){
        PAINTSTRUCT buttonPaint;
        const HDC paintButtons=BeginPaint(GetDlgItem(hwnd,INDEX),&buttonPaint);
        Gdiplus::Graphics buttonGraphics(paintButtons);
        Gdiplus::SolidBrush foregroundBrush(colors[INDEX-1]),blackBrush(0xff000000);
        const Gdiplus::RectF buttonRect(0,0,(DialogSize.width-40)/4,20);
        buttonGraphics.FillRectangle(&blackBrush,0,0,(DialogSize.width-40)/4,20);
        buttonGraphics.DrawString(text[INDEX-1],wcslen(text[INDEX-1]),&font,buttonRect,&titleAlign,&foregroundBrush);
        EndPaint(GetDlgItem(hwnd,INDEX),&buttonPaint);
      }
      break;
  }
  return 0;
}
int __stdcall OptionsDialogProcedure(HWND hwnd,unsigned int uMsg,unsigned int wParam,long lParam){
  switch(uMsg){
    case WM_INITDIALOG:
      for(const int id:{0,1})SendMessage(GetDlgItem(hwnd,id),TBM_SETRANGE,1,MAKELONG(0,100));
      MoveWindow(hwnd,20,20,DialogSize.width,DialogSize.height,1);
      MoveWindow(GetDlgItem(hwnd,0),25,50,DialogSize.width-50,100,1);
      MoveWindow(GetDlgItem(hwnd,1),25,150,DialogSize.width-50,100,1);
      MoveWindow(GetDlgItem(hwnd,2),25,DialogSize.height-125,DialogSize.width/2-50,100,1);
      MoveWindow(GetDlgItem(hwnd,3),DialogSize.width/2+25,DialogSize.height-125,DialogSize.width/2-50,100,1);
      AnimateWindow(hwnd,1,AW_BLEND);
      SetWindowLongPtr(hwnd,GWL_STYLE,WS_POPUP);
      break;
    case WM_COMMAND:
      switch(HIWORD(wParam)){
        case BN_CLICKED:
          switch(LOWORD(wParam))
          {
            case 2:
              AnimateWindow(hwnd,100,AW_HIDE|AW_BLEND);
              EndDialog(hwnd,2);
              break;
            case 3:
              AnimateWindow(hwnd,100,AW_HIDE|AW_BLEND);
              EndDialog(hwnd,3);
              break;
          }
          break;
      }
      break;
    case WM_PAINT:
      PAINTSTRUCT dialogBackground;
      const HDC paintDC=BeginPaint(hwnd,&dialogBackground);
      Gdiplus::Graphics graphics(paintDC);
      const Gdiplus::SolidBrush brush(0xff000000);
      const Gdiplus::Pen pen(0xff808080,5);
      graphics.FillRectangle(&brush,0,0,DialogSize.width,DialogSize.height);
      graphics.DrawRectangle(&pen,0,0,DialogSize.width,DialogSize.height);
      EndPaint(hwnd,&dialogBackground);
      for(const int id:{2,3}){
        const wchar_t *textes[]={L"Conferma",L"Non Confermare"};
        PAINTSTRUCT buttonStyle;
        const HDC dialogButtonPaint=BeginPaint(GetDlgItem(hwnd,id),&buttonStyle);
        Gdiplus::Graphics graphics(dialogButtonPaint);
        Gdiplus::SolidBrush brush(0xff008080),textBrush(0xffffffff);
        Gdiplus::Pen pen(0xff0000ff,5);
        Gdiplus::FontFamily Magneto(L"Magneto");
        Gdiplus::Font font(&Magneto,10,Gdiplus::FontStyleRegular,Gdiplus::UnitPixel);
        Gdiplus::PointF fontPosition(DialogSize.width/4,25);
        Gdiplus::StringFormat textAlignment;
        textAlignment.SetAlignment(Gdiplus::StringAlignmentCenter);
        textAlignment.SetLineAlignment(Gdiplus::StringAlignmentCenter);
        graphics.FillRectangle(&brush,0,0,DialogSize.width,DialogSize.height);
        graphics.DrawRectangle(&pen,0,0,DialogSize.width,DialogSize.height);
        graphics.DrawString(textes[id-2],wcslen(textes[id-2]),&font,fontPosition,&textAlignment,&textBrush);
        EndPaint(GetDlgItem(hwnd,id),&buttonStyle);
      }
      break;
  }
  return 0;
}
long __stdcall WindowProc(HWND hwnd, unsigned int uMsg, unsigned int wParam, long lParam){
  HDC editDC;
  PAINTSTRUCT PaintDataStructure;
  switch(uMsg){
    case WM_CTLCOLOREDIT:
      editDC=(HDC)wParam;
      SetBkMode(editDC,TRANSPARENT);
      SetTextColor(editDC,RGB(255,255,0));
      return(long)CreateSolidBrush(RGB(0,128,255));
    case WM_COMMAND:
      switch (HIWORD(wParam)){
        case BN_CLICKED:
          Beep(1000,100);
          switch(LOWORD(wParam)){
            case 2:
              DialogBox((HINSTANCE)GetWindowLongPtr(hwnd,GWLP_HINSTANCE),MAKEINTRESOURCE(6),hwnd,PlayDialogProcedure);
              break;
            case 3:
              DestroyWindow(hwnd);
              break;
            case 4:
              DialogBox((HINSTANCE)GetWindowLongPtr(hwnd,GWLP_HINSTANCE),MAKEINTRESOURCE(5),hwnd,OptionsDialogProcedure);
              break;
          }
          break;
      }
      break;
    case WM_DESTROY:
      PostQuitMessage(0);
      break;
    default:
      return DefWindowProc(hwnd, uMsg, wParam, lParam);
  }
}
int APIENTRY WinMain(HINSTANCE hInst,HINSTANCE hInstPrev,char* cmdline,int cmdshow){
  char user[40];
  for(char*args=strtok(cmdline," ");args!=NULL;args=strtok(NULL," ")){
    if(strcmp(args,"help")==0){
      std::cout<<"Guida per l'esecuzione del programma RegySpecial.exe da terminale\nRegySpecial.exe [--help] --user user --background background --music music\n--user: set the user to login\n--background: set background after login\n--music: set music after login\n";
      return 0;
    }
    if(strcmp(args,"user")==0){
      strcpy(user,args);
    }else{
      perror("name cannot be greater than 40 characters\n");
      return 1;
    }
  }
  if(strcmp(cmdline,"")==0){
    char*programName=GetCommandLine();
    int helpProcess=system(strcat(programName," help"));
    if(!helpProcess){
      perror("Failed to create help process\n");
      return 1;
    }
    unsigned long unsignedLongPointer;
    Gdiplus::GdiplusStartupInput gdiplusStartupInput;
    Gdiplus::GdiplusStartup(&unsignedLongPointer,&gdiplusStartupInput,NULL);
    WNDCLASSA windowClass;
    windowClass.hInstance=hInst;
    windowClass.style=CS_HREDRAW|CS_VREDRAW|CS_OWNDC;
    windowClass.lpfnWndProc=WindowProc;
    windowClass.hCursor=LoadCursor(windowClass.hInstance,IDC_ARROW);
    windowClass.hbrBackground=CreateSolidBrush(0);
    windowClass.lpszClassName="RegySpecial";
    windowClass.lpszMenuName="RegySpecial";
    windowClass.hIcon=(HICON)LoadImageA(
      windowClass.hInstance,
      "F:/Regy Special/Regy Special Project/blob/images/RegySpecial.ico",
      IMAGE_ICON,
      0,
      0,
      LR_LOADFROMFILE
    );
    if(RegisterClassA(&windowClass)==0){
      perror("Failed to register the main window class RegySpecial\n");
      return 1;
    }
    const HWND MainWindow=CreateWindowA(
      windowClass.lpszClassName,//window class name
      "RegySpecial",//window title
      WS_POPUP|WS_VISIBLE,//window style
      0,//window x
      0,//window y
      GetSystemMetrics(SM_CXSCREEN),//window width
      GetSystemMetrics(SM_CYSCREEN),//window height
      NULL,//window parent
      (HMENU)MainWindow_MainWindow,//window menu
      windowClass.hInstance,//window instance
      NULL//window extra info(lparam)
    );
    mciSendStringA("open \"F:/Regy Special/Regy Special Project/blob/audios/Sinister_Dark_Ambient_Background_Music_-_Dark_Rage_[_YouConvert.net_].mp3\" type mpegvideo alias DarkRage",NULL,0,NULL);
    mciSendStringA("play DarkRage",NULL,0,NULL);
    HANDLE_WM_PAINT(MainWindow,0,0,PaintTheIntro);
    const HWND UserInput=CreateWindowA(
      "EDIT",
      user,
      WS_CHILD|WS_VISIBLE|ES_CENTER,
      GetSystemMetrics(SM_CXSCREEN)/4,
      GetSystemMetrics(SM_CYSCREEN)/4,
      GetSystemMetrics(SM_CXSCREEN)/2,
      100,
      MainWindow,
      (HMENU)MainWindow_UsernameTextView,
      windowClass.hInstance,
      NULL
    );
    HWND mainScreenButtons[2][2];
    unsigned char i=0;
    for(unsigned char buttonY=0,buttonId=MainWindow_UsernameTextView;buttonY<2;buttonY++){
      for(unsigned char buttonX=0;buttonX<2;buttonX++){
        const char*textes[2][2]={{"Play","Exit"},{"Options","More Information"}};    
        /*
          Grid Calculation
          e[x][y].x=grid.x+grid.xPadding+grid.width/grid.columns*x
          e[x][y].y=grid.y+grid.yPadding+grid.height/grid.rows*y
          e[x][y].width=grid.width/grid.rows-2*grid.xPadding
          e[x][y].height=grid.height/grid.columns-2*grid.yPadding
          e[x][y] is the element of the grid
        */
        mainScreenButtons[buttonY][buttonX]=CreateWindowA(
          "BUTTON",
          textes[buttonY][buttonX],
          WS_CHILD|WS_VISIBLE|BS_OWNERDRAW,
          10+GetSystemMetrics(SM_CXSCREEN)/buttonX,
          10+GetSystemMetrics(SM_CYSCREEN)/buttonY,
          GetSystemMetrics(SM_CXSCREEN)/2-20,
          (50*2+10*3)/2-20,
          MainWindow,
          (HMENU)buttonId++,
          windowClass.hInstance,
          NULL
        );
        HANDLE_WM_PAINT(mainScreenButtons[buttonY][buttonX],0,0,[&](HWND button)->void{
          PAINTSTRUCT paintStructure;
          const HDC paint=BeginPaint(button,&paintStructure);
          Gdiplus::Graphics graphics(paint);
          const Gdiplus::SolidBrush buttonTextColor(0xff0000ff);
          const Gdiplus::SolidBrush buttonBackgroundColor(0xffff0000);
          graphics.FillRectangle(&buttonTextColor,0,0,GetSystemMetrics(SM_CXSCREEN)/2-20,50);
          const Gdiplus::FontFamily fontFamily(L"Magneto");
          const Gdiplus::Font font(&fontFamily,25,Gdiplus::FontStyleRegular,Gdiplus::UnitPixel);
          const Gdiplus::RectF rectf(0,0,GetSystemMetrics(SM_CXSCREEN)/2-20,50);
          Gdiplus::StringFormat stringAlign;
          stringAlign.SetAlignment(Gdiplus::StringAlignmentCenter);
          stringAlign.SetLineAlignment(Gdiplus::StringAlignmentCenter);
          graphics.DrawString((wchar_t*)textes[buttonY][buttonX],-1,&font,rectf,&stringAlign,&buttonBackgroundColor);
          EndPaint(button,&paintStructure);
        });
      }
    }
    const HWND form=CreateDialogParamA(windowClass.hInstance,(char*)0,MainWindow,formCallback,0);
    MSG mainWindowMessage;
    while(GetMessage(&mainWindowMessage,NULL,0,0)){
      TranslateMessage(&mainWindowMessage);
      DispatchMessageA(&mainWindowMessage);
    }
    Gdiplus::GdiplusShutdown(unsignedLongPointer);
    DeleteBrush(windowClass.hbrBackground);
    if(UnregisterClassA("RegySpecial",windowClass.hInstance)==0){
      failureMessage("Cannot unregister the main window class RegySpecial!\n");
      return 1;
    }else OKMessage("The main window class Regyspecial has been unregistered successfully!");
    return mainWindowMessage.wParam;
  }
}
#else
int main(int argc,char*argv[],char*envp[]){
  char userInput[41]={},//user name input (its size is incremented by 1 because of the null terminating character)
     *suboptionValue;
  unsigned char generalPurposeMask=1,//Mask pattern:.|.|.|.|.|dialogBindToWindow|eventLoop|debug
                dialogIndex=0,
                dialogButtonsIndex=0,
                mainScreenButtonX=0,
                mainScreenButtonY=0,
                gameModeIndex=0,
                gameModeInformationPoint=0,
                soundSliderIndex=0,
                helpRechargeButtonIndex=0;

  const char
    *mainButtonTextes[2][2]={{"Play","Exit"},{"Options","More Information"}},
    *modeInformation[4][3]={
      {
        "1.I pulsanti di suggerimento e per saltare i rompicapi si ricaricano più velocemente (30 secondi)",
        "2.I rompicapi non richiedono competenze particolari",
        "3.Le azioni disponibili sono presenti all'interno della mappa"
      },
      {
        "1.I pulsanti di suggerimento e per saltare i rompicapi si ricaricano più lentamente (2 minuti)",
        "2.I rompicapi richiedono competenze leggermente più avanzate",
        "3.Le azioni disponibili sono presenti all'interno della mappa"
      },
      {
        "1.I pulsanti di suggerimento e per saltare i rompicapi si ricaricano ancora più lentamente (5 minuti)",
        "2.I rompicapi richiedono competenze più avanzate (livello scuola superiore)",
        "3.Nessuna azione disponibili all'interno della mappa"
      },
      {
        "1.Nessun suggerimento o possibilità di saltare un rompicapo",
        "2.I rompicapi richiedono competenze specifiche (livello scuola superiore/università)",
        "3.Nessuna azione disponibili all'interno della mappa"
      }
    };

  struct textBoxControl{
    unsigned char pointer=0;
    unsigned char size=0;
  }keyHandler;
  
  manageArguments(argc,argv);
  const struct option longOptions[]={
    {"help",optional_argument,NULL,'h'},
    {"user",required_argument,NULL,'u'},
    {"background",required_argument,NULL,'b'},
    {"audio",required_argument,NULL,'m'},
    {"debug",no_argument,NULL,'d'}
  };
  int gotOptions,gotSuboptions;

  /*
    "::" of "h::u::b:a:d" means optional_argument
    ":" of "h::u::b:a:d" means required_argument
    else no_argument
  */
  while((gotOptions=getopt_long(argc,argv,"h::u:b:a:d",longOptions,NULL))!=-1){
    char *userSuboptions[]={
           "user",
           "idenitifier"
         },
         *backgroundSuboptions[]={
           "color",
           "pixelmap",
           "path"
         };
    switch(gotOptions){
      default:
        failureMessage("Invalid flag!");
        return 1;
        break;
      case 'u':
        while((gotSuboptions=getsubopt(&optarg,userSuboptions,&suboptionValue))!=-1){
          switch(gotSuboptions){
            case 0://handle name suboption case
              if(strlen(suboptionValue)>40){
                failureMessage("Name rejected: the user name character number must lower than or equal to 40 characters!");
                abort();
              }
              //connect to the database and check if name is redondant or not
              informationMessage("Ottienimento informazioni non disponibile al momento");
              break;
            case 1://handle identifier suboption case
              if(atoi(suboptionValue)<0){
                failureMessage("Identifier rejected: the user identifier must be positive!");
                abort();
              }
              //connect to the database and check if the user is identified or not
              informationMessage("Ottienimento informazioni non disponibile al momento");
              return 0;
              break;
          }
        }
        break;
      case 'b':
        while((gotSuboptions=getsubopt(&optarg,backgroundSuboptions,&suboptionValue))!=-1){
          switch(gotSuboptions){
            case 0://handle name suboption case
              if(strlen(suboptionValue)>40){
                failureMessage("Name rejected: the user name character number must lower than or equal to 40 characters!");
                abort();
              }
              //connect to the database and check if name is redondant or not
              informationMessage("Ottienimento informazioni non disponibile al momento");
              break;
            case 1://handle identifier suboption case
              if(atoi(suboptionValue)<0){
                failureMessage("Identifier rejected: the user identifier must be positive!");
                abort();
              }
              //connect to the database and check if the user is identified or not
              informationMessage("Ottienimento informazioni non disponibile al momento");
              break;
          }
        }
        break;
      case 'd':
        generalPurposeMask=setBit<unsigned char>(generalPurposeMask,generalPurposeMaskBits_debug);//set debug bit to 1
        break;
      case 'h':
        if(strcmp(optarg,"user")==0){
          printf("Usage: %s [-u [name=<userName>,identifier=<userId>]|--user=[name<userName>,identifier=<userId>]]\n",argv[0]);
          puts("-u or --user suboption:");
          puts("  name=<userName> Access to your account by name");
          puts("  identifier=<userId> Access to your account by id");
          puts("Description:");
          printf("If <username> is empty, when the game is opened, a form to input it will appear,");
          printf(" else if <userIdentifier> is empty and <username> is the same as any user name in the database,");
          puts(" the same form will require you to input <userIdentifier> instead.");
          return 0;
        }
        if(strcmp(optarg,"background")==0){
          printf("Usage: %s [-b [url=<backgroundURL>,path=<backgroundPath>,color=<backgroundColor>,pixmap=<backgroundPixmap>]|--background=[url=<backgroundURL>,path=<backgroundPath>,color=<backgroundColor>,pixmap=<backgroundPixmap>]]\n",argv[0]);
          printf("-b or --background suboption:\v");
          printf("path=<background path>\v");
          printf("color=<background color>\v");
          printf("pixmap=<pixmap data>\v");
          printf("Description:\v");
          puts("Draw the background of the play screen in the following order: color,pixelmap,backgroundImageFromPath");
          return 0;
        }
        if(optarg==NULL){
          puts("Regy Special videogame");
          printf("Usage: %s [options] \n",argv[0]);
          puts("Options:");
          puts("  --help Display this information");
          char*helpSubopts[]={"--help=user","--help=background"};
          for(unsigned char i=0;i<sizeof helpSubopts/sizeof *helpSubopts;i++){
            int forkHelpProcess=fork(),executionImage;
            switch(forkHelpProcess){
              case -1:
                failureMessage(strerror(3));
                return 1;
                break;
              case 0:
                int executionImage=execl(argv[0],argv[0],helpSubopts[i]);
                if(readBit<unsigned char>(generalPurposeMask,generalPurposeMaskBits_debug))assert(executionImage!=-1);
                else if(executionImage==-1){
                  failureMessage(strerror(3));
                  return 1;
                }
                break;
            }
          }
          wait(0);
          return 0;
        }
        break;
    }
  }

  //handle the extra options
  while(optind<argc)
    printf("Extra args #%u %s",optind++,optarg);

  if(argc==1){
    assert(system(strcat(argv[0]," --help"))==0);
    //assert(system("ffplay -nodisp blob/audios/Sinister_Dark_Ambient_Background_Music_-_Dark_Rage_[_YouConvert.net_].mp3")==0);
    generalPurposeMask=setBit<unsigned char>(generalPurposeMask,generalPurposeMaskBits_dialogBindToWindow);
  }

  char logoImage[]="/media/regyspecial/REGYSPECIAL/Regy Special/regy-special-project/blob/images/bird-1834401_1280.jpg", //path of the image about the creator of the videogame
       backgroundImage[]="/media/regyspecial/REGYSPECIAL/Regy Special/regy-special-project/blob/images/author-4745750_1280.jpg";//path of the image about the introductive background of the videogame

  struct
    RetrieveDataFromJpegImage_return
      logo=RetrieveDataFromJpegImage(logoImage),
      background=RetrieveDataFromJpegImage(backgroundImage);
  if(readBit<unsigned char>(generalPurposeMask,generalPurposeMaskBits_debug))
    assert(XInitThreads());
  else if(XInitThreads())
    OKMessage("X Threads Initialized successfully!");
  else{
    failureMessage("Cannot initialize X Threads!");
    return 1;
  }
  
  Display*display=XOpenDisplay(getenv("DISPLAY"));

  if(readBit<unsigned char>(generalPurposeMask,generalPurposeMaskBits_debug))
    assert(display!=NULL);
  else if(display==NULL){
    failureMessage("Failed to connect to X Graphic server!");
    return 1;
  }else
    OKMessage("The connection to the X Graphic Server has been established successfully!");

  XVisualInfo visualInformation={.c_class=InputOutput};
  
  Screen*screen=XScreenOfDisplay(display,visualInformation.screen);
  
  XSetWindowAttributes
    mainWindowAttributes={
      .background_pixel=0,
      .border_pixel=0,
      .event_mask=ExposureMask|ResizeRedirectMask|StructureNotifyMask
    },
    mainScreenButtonsAttributes={
      .background_pixel=255,//set window background color to blue on RGB format 00000000|00000000|11111111
      .border_pixel=255<<16,//set window border color to red on RGB format 11111111|00000000|00000000
      .event_mask=ButtonPressMask|EnterWindowMask|LeaveWindowMask,
      .do_not_propagate_mask=ButtonPressMask
    },
    mainScreenDialogsAttributes={
      .background_pixel=0,
      .border_pixel=127<<16|127<<8|127,
      .event_mask=ExposureMask
    },
    modeButtonsAttributes={
      .background_pixel=0,
      .border_pixel=0x808080,
      .event_mask=ButtonPressMask|ExposureMask,
      .do_not_propagate_mask=ButtonPress
    },
    formAttributes={
      .background_pixel=0xffffff,
      .border_pixel=0,
      .event_mask=ExposureMask
    },
    formTextBoxAttributes={
      .background_pixel=0,
      .border_pixel=255<<8,
      .event_mask=KeyPressMask|FocusChangeMask|EnterWindowMask|LeaveWindowMask,
      .do_not_propagate_mask=KeyPressMask
    },
    formSubmitButtonAttributes={
      .background_pixel=0xffffff,
      .border_pixel=0,
      .event_mask=ExposureMask|ButtonPressMask,
      .do_not_propagate_mask=ButtonPressMask
    },
    soundSliderAttributes={
     .background_pixel=0,
     .border_pixel=0x808080,
     .event_mask=ButtonPressMask,
     .do_not_propagate_mask=ButtonPressMask
    };
  
  XSizeHints
    mainWindowBounds={
      .x=0,
      .y=0,
      .max_width=screen->width,
      .max_height=screen->height
    },
    dialogBounds={
      .x=20,
      .y=20,
      .width=screen->width-40,
      .height=screen->height-40
    },
    formBounds={
      .x=screen->width*20/100,//20% of screen.width
      .y=screen->height*20/100,//20% of screen.width
      .width=screen->width-2*screen->width*20/100,//screen.width-2*form.x
      .height=screen->height-2*screen->height*20/100,//screen.width-2*form.x
    };

  unsigned long 
    mainWindowMask,
    mainScreenButtonMask;
  
  const Window 
    mainWindow=XCreateWindow(
      display,//display
      XRootWindow(display,visualInformation.screen),//root window
      mainWindowBounds.x,//x
      mainWindowBounds.y,//y
      mainWindowBounds.max_width,//width
      mainWindowBounds.max_height,//height
      1,//border width
      visualInformation.depth,//depth
      visualInformation.c_class,//window class
      visualInformation.visual,//visual
      (mainWindowMask=CWBorderWidth|CWBackPixel|CWBorderPixel|CWEventMask),//window attributes mask
      &mainWindowAttributes//window attributes
    ),
    form=XCreateWindow(
      display,
      mainWindow,
      formBounds.x,//20% of screen.width
      formBounds.y,//20% of screen.width
      formBounds.width,//screen.width-2*form.x
      formBounds.height,//screen.width-2*form.x
      2,
      visualInformation.depth,//depth
      visualInformation.c_class,//window class
      visualInformation.visual,//visual
      CWBorderPixel|CWBackPixel|CWEventMask,
      &formAttributes
    ),
    formTextBox=XCreateWindow(
      display,
      form,
      formBounds.width*5/100,
      formBounds.height*5/100,
      formBounds.width-2*(formBounds.width*10/100),
      formBounds.height*20/200,
      1,
      visualInformation.depth,//depth
      visualInformation.c_class,//window class
      visualInformation.visual,//visual
      CWEventMask|CWDontPropagate|CWBorderPixel|CWBackPixel,
      &formTextBoxAttributes
    ),
    formSubmitButton=XCreateWindow(
      display,
      form,
      formBounds.width-100-10,
      formBounds.height-50-10,
      100,
      50,
      1,
      visualInformation.depth,//depth
      visualInformation.c_class,//window class
      visualInformation.visual,//visual
      CWBackPixel|CWBorderPixel|CWEventMask|CWDontPropagate,
      &formSubmitButtonAttributes
    );
  Window dialogButtons[5][2],
    soundSliders[3],
    mainScreenButtons[2][2],
    dialogs[5],
    gameModeButton[5],
    helpRechargeButtons[2];
  if(readBit<unsigned char>(generalPurposeMask,generalPurposeMaskBits_debug))
    assert(
      XSetStandardProperties(
        display,//display
        mainWindow,//window
        "RegySpecial",//window title
        "RegySpecial",//window icon name
        0,//window pixel map
        argv,//argument vector
        argc,//argument count
        &mainWindowBounds//window size hints
      )
    );
  else if(
    XSetStandardProperties(
      display,//display
      mainWindow,//window
      "RegySpecial",//window title
      "RegySpecial",//window icon name
      0,//window pixel map
      argv,//argument vector
      argc,//argument count
      &mainWindowBounds//window size hints
    )
  )
    OKMessage("Main window standard properties has been set successfully!");
  else{
    failureMessage("Cannot set main window standard properties!");
    return 1;
  }

  if(XMapRaised(display,mainWindow)==1)puts("\e[38;2;255;255;255m[\e[38;2;0;255;0mOK\e[38;2;255;255;255m]The main window has been mapped raised succesfully!");
  else{
    perror("\e[38;2;255;255;255m[\e[38;2;255;0;0mFailed\e[38;2;255;255;255m]Something wrong occured while trying to map raised the main window!");
    return 1;
  }

  for(dialogIndex=0;dialogIndex<5;dialogIndex++){
    dialogs[dialogIndex]=XCreateWindow(
      display,
      dialogIndex==dialogType_layoutMode?XRootWindow(display,visualInformation.screen):mainWindow,
      dialogIndex==dialogType_exit?screen->width/4:20,
      dialogIndex==dialogType_exit?screen->height/4:20,
      dialogIndex==dialogType_exit?screen->width/2:screen->width-40,
      dialogIndex==dialogType_exit?screen->height/2:screen->height-40,
      1,
      visualInformation.depth,//depth
      visualInformation.c_class,//window class
      visualInformation.visual,//visual
      CWBorderWidth|CWBorderPixel|CWBackPixel|CWEventMask,
      &mainScreenDialogsAttributes
    );

    for(dialogButtonsIndex=0;dialogButtonsIndex<2;dialogButtonsIndex++){
      dialogButtons[dialogIndex][dialogButtonsIndex]=XCreateWindow(
        display,
        dialogs[dialogIndex],
        20+dialogBounds.width/2*dialogButtonsIndex,
        20+dialogBounds.height*4/5,
        dialogBounds.width/2-20*2,
        dialogBounds.height/5-20*2,
        1,
        visualInformation.depth,//depth
        visualInformation.c_class,//window class
        visualInformation.visual,//visual
        CWBackPixel|CWBorderWidth|CWBorderPixel|CWEventMask|CWDontPropagate,
        &modeButtonsAttributes
      );  
    }
    if(!dialogs[dialogIndex]){
      std::cerr<<"\e[38;2;255;255;255m[\e[38;2;255;0;0mFailed\e[38;2;255;255;255m]Something wrong occured while trying to create dialog #"<<dialogIndex;
      XDestroyWindow(display,mainWindow);
      XCloseDisplay(display);
      return 1;
    }else printf("\e[38;2;255;255;255m[\e[38;2;0;255;0mOK\e[38;2;255;255;255m]Dialog #%i has been created successfully\n",dialogIndex);
  }

  for(mainScreenButtonY=0;mainScreenButtonY<2;mainScreenButtonY++){
    for(mainScreenButtonX=0;mainScreenButtonX<2;mainScreenButtonX++){
      /*
        Grid Calculation
        e[x][y].x=grid.x+grid.xPadding+grid.width/grid.columns*x
        e[x][y].y=grid.y+grid.yPadding+grid.height/grid.rows*y
        e[x][y].width=grid.width/grid.rows-2*grid.xPadding
        e[x][y].height=grid.height/grid.columns-2*grid.yPadding
        e[x][y] is the element of the grid
      */
      mainScreenButtons[mainScreenButtonY][mainScreenButtonX]=XCreateWindow(
        display,
        mainWindow,
        10+screen->width/2*mainScreenButtonX,
        10+screen->height/4*mainScreenButtonY+screen->height/2,
        screen->width/2-2*10,
        screen->height/4-2*10,
        1,
        visualInformation.depth,//depth
        visualInformation.c_class,//window class
        visualInformation.visual,//visual
        (mainScreenButtonMask=CWBackPixel|CWBorderWidth|CWBorderPixel|CWDontPropagate|CWEventMask),
        &mainScreenButtonsAttributes
      );
      XMapRaised(display,mainScreenButtons[mainScreenButtonY][mainScreenButtonX]);
    }
  }

  if(readBit<unsigned char>(generalPurposeMask,2)==0){
    if(XMapRaised(display,form)==0){
      perror("Failed to map form");
      return 1;
    }else generalPurposeMask=setBit<unsigned char>(generalPurposeMask,1);
    if(XMapSubwindows(display,form)==0){
      perror("Failed to map form children");
      return 1;
    }
  }

  for(soundSliderIndex=0;soundSliderIndex<3;soundSliderIndex++){
    soundSliders[soundSliderIndex]=XCreateWindow(
      display,
      dialogs[dialogType_options],
      400,
      20+20*(soundSliderIndex+1),
      500,
      20,
      1,
      visualInformation.depth,//depth
      visualInformation.c_class,//window class
      visualInformation.visual,//visual
      CWBackPixel|CWBorderPixel|CWBorderWidth|CWEventMask|CWDontPropagate,
      &soundSliderAttributes
    );
  }

  XGCValues
    mainScreenButtonsGCValues={
      .foreground=255<<16,
      .font=XLoadFont(display,"-urw-century schoolbook l-regular-r-normal--0-0-0-0-p-0-iso8859-15")
    },
    gameModeGCValues[5]={
      {.foreground=255<<8},
      {.foreground=255<<16|255<<8},
      {.foreground=255<<16|(255/2)<<8},
      {.foreground=255<<16},
      {.foreground=255<<16|(255/2)}
    },
    dialogsGCValues[5]={
      {.foreground=255},
      {.foreground=255<<8},
      {.foreground=255<<16},
      {.foreground=0xffff},
      {.foreground=0xffffff}
    },
    userInputGCValues={.foreground=255<<8},
    soundSliderGCValues={.foreground=0x00ffff};
  
  GC mainScreenButtonsGC=XCreateGC(display,mainScreenButtons[0][0],GCForeground|GCFont,&mainScreenButtonsGCValues),
     dialogsGCs[5],
     gameModeGCs[5],
     userInputGC=XCreateGC(display,formTextBox,GCForeground,&userInputGCValues),
     soundSliderGC=XCreateGC(display,soundSliders[0],GCForeground,&soundSliderGCValues);
  
  for(dialogIndex=0;dialogIndex<5;dialogIndex++){
    dialogsGCs[dialogIndex]=XCreateGC(
      display,
      dialogs[dialogIndex],
      GCForeground,
      &dialogsGCValues[dialogIndex]
    );
  }
  for(gameModeIndex=0;gameModeIndex<5;gameModeIndex++){
    /*
      Grid Calculation
      e[x][y].x=grid.x+grid.xPadding+grid.width/grid.columns*RowsX
      e[x][y].y=grid.y+grid.yPadding+grid.height/grid.rows*ColumnsY
      e[x][y].width=grid.width/grid.rows-2*grid.xPadding
      e[x][y].height=grid.height/grid.columns-2*grid.yPadding
      e[x][y] is the element of the grid
    */
    gameModeButton[gameModeIndex]=XCreateWindow(
      display,
      dialogs[dialogType_play],
      20+(screen->width-40)/5*gameModeIndex,
      20,
      (screen->width-40)/5-20*2,
      20*2,
      1,
      visualInformation.depth,//depth
      visualInformation.c_class,//window class
      visualInformation.visual,//visual
      CWBackPixel|CWBorderWidth|CWBorderPixel|CWEventMask|CWDontPropagate,
      &modeButtonsAttributes
    );
    gameModeGCs[gameModeIndex]=XCreateGC(display,gameModeButton[gameModeIndex],GCForeground,&gameModeGCValues[gameModeIndex]);
  }

  for(helpRechargeButtonIndex=0;helpRechargeButtonIndex<2;helpRechargeButtonIndex++){
    helpRechargeButtons[helpRechargeButtonIndex]=XCreateWindow(
      display,
      dialogs[dialogType_play],
      20,
      screen->height/10+40,
      20,
      20,
      1,
      visualInformation.depth,
      visualInformation.c_class,
      visualInformation.visual,
      CWEventMask|CWDontPropagate|CWBackPixel|CWBorderPixel|CWBorderWidth,
      &modeButtonsAttributes
    );
  }
  for(XEvent event;readBit<unsigned char>(generalPurposeMask,0)==1;XNextEvent(display,&event)){//while main window event loop is running 
    for(gameModeIndex=0;gameModeIndex<5;gameModeIndex++){
      const char*modeTextes[5]={"Semplice","Intermedia","Avanzata","Estrema","Personalizzata"};
      if(event.xany.window==gameModeButton[gameModeIndex]&&event.type==Expose)
        XDrawString(
          display,
          gameModeButton[gameModeIndex],
          gameModeGCs[gameModeIndex],
          20,
          20,
          modeTextes[gameModeIndex],
          strlen(modeTextes[gameModeIndex])
        );
    }

    if(event.xany.window==dialogs[dialogType_layoutMode]&&event.type==Expose)
      XDrawString(
        display,
        dialogs[dialogType_layoutMode],
        dialogsGCs[dialogType_layoutMode],
        20,
        20,
        "Dialogo aperto, scegliere la modalità",
        sizeof "Dialogo aperto, scegliere la modalità"-1
      );

    if(event.xany.window==dialogs[dialogType_play]&&event.type==Expose)
      for(unsigned char gameModeInformationPoint=0;gameModeInformationPoint<3;gameModeInformationPoint++)
        XDrawString(
          display,
          dialogs[dialogType_play],
          dialogsGCs[dialogType_play],
          20,
          screen->height/10+40+20*gameModeInformationPoint,
          modeInformation[0][gameModeInformationPoint],
          strlen(modeInformation[0][gameModeInformationPoint])
        );

    if(event.xany.window==dialogs[dialogType_exit]&&event.type==Expose){
      XDrawString(
        display,
        dialogs[dialogType_exit],
        dialogsGCs[dialogType_exit],
        20,
        20,
        "Sei sicuro di voler uscire?",
        sizeof "Sei sicuro di voler uscire?"-1
      );
    }

    if(event.xany.window==dialogs[dialogType_options]&&event.type==Expose){
      const char*optionsTextes[3]={"Volume:","Musica:","Suoni:"};
      for(unsigned int optionIndex=0;optionIndex<3;optionIndex++)
        XDrawString(
          display,
          dialogs[dialogType_options],
          dialogsGCs[dialogType_options],
          20,
          20+20*(optionIndex+1),
          optionsTextes[optionIndex],
          strlen(optionsTextes[optionIndex])
        );
    }

    if(event.xany.window==dialogs[dialogType_moreInformation]&&event.type==Expose){
      XDrawString(
        display,
        dialogs[dialogType_moreInformation],
        dialogsGCs[dialogType_moreInformation],
        20,
        20,
        "Hardware Information:",
        sizeof "Hardware Information:"-1
      );
      const char*moreInformationTextes[3]={cpu,os,byteOrder};
      for(unsigned int moreInformationIndex=0;moreInformationIndex<3;moreInformationIndex++)
        XDrawString(
          display,
          dialogs[dialogType_moreInformation],
          dialogsGCs[dialogType_moreInformation],
          40,
          20+20*(moreInformationIndex+1),
          moreInformationTextes[moreInformationIndex],
          strlen(moreInformationTextes[moreInformationIndex])
        );
      XDrawString(
        display,
        dialogs[dialogType_moreInformation],
        dialogsGCs[dialogType_moreInformation],
        20,
        20+20*(3+1),
        "Software Information:",
        sizeof "Software Information:"-1
      );
      XDrawString(
        display,
        dialogs[dialogType_moreInformation],
        dialogsGCs[dialogType_moreInformation],
        40,
        20+20*(4+1),
        compiler,
        sizeof compiler-1
      );
    }

    //main window on resize
    if(event.xany.window==mainWindow&&event.type==ResizeRequest){
      switch(event.type){
        case ClientMessage:
          if((Atom)event.xclient.data.l == XInternAtom(display, "WM_DELETE_WINDOW", False))
            XSendEvent(display,mainScreenButtons[0][1],0,ButtonPressMask,&event);
          break;
        case ResizeRequest:
        
          for(dialogIndex=0;dialogIndex<5;dialogIndex++)
            XMoveResizeWindow(
              display,
              dialogs[dialogIndex],
              20,
              20,
              event.xresizerequest.width-40,
              event.xresizerequest.height-40
            );

          for(mainScreenButtonY=0;mainScreenButtonY<2;mainScreenButtonY++)
            for(mainScreenButtonX=0;mainScreenButtonX<2;mainScreenButtonX++){
              XMoveResizeWindow(
                display,
                mainScreenButtons[mainScreenButtonY][mainScreenButtonX],
                10+event.xresizerequest.width/2*mainScreenButtonX,
                10+event.xresizerequest.height/4*mainScreenButtonY+event.xresizerequest.height/2,
                event.xresizerequest.width/2-2*10,
                event.xresizerequest.height/4-2*10
              );
              XDrawString(
                display,
                mainScreenButtons[mainScreenButtonY][mainScreenButtonX],
                mainScreenButtonsGC,
                20,
                20,
                mainButtonTextes[mainScreenButtonY][mainScreenButtonX],
                strlen(mainButtonTextes[mainScreenButtonY][mainScreenButtonX])
              );
            }
          break;
      }
    }
    for(mainScreenButtonY=0;mainScreenButtonY<2;mainScreenButtonY++){
      for(mainScreenButtonX=0;mainScreenButtonX<2;mainScreenButtonX++){
        if(event.xany.window==mainScreenButtons[mainScreenButtonY][mainScreenButtonX]&&!readBit<unsigned char>(generalPurposeMask,generalPurposeMaskBits_dialogBindToWindow)){
          switch(event.type){
            case Expose:
              XDrawString(
                display,
                mainScreenButtons[mainScreenButtonY][mainScreenButtonX],
                mainScreenButtonsGC,
                20,
                20,
                mainButtonTextes[mainScreenButtonY][mainScreenButtonX],
                strlen(mainButtonTextes[mainScreenButtonY][mainScreenButtonX])
              );
              break;
            case ButtonPress:
              XDrawString(
                display,
                mainScreenButtons[mainScreenButtonY][mainScreenButtonX],
                mainScreenButtonsGC,
                20,
                20,
                mainButtonTextes[mainScreenButtonY][mainScreenButtonX],
                strlen(mainButtonTextes[mainScreenButtonY][mainScreenButtonX])
              );
              beep(1000,100);
              XMapRaised(display,dialogs[((mainScreenButtonY<<1)|mainScreenButtonX)+1]);
              XMapSubwindows(display,dialogs[((mainScreenButtonY<<1)|mainScreenButtonX)+1]);
              break;
            case EnterNotify:
              XSetWindowBackground(display,mainScreenButtons[mainScreenButtonY][mainScreenButtonX],~(mainScreenButtonsAttributes.background_pixel<<1));
              XClearWindow(display,mainScreenButtons[mainScreenButtonY][mainScreenButtonX]);
              XDrawString(
                display,
                mainScreenButtons[mainScreenButtonY][mainScreenButtonX],
                mainScreenButtonsGC,
                20,
                20,
                mainButtonTextes[mainScreenButtonY][mainScreenButtonX],
                strlen(mainButtonTextes[mainScreenButtonY][mainScreenButtonX])
              );
              break;
            case LeaveNotify:
              XSetWindowBackground(display,mainScreenButtons[mainScreenButtonY][mainScreenButtonX],255);
              XClearWindow(display,mainScreenButtons[mainScreenButtonY][mainScreenButtonX]);
              XDrawString(
                display,
                mainScreenButtons[mainScreenButtonY][mainScreenButtonX],
                mainScreenButtonsGC,
                20,
                20,
                mainButtonTextes[mainScreenButtonY][mainScreenButtonX],
                strlen(mainButtonTextes[mainScreenButtonY][mainScreenButtonX])
              );
              break;
          }
        }
      }
    }

    for(soundSliderIndex=0;soundSliderIndex<3;soundSliderIndex++){
      if(event.xany.window==soundSliders[soundSliderIndex]&&event.type==ButtonPress){
        XClearWindow(display,soundSliders[soundSliderIndex]);
        XFillRectangle(
          display,
          soundSliders[soundSliderIndex],
          soundSliderGC,
          0,
          0,
          event.xbutton.x,
          20
        );
      }
    }

    for(dialogIndex=0;dialogIndex<5;dialogIndex++){
      const char*dialogButtonsTextes[2]={"OK","Cancel"};
      for(dialogButtonsIndex=0;dialogButtonsIndex<2;dialogButtonsIndex++){
        if(event.xany.window==dialogButtons[dialogIndex][dialogButtonsIndex]&&event.type==ButtonPress){
          XUnmapWindow(display,dialogs[dialogIndex]);
          if(dialogIndex==dialogType_exit&&dialogButtonsIndex==0)generalPurposeMask=clearBit<unsigned char>(generalPurposeMask,0);
        }
        if(event.xany.window==dialogButtons[dialogIndex][dialogButtonsIndex]&&event.type==Expose){
          XDrawString(
            display,
            dialogButtons[dialogIndex][dialogButtonsIndex],
            dialogsGCs[dialogIndex],
            20,
            20,
            dialogButtonsTextes[dialogButtonsIndex],
            strlen(dialogButtonsTextes[dialogButtonsIndex])
          );
        }
        for(mainScreenButtonY=0;mainScreenButtonY<2;mainScreenButtonY++)
          for(mainScreenButtonX=0;mainScreenButtonX<2;mainScreenButtonX++)
            XDrawString(
              display,
              mainScreenButtons[mainScreenButtonY][mainScreenButtonX],
              mainScreenButtonsGC,
              20,
              20,
              mainButtonTextes[mainScreenButtonY][mainScreenButtonX],
              strlen(mainButtonTextes[mainScreenButtonY][mainScreenButtonX])
            );
      }
    }
    
    for(gameModeIndex=0;gameModeIndex<5;gameModeIndex++){
      if(event.xany.window==gameModeButton[gameModeIndex]&&event.type==ButtonPress){
        XClearWindow(display,dialogs[dialogType_play]);
        XSetForeground(display,gameModeGCs[gameModeIndex],gameModeGCValues[gameModeIndex].foreground);
        if(gameModeIndex<4){
          for(helpRechargeButtonIndex=0;helpRechargeButtonIndex<2;helpRechargeButtonIndex++){
            XUnmapWindow(display,helpRechargeButtons[helpRechargeButtonIndex]);
            XDrawString(
              display,
              dialogs[dialogType_play],
              gameModeGCs[gameMode_customized],
              20,
              20,
              &"+-"[helpRechargeButtonIndex],
              1
            );
          }
          for(gameModeInformationPoint=0;gameModeInformationPoint<3;gameModeInformationPoint++)
            XDrawString(
              display,
              dialogs[dialogType_play],
              gameModeGCs[gameModeIndex],
              20,
              screen->height/10+40+20*gameModeInformationPoint,
              modeInformation[gameModeIndex][gameModeInformationPoint],
              strlen(modeInformation[gameModeIndex][gameModeInformationPoint])
            );
        }
        else{
          XDrawString(
            display,
            dialogs[dialogType_play],
            gameModeGCs[gameMode_customized],
            20,
            screen->height/10+40,
            "Tempo di ricarica degli aiuti:",
            sizeof "Tempo di ricarica degli aiuti:"-1
          );
          XDrawString(
            display,
            dialogs[dialogType_play],
            gameModeGCs[gameMode_customized],
            20,
            screen->height/10+40+20,
            "Difficoltà enigmi:",
            sizeof "Difficoltà enigmi:"-1
          );
          for(helpRechargeButtonIndex=0;helpRechargeButtonIndex<2;helpRechargeButtonIndex++){
            XMapRaised(display,helpRechargeButtons[helpRechargeButtonIndex]);
            XDrawString(
              display,
              dialogs[dialogType_play],
              gameModeGCs[gameMode_customized],
              20,
              20,
              &"+-"[helpRechargeButtonIndex],
              1
            );
          }
        }
      }
    }

    if(event.xany.window==formSubmitButton&&event.type==ButtonPress){
      if(strcmp(userInput,"")==0||strcmp(userInput," ")==0)beep(1000,100);
      else{
        generalPurposeMask=clearBit<unsigned char>(generalPurposeMask,generalPurposeMaskBits_dialogBindToWindow);
        XUnmapSubwindows(display,form);
        XUnmapWindow(display,form);
        for(mainScreenButtonY=0;mainScreenButtonY<2;mainScreenButtonY++)
          for(mainScreenButtonX=0;mainScreenButtonX<2;mainScreenButtonX++)
            XDrawString(
              display,
              mainScreenButtons[mainScreenButtonY][mainScreenButtonX],
              mainScreenButtonsGC,
              20,
              20,
              mainButtonTextes[mainScreenButtonY][mainScreenButtonX],
              strlen(mainButtonTextes[mainScreenButtonY][mainScreenButtonX])
            );
        XDrawString(
          display,
          mainWindow,
          mainScreenButtonsGC,
          screen->width/4,
          screen->height/4,
          userInput,
          keyHandler.size
        );
      }
    }

    if(event.xany.window==form&&event.type==Expose){
      generalPurposeMask=setBit<unsigned char>(generalPurposeMask,generalPurposeMaskBits_dialogBindToWindow);
      XDrawString(
        display,
        formSubmitButton,
        userInputGC,
        5,
        10,
        "Invia",
        5
      );

      for(mainScreenButtonY=0;mainScreenButtonY<2;mainScreenButtonY++)
        for(mainScreenButtonX=0;mainScreenButtonX<2;mainScreenButtonX++){
          XDrawString(
            display,
            mainScreenButtons[mainScreenButtonY][mainScreenButtonX],
            mainScreenButtonsGC,
            20,
            20,
            mainButtonTextes[mainScreenButtonY][mainScreenButtonX],
            strlen(mainButtonTextes[mainScreenButtonY][mainScreenButtonX])
          );
        }
    }
    if(event.xany.window==formTextBox){
      switch(event.type){
        case FocusIn:
          puts("Focus In!");
          break;
        case FocusOut:
          puts("Focus Out!");
          break;
        case KeyPress:
          char trueKey=(char)XkbKeycodeToKeysym(
            display,//X display
            event.xkey.keycode,//key event key code
            0,//key group
            readBit<unsigned char>(event.xkey.state,ShiftMapIndex)^
            readBit<unsigned char>(event.xkey.state,LockMapIndex)//key level
          );
          //Mod2=Alt
          switch(event.xkey.keycode){
            case 22://Backspace key case
              if(keyHandler.pointer==0)
                beep(1000,100);
              else{
                keyHandler.pointer-=1;
                for(unsigned char I=keyHandler.pointer;userInput[I]!=0;I++)
                  userInput[I]=userInput[I+1];
                keyHandler.size-=1;
              }
              break;
            case 113://LeftArrow key case
              if(keyHandler.pointer==0)beep(1000,100);
              else keyHandler.pointer-=1;
              break;
            case 114://RightArrow key case
              if(keyHandler.pointer<keyHandler.size)keyHandler.pointer+=1;
              else beep(1000,100);
              break;
            case 66://Caps_lock key case
            case 62://left shift key case
            case 50://right shift key case
              beep(1000,100);
              break;
            case 119://canc key case
              if(keyHandler.pointer<keyHandler.size){
                for(unsigned char I=keyHandler.pointer;userInput[I]!=0;I++)
                  userInput[I]=userInput[I+1];
                keyHandler.size-=1;
              }else
                beep(1000,100);
              break;
            default:
              if(keyHandler.size==40)
                beep(1000,100);
              else{
                keyHandler.size+=1;
                for(unsigned char I=keyHandler.size;I>keyHandler.pointer;I--)
                  userInput[I]=userInput[I-1];
                userInput[keyHandler.pointer]=trueKey;
                keyHandler.pointer+=1;
              }
              break;
          }
          XClearWindow(display,formTextBox);
          XDrawString(
            display,
            formTextBox,
            userInputGC,
            20,
            20,
            userInput,
            keyHandler.size
          );
          break;
      }
    }
  }
  CleanImageData(background.r2);
  CleanImageData(logo.r2);
  XFreeGC(display,soundSliderGC);
  XFreeGC(display,userInputGC);
  for(dialogIndex=0;dialogIndex<5;dialogIndex++){
    XFreeGC(display,dialogsGCs[dialogIndex]);
    XDestroySubwindows(display,dialogs[dialogIndex]);
    XDestroyWindow(display,dialogs[dialogIndex]);
  }
  for(gameModeIndex=0;gameModeIndex<5;gameModeIndex++)if(gameModeGCs[gameModeIndex])XFreeGC(display,gameModeGCs[gameModeIndex]);
  XFreeGC(display,mainScreenButtonsGC);
  XDestroySubwindows(display,mainWindow);
  XDestroyWindow(display,mainWindow);
  XCloseDisplay(display);
  XFreeThreads();
  return 0;
}
#endif
