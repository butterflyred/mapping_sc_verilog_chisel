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

  val a = RegInit(UInt(0,16.W))
  val b = RegInit(UInt(0,16.W))
// *0
  val p = RegInit(false.B)

// *1
  when (io.in.valid && !p) { // equal always@(poesedge clk)
    a := io.in.bits.a // slow one cycle
    b := io.in.bits.b // slow one cycle
    p := true.B
  } 
// *2
  when (p) { // p=T => start computing
    when (a > b)  { a := b; b := a } // swap 
    .otherwise    { b := b - a }
  }
// *3
  io.in.ready  := !p // must setting 
  io.out.bits  := a
  io.out.valid := b === 0.U && p // when (b=0 & computing )=> valid = T 
// *4
  when (io.out.valid) { // valid = T => stop computing
    a := 0.U // slow one cycle
    b := 0.U // slow one cycle
    p := false.B // p=F => stop computing
  }
}
