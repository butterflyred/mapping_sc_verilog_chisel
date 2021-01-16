// See LICENSE.txt for license details.
package solutions

import chisel3._


class Hello extends Module {
  val io = IO(new Bundle {
    val out = Output(UInt(8.W))
  })
  io.out := 42.U
}

