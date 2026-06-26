@inlinable func setBit(data:BinaryInteger,position:UInt8)->BinaryInteger{
  data|1<<position
}
@inlinable func clearBit(data:BinaryInteger,position:UInt8)->BinaryInteger{
  data & ~(1<<position)
}
@inlinable func toggleBit(data:BinaryInteger,position:UInt8)->BinaryInteger{
  data^1<<position
}
@inlinable func clearBit(data:BinaryInteger,position:UInt8)->Bool{
  (data>>position&1)==1
}