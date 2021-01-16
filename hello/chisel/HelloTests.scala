// See LICENSE.txt for license details.
package solutions

import chisel3.iotesters.PeekPokeTester

class HelloTests(c: Hello) extends PeekPokeTester(c) {
  step(1)
  expect(c.io.out, 42)
}
