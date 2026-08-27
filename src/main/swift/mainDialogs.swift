public class dialog: commonWidgetInterface {
  var id:(NSPanel?,NSWindow?)
  init(_ root:mainWindow,_ type:UInt8){
    self.root = root
    self.type = type
    self.x = 20
    self.y = 20
    self.width = self.root.width - 40
    self.height = self.root.height - 40
    let titles:[String] = {
      "layoutMode",
      "Play",
      "Exit",
      "Options",
      "More information"
    };
    let dialogColors:[UInt32]={
      255,
      255<<8,
      255<<16,
      0xffff,
      0xffffff
    };
    self.background = backgroundStruct()
    self.border = borderStruct(1, 0xffffff)
    self.id.0 = NSPanel() ?? nil
    self.id.1 = NSWindow
                (
                  contentRect:NSRect(x:20,y:20,width:self.frame.width-40,height:self.frame.height-40),
                  styleMask:[.titled,.closable,.resizable,.miniaturizable],
                  backing:.buffered,
                  defer:true
                )
    self.title = self.root.title
    self.id?.0.setIsVisible(true)
    self.id?.1.setIsVisible(true)
    XMapRaised(self.root.display,self.id);
    XGCValues gcValues={
      .foreground=(self.text.color=dialogColors[self.type])
    };
    self.graphicId=XCreateGC(self.root.display,self.id,(self.graphicMask=GCForeground),&gcValues);
    XMapRaised(self.root.display,self.id);
    XMapSubwindows(self.root.display,self.id);
  }
}