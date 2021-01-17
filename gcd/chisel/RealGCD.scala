// See LICENSE.txt for license details.
package solutions

import chisel3._
import chisel3.util.{Valid, DeqIO}

// Problem:
// Implement a GCD circuit (the greatest common divisor of two numbers).
// Input numbers are bundled as 'RealGCDInput' and communicated using the Decoupled handshake protocol
//
class RealGCDInput extends Bundle {
  val a = UInt(16.W)
  val b = UInt(16.W)
}

class RealGCD extends Module {
  val io  = IO(new Bundle {
    val in  = DeqIO(new RealGCDInput())
    val out = Output(Valid(UInt(16.W)))
  })

  val a = Reg(UInt())
  val b = Reg(UInt())
  val p = RegInit(false.B)

  io.in.ready := !p

  when (io.in.valid && !p) {
    a := io.in.bits.a
    b := io.in.bits.b
    p := true.B
  } 

  when (p) { // p=T => start computing
    when (a > b)  { a := b; b := a } // swap 
    .otherwise    { b := b - a }
  }

  io.out.bits  := a
  io.out.valid := b === 0.U && p // when (b=0 & computing )=> valid = T 
  when (io.out.valid) { // valid = T => stop computing
    p := false.B // p=F => stop computing
  }
}
