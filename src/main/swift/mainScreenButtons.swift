public class mainScreenButton:commonWidgetInterface {
  public var id:NSButton!
  public var root:mainWindow
  @objc public func onButtonDown(){
    NSSound.beep()
  } 
  init(_ root:mainWindow,_ text:String){
    self.root=root
    self.text.value=text
    self.id=NSButton(
      title:self.text.value,
      target:self.id,
      action:#selector(self.onButtonDown)
    )
  }
}