public class mainScreenButton:commonWidgetInterface {
  public var id:NSButton!
  public var root:mainWindow
  @objc public func onButtonDown(){
    NSSound.beep()
    if self.text.value == "Exit"
    {
      self.root.application.terminate()
    }
  } 
  init(_ root:mainWindow,_ text:String){
    self.root = root
    let nsfont:NSFont = NSFont(fontName: "Helvatica Neue", fontSize: 10)
    self.text = textStruct(text, 20, 20, fontStruct(nsfont.familyName, nsfont.Weight.regular))
    self.id = NSButton
    (
      title:self.text.value,
      target:self.id,
      action:#selector(self.onButtonDown)
    )
  }
}