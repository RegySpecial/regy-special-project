import AppKit

public struct borderStruct
{
  public var width: CGFloat = 1
  public var color: NSColor = NSColor(srgbRed: 1, green: 1, blue: 1, alpha: 1)
  public init(_ width: CGFloat = 1, _ color: NSColor = NSColor(srgbRed: 1, green: 1, blue: 1, alpha: 1))
  {
    self.width = width
    self.color = color
  }
}

public struct backgroundStruct
{
  public var color:  NSColor = NSColor(srgbRed: 1, green: 1, blue: 1, alpha: 1)
  public var x:      Double = 0
  public var y:      Double = 0
  public var width:  Double = 0
  public var height: Double = 0
  public init
  (
    _ color:  NSColor = NSColor(srgbRed: 1, green: 1, blue: 1, alpha: 1)
    _ x:      Double = 0
    _ y:      Double = 0
    _ width:  Double = 0
    _ height: Double = 0
  )
  {
    self.color = color
    self.x = x
    self.y = y
    self.width = width
    self.height = height
  }
}

public struct fontStruct
{
  public var family: String
  public var size: UInt32 = 10
  public var weight: UInt32
  public init
  (
    _ family: String
    _ size: UInt32 = 10
    _ weight: UInt32
  )
  {
    self.family = family
    self.size = size
    self.weight = weight
  }
}

public struct textStruct
{
  public var value: String
  public var x: Double = 0
  public var y: Double = 0
  public var font: fontStruct
  public init
  (
    _ value: String?
    _ x: Double = 0
    _ y: Double = 0
    _ font:fontStruct?
  )
  {
    self.value = value
    self.x = x
    self.y = y
    self.font = font
  }
}

public protocol commonWidgetInterface
{
  var x:      Double
  var y:      Double
  var width:  Double
  var height: Double  
  var title: String
  var subWindows: [NSView]
  var border: borderStruct
  var background: backgroundStruct
  var text: textStruct
  func show(_ microseconds: UInt32) -> Int;
  func hide(_ microseconds: UInt32) -> Int;
  @objc mutating func onClientMessage()
  @objc mutating func onResize()
  @objc mutating func onButtonUp()
  @objc mutating func onButtonDown()
  @objc mutating func onKeyUp()
  @objc mutating func onKeyDown()
  @objc mutating func onExpose()
  @objc mutating func onPointerIn()
  @objc mutating func onPointerOut()
  @objc mutating func onPointerMove()
  @objc mutating func onFocusIn()
  @objc mutating func onFocusOut()
  @objc mutating func onAny()
}