/*
*@description Main entry point of the videogame
*@author Regy Special
*@date (First version [Linux]) 2026 July 19th Sunday, 15:46:00
*@license GNU General Public License to stop private corporation to not share source code
*/
#include "../../include/main/c++/mainDialogs.hpp"

dialog::dialog(mainWindow*root,unsigned char type){
  this->root=root;
  this->type=type;
  this->x=20;
  this->y=20;
  this->width=this->root->width-40;
  this->height=this->root->height-40;
  XSizeHints dimensionConfiguration={
    .x=this->x,
    .y=this->y,
    .max_width=this->width,
    .max_height=this->height
  };
  const char*titles[]={
    "layoutMode",
    "Play",
    "Exit",
    "Options",
    "More information"
  };
  unsigned long dialogColors[]={
    255,
    255<<8,
    255<<16,
    0xffff,
    0xffffff
  };
  XSetWindowAttributes dialogAttributes={
    .background_pixel=this->background.color,
    .border_pixel=this->border.color,
    .event_mask=this->eventMask
  };
  this->id=XCreateWindow(
    this->root->display,
    this->root->id,
    this->x,
    this->y,
    this->width,
    this->height,
    this->border.width,
    this->root->visualInfo.depth,
    this->root->visualInfo.c_class,
    this->root->visualInfo.visual,
    this->attributeMask,
    &dialogAttributes
  );
  XSetStandardProperties(
    this->root->display,
    this->id,
    (this->title=titles[this->type]),
    NULL,
    0,
    this->root->argv,
    this->root->argc,
    &dimensionConfiguration
  );
  XMapRaised(this->root->display,this->id);
  XGCValues gcValues={
    .foreground=(this->text.color=dialogColors[this->type])
  };
  this->graphicId=XCreateGC(this->root->display,this->id,(this->graphicMask=GCForeground),&gcValues);
  XMapRaised(this->root->display,this->id);
  XMapSubwindows(this->root->display,this->id);
}
dialog::~dialog(){
  XFreeGC(this->root->display,this->graphicId);
  XDestroySubwindows(this->root->display,this->id);
}
void dialog::onClientMessage(XClientMessageEvent*event,void*extraArgs){
  if((Atom)event->data.l == XInternAtom(this->root->display, "WM_DELETE_WINDOW", 0))
    XUnmapWindow(this->root->display,this->id);
}
void dialog::onExpose(XExposeEvent*event,void*extraArgs){
  const char
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
  switch(this->type){
    case dialogType_layoutMode:
      XDrawString(
        this->root->display,
        this->id,
        this->graphicId,
        20,
        20,
        "Dialogo aperto, scegliere la modalità",
        sizeof "Dialogo aperto, scegliere la modalità"-1
      );
      break;
    case dialogType_play:
      for(unsigned char gameModeInformationPoint=0;gameModeInformationPoint<3;gameModeInformationPoint++)
        XDrawString(
          this->root->display,
          this->id,
          this->graphicId,
          20,
          this->root->height/10+40+20*gameModeInformationPoint,
          modeInformation[0][gameModeInformationPoint],
          strlen(modeInformation[0][gameModeInformationPoint])
        );
      break;
    case dialogType_exit:
      XDrawString(
        this->root->display,
        this->id,
        this->graphicId,
        20,
        20,
        "Sei sicuro di voler uscire?",
        sizeof "Sei sicuro di voler uscire?"-1
      );
      break;
    case dialogType_options:
      const char*optionsTextes[3]={"Volume:","Musica:","Suoni:"};
      for(unsigned char optionIndex=0;optionIndex<3;optionIndex++)
        XDrawString(
          this->root->display,
          this->id,
          this->graphicId,
          20,
          20+20*(optionIndex+1),
          optionsTextes[optionIndex],
          strlen(optionsTextes[optionIndex])
        );
      break;
    case dialogType_moreInformation:
      XDrawString(
        this->root->display,
        this->id,
        this->graphicId,
        20,
        20,
        "Hardware Information:",
        sizeof "Hardware Information:"-1
      );
      const char*moreInformationTextes[3]={cpu,os,byteOrder};
      for(unsigned int moreInformationIndex=0;moreInformationIndex<3;moreInformationIndex++)
        XDrawString(
          this->root->display,
          this->id,
          this->graphicId,
          40,
          20+20*(moreInformationIndex+1),
          moreInformationTextes[moreInformationIndex],
          strlen(moreInformationTextes[moreInformationIndex])
        );
      XDrawString(
        this->root->display,
        this->id,
        this->graphicId,
        20,
        20+20*(3+1),
        "Software Information:",
        sizeof "Software Information:"-1
      );
      XDrawString(
        this->root->display,
        this->id,
        this->graphicId,
        40,
        20+20*(4+1),
        compiler,
        sizeof compiler-1
      );
      break;
  }
}