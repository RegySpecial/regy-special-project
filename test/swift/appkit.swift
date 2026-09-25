import AppKit

class windowDelegate
:
NSObject,
NSWindowDelegate
{
  func windowWillClose(_ a: Notification)
  {
    NSApp.terminate(nil)
  }
}

class applicationDelegate
:
NSObject,
NSApplicationDelegate
{
  var win: NSWindow!
  var winDelegate: windowDelegate!
  public func applicationDidFinishLaunching(_ a: Notification)
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

let a: NSApplication! = NSApplication.shared
let appDelegate = applicationDelegate()
a.delegate = appDelegate
a.setActivationPolicy(.regular)
a.applicationIconImage = NSImage(contentsOfFile: "bin/blob/image/icons/RegySpecial.ico")
if a.applicationIconImage == nil
{
  print("Application image is \(a.applicationIconImage): Not Found!")
  a.terminate(nil)
}
a.run()
