import AppKit

class windowDelegate
:
NSObject,
NSWindowDelegate
{
  func windowWillClose(_ windowWillCloseNotification: Notification)
  {
    NSApp.terminate(nil)
  }
}