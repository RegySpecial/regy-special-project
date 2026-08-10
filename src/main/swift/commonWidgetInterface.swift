import AppKit

struct borderStruct {
  public var width:UInt32=1
  public var color:UInt64=0xffffff
}

struct backgroundStruct {
  public var color:UInt64=0xffffff
  public var x:UInt32=0
  public var y:UInt32=0
  public var width:Int32=0
  public var height:Int32=0
}

struct fontStruct {
  public var family:String
  public var size:UInt32
  public var weight:UInt32
}

struct textStruct {
  public var value:String
  public var x:UInt32=0
  public var y:UInt32=0
  public var width:Int32=0
  public var height:Int32=0
  public var font:fontStruct
}

protocol commonWidgetInterface {
  var x:UInt8=0
  var y:UInt8=0
  var width:Int=0
  var height:Int=0
  var title:String
  var subWindows:[NSView]
  var border:borderStruct
  var background:backgroundStruct
  var text:textStruct
}