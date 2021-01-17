module RealGCD(
  input         clock,
  input         reset,
  output        io_in_ready,
  input         io_in_valid,
  input  [15:0] io_in_bits_a,
  input  [15:0] io_in_bits_b,
  output        io_out_valid,
  output [15:0] io_out_bits
);
  reg [15:0] a; // @[RealGCD.scala 22:14]
  reg [31:0] _RAND_0;
  reg [15:0] b; // @[RealGCD.scala 23:14]
  reg [31:0] _RAND_1;
  reg  p; // @[RealGCD.scala 24:18]
  reg [31:0] _RAND_2;
  
  wire  _T_30; // @[RealGCD.scala 26:18]
  wire  _T_33; // @[RealGCD.scala 28:21]
  wire [15:0] _GEN_0; // @[RealGCD.scala 28:28]
  wire [15:0] _GEN_1; // @[RealGCD.scala 28:28]
  wire  _GEN_2; // @[RealGCD.scala 28:28]
  wire  _T_35; // @[RealGCD.scala 35:13]
  wire [16:0] _T_36; // @[RealGCD.scala 36:28]
  wire [16:0] _T_37; // @[RealGCD.scala 36:28]
  wire [15:0] _T_38; // @[RealGCD.scala 36:28]
  wire [15:0] _GEN_3; // @[RealGCD.scala 35:19]
  wire [15:0] _GEN_4; // @[RealGCD.scala 35:19]
  wire  _T_40; // @[RealGCD.scala 40:21]
  wire  _GEN_7; // @[RealGCD.scala 41:23]
  
  assign _T_30 = p == 1'h0; // @[RealGCD.scala 26:18]
  assign _T_33 = io_in_valid & _T_30; // @[RealGCD.scala 28:21]
  assign _GEN_0 = _T_33 ? io_in_bits_a : a; // @[RealGCD.scala 28:28]
  assign _GEN_1 = _T_33 ? io_in_bits_b : b; // @[RealGCD.scala 28:28]
  assign _GEN_2 = _T_33 ? 1'h1 : p; // @[RealGCD.scala 28:28]
  assign _T_35 = a > b; // @[RealGCD.scala 35:13]
  assign _T_36 = b - a; // @[RealGCD.scala 36:28]
  assign _T_37 = $unsigned(_T_36); // @[RealGCD.scala 36:28]
  assign _T_38 = _T_37[15:0]; // @[RealGCD.scala 36:28]
  assign _GEN_3 = _T_35 ? b : _GEN_0; // @[RealGCD.scala 35:19]
  assign _GEN_4 = _T_35 ? a : _T_38; // @[RealGCD.scala 35:19]
  assign _T_40 = b == 16'h0; // @[RealGCD.scala 40:21]
  assign _GEN_7 = io_out_valid ? 1'h0 : _GEN_2; // @[RealGCD.scala 41:23]
  assign io_in_ready = p == 1'h0; // @[RealGCD.scala 26:15]
  assign io_out_valid = _T_40 & p; // @[RealGCD.scala 40:16]
  assign io_out_bits = a; // @[RealGCD.scala 39:16]

  always @(posedge clock) begin
    if (p) begin
      if (_T_35) begin
        a <= b;
      end else begin
        if (_T_33) begin
          a <= io_in_bits_a;
        end
      end
    end else begin
      if (_T_33) begin
        a <= io_in_bits_a;
      end
    end
    if (p) begin
      if (_T_35) begin
        b <= a;
      end else begin
        b <= _T_38;
      end
    end else begin
      if (_T_33) begin
        b <= io_in_bits_b;
      end
    end
    if (reset) begin
      p <= 1'h0;
    end else begin
      if (io_out_valid) begin
        p <= 1'h0;
      end else begin
        if (_T_33) begin
          p <= 1'h1;
        end
      end
    end
  end
endmodule
