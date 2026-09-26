import AppKit

class applicationDelegate
:
NSObject,
NSApplicationDelegate
{
  var win: NSWindow!
  var mainWin: mainWindow!
  var winDelegate: windowDelegate!
  public func applicationDidFinishLaunching(_ applicationDidFinishLaunchingNotification: Notification)
  {
    self.win = NSWindow(
      contentRect: CGRect(x: 0, y: 0, width: 500, height: 500),
      styleMask: [.titled, .closable, .miniaturizable, .resizable],
      backing: .buffered,
      defer: true
    )
    self.win.title = "Vaffanculo"
    self.win.setIsVisible(true)
    self.win.makeKeyAndOrderFront(nil)
    self.winDelegate = windowDelegate()
    self.win.delegate = self.winDelegate
  }
}