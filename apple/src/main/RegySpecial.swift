/*
Main entry point of the videogame (Apple Operating Systems)
*@author Regy Special
*@date (First version [MacOS]) 2026 January 19th Monday, 17:55:46
*@license GNU General Public License to stop private corporation to not share source code
*/
#if os(macOS)
import Cocoa
class Window:NSWindow{
  let text:NSTextView=NSTextView(frame:NSRect(x:0,y:0,width:100,height:100))
  var gameMode:UInt8=0

  //form components
  let textBox:NSTextField=NSTextField(labelWithString:"inserire il nome utente")
  var submitButton:NSButton!
  var form:NSStackView!
  @objc func handleGameMode(){
    print("coso")
  }
  @objc override func close(){
    appShare.terminate(appShare)
  }
  @objc func playDialog(){
    let PlayDialog:NSWindow=NSWindow(
      contentRect:NSRect(x:20,y:20,width:self.frame.width-40,height:self.frame.height-40),
      styleMask:[.titled,.closable,.resizable,.miniaturizable],
      backing:.buffered,
      defer:true
    )
    PlayDialog.title="Gioca"
    text.string="Difficoltà gioco"
    let simpleModeButton:NSButton=NSButton(
      title:"Semplice",
      target:self,
      action:#selector(self.handleGameMode)
    )
    let intermediateModeButton:NSButton=NSButton(
      title:"Intermedia",
      target:self,
      action:#selector(self.handleGameMode)
    )
    let advancedModeButton:NSButton=NSButton(
      title:"Avanzata",
      target:self,
      action:#selector(self.handleGameMode)
    )
    let extremeModeButton:NSButton=NSButton(
      title:"Estrema",
      target:self,
      action:#selector(self.handleGameMode)
    )
    let dialogConfirmButton:NSButton=NSButton(
      title:"Conferma",
      target:PlayDialog,
      action:#selector(PlayDialog.close)//close play dialog
    )
    let dialogCancelButton:NSButton=NSButton(
      title:"Non confermare",
      target:PlayDialog,
      action:#selector(PlayDialog.close)//close play dialog
    )
    PlayDialog.setIsVisible(true)
    PlayDialog.makeKeyAndOrderFront(self)
    PlayDialog.contentView?.addSubview(text)
    PlayDialog.contentView?.addSubview(simpleModeButton)
    PlayDialog.contentView?.addSubview(intermediateModeButton)
    PlayDialog.contentView?.addSubview(advancedModeButton)
    PlayDialog.contentView?.addSubview(extremeModeButton)
    PlayDialog.contentView?.addSubview(dialogCancelButton)
    PlayDialog.contentView?.addSubview(dialogConfirmButton)
  }
  @objc func showIntro(){
    let ButtonGrid:[[String:Selector]]=[
      [
        "Play":#selector(self.playDialog),
        "Exit":#selector(self.close)
      ],
      [
        "Options":#selector(self.playDialog),//optionsDialog
        "More Information":#selector(self.playDialog)//moreInformationDialog
      ]
    ]
    let GridLayout:NSGridView=NSGridView(views:ButtonGrid.map{
      dict in ButtonGrid
      return dict.keys.map{
        let Button:NSButton=NSButton(
          title:$0,
          target:self, 
          action:dict[$0]!
        )
        Button.contentTintColor=NSColor(red:0,green:0,blue:1,alpha:0)
        return Button
      }
    })
    GridLayout.frame=self.frame
    self.backgroundColor=NSColor(red:0,green:0,blue:0,alpha:1)
    self.contentView?.replaceSubview(self.form,with:GridLayout);
    self.update()
  }
}
class ApplicationDelegate:NSObject,NSApplicationDelegate{
  let window:Window=Window(
    contentRect:NSRect(x:0,y:0,width:1080,height:540),
    styleMask:[.titled,.closable,.resizable,.miniaturizable],
    backing:.buffered,
    defer:true,
    screen:NSScreen.main
  )
  func applicationDidFinishLaunching(_ aNotification:Notification){
    self.window.setIsVisible(true)
    self.window.title="RegySpecial"
    if CommandLine.argc==1{
      self.window.submitButton=NSButton(
        title:"Invia",
        target:self.window,
        action:#selector(self.window.showIntro)
      )
      self.window.textBox.textColor=NSColor(red:0,green:1,blue:0,alpha:1)
      self.window.textBox.backgroundColor=NSColor(red:0,green:0,blue:0,alpha:1)
      self.window.form=NSStackView(views:[self.window.textBox,self.window.submitButton])
      self.window.form.orientation=NSUserInterfaceLayoutOrientation.vertical
      self.window.form.frame=NSRect(
        x:0,
        y:0,
        width:self.window.frame.width,
        height:self.window.frame.height
      );
      self.window.contentView?.addSubview(window.form)
    }
  }
}
if CommandLine.argc==1{
  let programLocation:URL=URL(
    fileURLWithFileSystemRepresentation:CommandLine.arguments[0],
    isDirectory:false,
    relativeTo:nil
  )
  let helpProcess:Process=try Process.run(programLocation,arguments:["help"])
}else{
  manageArguments(CommandLine.argc,CommandLine.unsafeArgv)
  let appShare=NSApplication.shared
  let appDelegate=ApplicationDelegate()
  appShare.delegate=appDelegate
  appShare.run()
}
#endif
