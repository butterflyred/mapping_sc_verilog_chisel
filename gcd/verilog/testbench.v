`include "RealGCD.v"

module testbench;
reg bench_clk;
reg bench_rst;
reg bench_io_in_valid;
reg [15:0]bench_io_in_bits_a;
reg [15:0]bench_io_in_bits_b;
wire bench_io_in_ready;
wire bench_io_out_valid;
wire [15:0]bench_io_out_bits;


event e_clk;


initial begin
    $dumpfile("testbench.vcd");
    $dumpvars(0, dut);
    // $fsdbDumpfile("testbench.fsdb");
    // $fsdbDumpvars(0, dut);

end
initial
begin
#0 bench_clk = 1'b0;
end

always
begin
#10 bench_clk = !bench_clk;
->e_clk;
end

initial
begin
#0 bench_rst = 1'b1;
#20 bench_rst = 1'b0;
end

RealGCD dut(
.clock(bench_clk),
.reset(bench_rst),
.io_in_valid(bench_io_in_valid),
.io_in_bits_a(bench_io_in_bits_a),
.io_in_bits_b(bench_io_in_bits_b),
.io_in_ready(bench_io_in_ready),
.io_out_valid(bench_io_out_valid),
.io_out_bits(bench_io_out_bits)
);

initial
begin
$monitor($time, " reset = %b, clock = %b , io_in_valid = %b , io_in_bits_a = %b , io_in_bits_b = %b , io_in_ready = %b , io_out_valid = %b , io_out_bits = %b ",
bench_rst, bench_clk, bench_io_in_valid, bench_io_in_bits_a, bench_io_in_bits_b, bench_io_in_ready, bench_io_out_valid, bench_io_out_bits);
end

initial
begin
#40 
bench_io_in_valid = 1;
bench_io_in_bits_a = 48;
bench_io_in_bits_b = 32;
#20 bench_io_in_valid = 0;

#200 
bench_io_in_valid = 1;
bench_io_in_bits_a = 7;
bench_io_in_bits_b = 3;
#20 bench_io_in_valid = 0;

#200 
bench_io_in_valid = 1;
bench_io_in_bits_a = 100;
bench_io_in_bits_b = 10;
#20 bench_io_in_valid = 0;
#400 $finish;
end

endmodule 