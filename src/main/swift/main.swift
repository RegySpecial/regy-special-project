/*
*@description Main entry point of the videogame (Apple Operating Systems)
*@author Regy Special
*@date (First version [MacOS]) 2026 January 19th Monday, 17:55:46
*@license GNU General Public License to stop private corporation to not share source code
*/
#if os(macOS)
public class ApplicationDelegate:NSObject,NSApplicationDelegate{
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

  //manageArguments C function from src/main/c/manageArguments.c
  var gameCtxtStruct:gameContextStructure = manageCommandLineArguments(CommandLine.argc,CommandLine.unsafeArgv)
  let appShare=NSApplication.shared
  let appDelegate=ApplicationDelegate()
  appShare.delegate=appDelegate
  appShare.run()
}
#endif
