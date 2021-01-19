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
  reg [15:0] a;
  reg [15:0] b;
  reg  busy;
  wire  allow_enter;
  wire  gt;
  wire [15:0] sub;
  assign allow_enter = io_in_valid & !busy;
  assign gt = a > b;
  assign sub = b - a;
  assign io_in_ready = !busy;
  assign io_out_valid = (b == 16'h0) & busy;
  assign io_out_bits = a;

  always @(posedge clock) begin
    
    if (reset) begin
      a <= 16'h0;
    end else begin
      if (io_out_valid) begin
        a <= 16'h0;
      end else begin
        if (busy) begin
          if (gt) begin
            a <= b;
          end else begin
            if (allow_enter) begin
              a <= io_in_bits_a;
            end
          end
        end else begin
          if (allow_enter) begin
            a <= io_in_bits_a;
          end
        end
      end
    end
    
    if (reset) begin
      b <= 16'h0;
    end else begin
      if (io_out_valid) begin
        b <= 16'h0;
      end else begin
        if (busy) begin
          if (gt) begin
            b <= a;
          end else begin
            b <= sub;
          end
        end else begin
          if (allow_enter) begin
            b <= io_in_bits_b;
          end
        end
      end
    end
    
    if (reset) begin
      busy <= 1'h0;
    end else begin
      if (io_out_valid) begin
        busy <= 1'h0;
      end else begin
        if (allow_enter) begin
          busy <= 1'h1;
        end
      end
    end
  
  end
endmodule
