module Hello(
  input        clock,
  input        reset,
  output [7:0] io_out
);
  assign io_out = 8'h2a; // @[Hello.scala 11:10]
endmodule
