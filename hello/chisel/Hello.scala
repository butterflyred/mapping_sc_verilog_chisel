// See LICENSE.txt for license details.
package solutions

import chisel3._


class Hello extends Module {
  val io = IO(new Bundle {
    val rst = Input(Bool())
    val out = Output(UInt(8.W))
  })
  when (io.rst) {
  io.out := 7.U

  } .otherwise {
  io.out := 42.U

  }
}

