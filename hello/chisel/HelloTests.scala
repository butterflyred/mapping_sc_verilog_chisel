// See LICENSE.txt for license details.
package solutions

import chisel3.iotesters.PeekPokeTester

class HelloTests(c: Hello) extends PeekPokeTester(c) {
  // for (reset <- 0 until 2) {
  //     step(1)
  //     poke(c.io.rst, reset)
  //     expect(c.io.out,  if (reset == 1) 7 else 42)
  // }

      step(1)
      var reset = 1
      poke(c.io.rst, reset)
      expect(c.io.out,  if (reset == 1) 7 else 42)
      step(1)
      reset = 0
      poke(c.io.rst, reset)
      expect(c.io.out,  if (reset == 1) 7 else 42)
      step(1)
      reset = 1
      poke(c.io.rst, reset)
      expect(c.io.out,  if (reset == 1) 7 else 42)
      step(1)
      reset = 0
      poke(c.io.rst, reset)
      expect(c.io.out,  if (reset == 1) 7 else 42)
      step(1)

}
