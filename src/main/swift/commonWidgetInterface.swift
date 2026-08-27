import AppKit

public struct borderStruct {
  public var width:UInt32 = 1
  public var color:UInt64 = 0xffffff
  public init(_ width:UInt32 = 1, _ color:UInt64 = 0xffffff)
  {
    self.width = width
    self.color = color
  }
}

public struct backgroundStruct {
  public var color:UInt64 = 0xffffff
  public var x:UInt32 = 0
  public var y:UInt32 = 0
  public var width:Int32 = 0
  public var height:Int32 = 0
  public init
  (
    _ color:UInt64 = 0xffffff
    _ x:UInt32 = 0
    _ y:UInt32 = 0
    _ width:Int32 = 0
    _ height:Int32 = 0
  )
  {
    self.color = 0xffffff
    self.x = 0
    self.y = 0
    self.width = 0
    self.height = 0
  }
}

public struct fontStruct {
  public var family:String
  public var size:UInt32 = 10
  public var weight:UInt32
  public init
  (
    _ family:String
    _ size:UInt32 = 10
    _ weight:UInt32
  )
  {
    self.family = family
    self.size = size
    self.weight = weight
  }
}

public struct textStruct {
  public var value:String
  public var x:UInt32 = 0
  public var y:UInt32 = 0
  public var width:Int32 = 0
  public var height:Int32 = 0
  public var font:fontStruct
  public init
  (
    _ value:String?
    _ x:UInt32 = 0
    _ y:UInt32 = 0
    _ width:Int32 = 0
    _ height:Int32 = 0
    _ font:fontStruct?
  )
  {
    self.value = value
    self.x = x
    self.y = y
    self.width = width
    self.height = height
    self.font = font
  }
}

public protocol commonWidgetInterface {
  var x:UInt8=0
  var y:UInt8=0
  var width:Int=0
  var height:Int=0
  var title:String
  var subWindows:[NSView]
  var border:borderStruct
  var background:backgroundStruct
  var text:textStruct
  func show(_ microseconds:UInt32) -> Int;
  func hide(_ microseconds:UInt32) -> Int;
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