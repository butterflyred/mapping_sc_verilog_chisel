module Hello(
  input        clock,
  input        io_rst,
  output [7:0] io_out
);
  wire [5:0] _GEN_0; // @[Hello.scala 12:17]
  assign _GEN_0 = io_rst ? 6'h7 : 6'h2a; // @[Hello.scala 12:17]
  assign io_out = {{2'd0}, _GEN_0}; // @[Hello.scala 13:10 Hello.scala 16:10]
endmodule
