`include "Hello.v"

module testbench;
reg [0:2] indata_array;
wire bench_clock;
wire bench_io_rst;
wire [7:0]bench_io_out;

initial begin
    $dumpfile("testbench.vcd");
    $dumpvars(0, dut);
    $fsdbDumpfile("testbench.fsdb");
    $fsdbDumpvars(0, dut);

end

assign bench_clock = indata_array[0:0];
assign bench_io_rst = indata_array[2:2];

always
begin
#5 indata_array = $random;
end

Hello dut(
.clock(bench_clock),
.io_rst(bench_io_rst),
.io_out(bench_io_out)
);

initial
begin
$monitor($time, " clock = %b , io_rst = %b , io_out = %b ",
bench_clock, bench_io_rst, bench_io_out);
end

initial
begin
#50 $finish;
end

endmodule