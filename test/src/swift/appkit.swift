import AppKit
import AVKit

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
    let screen: NSScreen = NSScreen.main as! NSScreen
    self.win = NSWindow(
      contentRect: CGRect(x: 0, y: 0, width: screen.frame.width, height: screen.frame.height),
      styleMask: [.titled, .closable, .miniaturizable, .resizable],
      backing: .buffered,
      defer: true,
      screen: screen
    )
    self.win.title = "Vaffanculo"
    self.win.setIsVisible(true)
    self.win.makeKeyAndOrderFront(nil)
    self.winDelegate = windowDelegate()
    self.win.delegate = self.winDelegate
    self.win.backgroundColor = NSColor(red: 1, green: 0, blue: 0, alpha: 1)

    let button: NSButton = NSButton(title: "Morte Bianca", target: nil, action: nil)
    let buttonCell: NSButtonCell = NSButtonCell(textCell: "Morte Bianca")
    buttonCell.backgroundColor = NSColor(red: 0, green: 0, blue: 1, alpha: 1)
    button.setButtonType(.onOff)
    button.cell = buttonCell
    button.isBordered = true
    button.bezelStyle = 
    button.contentTintColor = NSColor(red: 1, green: 0, blue: 0, alpha: 1)
    button.bezelColor = button.contentTintColor
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
  print("Application image is \(a.applicationIconImage): Not Found!")
  a.terminate(nil)
}

let soundSource = URL(fileURLWithPath: "bin/blob/audio/music/co.ag/Still_so_much_Rage_-_Dark_Ambient_Music.mp3")
let avplayer: AVPlayer = AVPlayer(url: soundSource)
if avplayer.error != nil
{
  print("Failed to play AVPlayer")
  a.terminate(nil)
}
avplayer.play()

a.run()
