import AppKit
import AVKit

class application
{
  public var argc: Int32
  public var argv: UnsafeMutablePointer<UnsafeMutablePointer<Int8>?>
  public let nextStepApplication: NSApplication! = NSApplication.shared
  public let delegate: NSApplicationDelegate = applicationDelegate()
  public var icon: NSImage!
  init(argc: Int, argc: UnsafeMutablePointer<UnsafeMutablePointer<Int8>?>)
  {
    self.argc = argc
    self.argv = argv
    
    self.nextStepApplication.delegate = self.delegate
    self.nextStepApplication.setActivationPolicy(.regular)
    self.icon = NSImage(contentsOfFile: "bin/blob/image/icons/RegySpecial.ico")
    
    if self.icon == nil
    {
      errorMessage("Application image is \(a.applicationIconImage): Not Found!")
      self.nextStepApplication.terminate(nil)
    }
    
    self.nextStepApplication.applicationIconImage = self.icon
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
      contentRect: CGRect(x: 0, y: 0, width: NSScreen.main?.width, height: NSScreen.main?.height),
      styleMask: [.titled, .closable, .miniaturizable, .resizable],
      backing: .buffered,
      defer: true,
      screen: Screen.main
    )
    self.win.title = "Vaffanculo"
    self.win.setIsVisible(true)
    self.win.makeKeyAndOrderFront(nil)
    self.winDelegate = windowDelegate()
    self.win.delegate = self.winDelegate
    self.win.backgroundColor = NSColor(red: 1, green: 0, blue: 0)

    let button: NSButton = NSButton(title: "Morte Bianca")
    self.win.contentView?.addSubview(button)
  }
}

let a: NSApplication! = NSApplication.shared
let appDelegate = applicationDelegate()
a.delegate = appDelegate
a.setActivationPolicy(.regular)
a.applicationIconImage = NSImage(contentsOfFile: "bin/blob/image/icons/RegySpecial.ico")
if a.applicationIconImage == nil
{
  errorMessage("Application image at file system path \(a.applicationIconImage) has not been found!")
  a.terminate(nil)
}

do
{
  let avplayer: AVPlayer? = AVPlayer(url: soundSource)
  if avplayer == nil
  {
    errorMessage("Cannot start AVPlayer and play bin/blob/audio/music/co.ag/Still_so_much_Rage_-_Dark_Ambient_Music.mp3\n")
    NSApp.terminate(nil)
  }
  avplayer?.play()
}
catch
{
  errorMessage("Cannot start AVPlayer and play bin/blob/audio/music/co.ag/Still_so_much_Rage_-_Dark_Ambient_Music.mp3\n")
  NSApp.terminate(nil)
}

a.run()
