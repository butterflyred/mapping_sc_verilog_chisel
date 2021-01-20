#include "driver_RealGCD.h" 
#include "monitor_RealGCD.h" 
#include "RealGCD.h" 

int sc_main(int argc , char *argv[] )
{
        sc_clock t_clock("t_clock", 10, SC_NS);
    sc_signal< sc_logic >t_reset;

    sc_signal< sc_logic >t_io_in_ready;
    sc_signal< sc_logic >t_io_in_valid;
    sc_signal< sc_lv< 16 > >t_io_in_bits_a;
    sc_signal< sc_lv< 16 > >t_io_in_bits_b;
    sc_signal< sc_logic >t_io_out_valid;
    sc_signal< sc_lv< 16 > >t_io_out_bits;
    RealGCD  inst_RealGCD("RealGCD" );
         inst_RealGCD.clock( t_clock);
         inst_RealGCD.reset( t_reset);
         inst_RealGCD.io_in_ready( t_io_in_ready);
         inst_RealGCD.io_in_valid( t_io_in_valid);
         inst_RealGCD.io_in_bits_a( t_io_in_bits_a);
         inst_RealGCD.io_in_bits_b( t_io_in_bits_b);
         inst_RealGCD.io_out_valid( t_io_out_valid);
         inst_RealGCD.io_out_bits( t_io_out_bits);
    driver_RealGCD  inst_driver_RealGCD("driver_RealGCD" );
         inst_driver_RealGCD.d_clock( t_clock);
         inst_driver_RealGCD.d_reset( t_reset);
         inst_driver_RealGCD.d_io_in_valid( t_io_in_valid);
         inst_driver_RealGCD.d_io_in_bits_a( t_io_in_bits_a);
         inst_driver_RealGCD.d_io_in_bits_b( t_io_in_bits_b);
    monitor_RealGCD  inst_monitor_RealGCD("monitor_RealGCD" );
         inst_monitor_RealGCD.m_clock( t_clock);
         inst_monitor_RealGCD.m_reset( t_reset);
         inst_monitor_RealGCD.m_io_in_ready( t_io_in_ready);
         inst_monitor_RealGCD.m_io_in_valid( t_io_in_valid);
         inst_monitor_RealGCD.m_io_in_bits_a( t_io_in_bits_a);
         inst_monitor_RealGCD.m_io_in_bits_b( t_io_in_bits_b);
         inst_monitor_RealGCD.m_io_out_valid( t_io_out_valid);
         inst_monitor_RealGCD.m_io_out_bits( t_io_out_bits);
   // trace file creation, with VCD type output
	sc_trace_file *tf = sc_create_vcd_trace_file("RESULT");
	// External signals
	sc_trace(tf, inst_RealGCD.clock,          "inst_RealGCD.clock");
	sc_trace(tf, inst_RealGCD.reset,          "inst_RealGCD.reset");
	sc_trace(tf, inst_RealGCD.io_in_ready,        "inst_RealGCD.io_in_ready");
	sc_trace(tf, inst_RealGCD.io_in_valid,      "inst_RealGCD.io_in_valid");
	sc_trace(tf, inst_RealGCD.io_in_bits_a,          "inst_RealGCD.io_in_bits_a");
	sc_trace(tf, inst_RealGCD.io_in_bits_b,          "inst_RealGCD.io_in_bits_b");
	sc_trace(tf, inst_RealGCD.io_out_valid,        "inst_RealGCD.io_out_valid");
	sc_trace(tf, inst_RealGCD.io_out_bits,          "inst_RealGCD.io_out_bits");
	sc_trace(tf, inst_RealGCD.busy,          "inst_RealGCD.busy");

	sc_trace(tf, inst_driver_RealGCD.d_io_in_valid,          "inst_driver_RealGCD.d_io_in_valid");
	sc_trace(tf, inst_driver_RealGCD.d_io_in_bits_a,          "inst_driver_RealGCD.d_io_in_bits_a");
	sc_trace(tf, inst_driver_RealGCD.d_io_in_bits_b,          "inst_driver_RealGCD.d_io_in_bits_b");
	
	sc_trace(tf, inst_monitor_RealGCD.m_io_in_ready,          "inst_monitor_RealGCD.m_io_in_ready");
	sc_trace(tf, inst_monitor_RealGCD.m_io_in_valid,          "inst_monitor_RealGCD.m_io_in_valid");
	sc_trace(tf, inst_monitor_RealGCD.m_io_in_bits_a,          "inst_monitor_RealGCD.m_io_in_bits_a");
	sc_trace(tf, inst_monitor_RealGCD.m_io_in_bits_b,          "inst_monitor_RealGCD.m_io_in_bits_b");
	sc_trace(tf, inst_monitor_RealGCD.m_io_out_valid,          "inst_monitor_RealGCD.m_io_out_valid");
	sc_trace(tf, inst_monitor_RealGCD.m_io_out_bits,          "inst_monitor_RealGCD.m_io_out_bits");

    sc_start(500,SC_NS);
     sc_close_vcd_trace_file(tf);
    return 0;
}
