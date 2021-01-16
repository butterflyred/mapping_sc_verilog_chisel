#include "driver_Hello.h" 
#include "monitor_Hello.h" 
#include "Hello.h" 

int sc_main(int argc , char *argv[] )
{
         sc_clock t_clock("t_clock", 10, SC_NS);

    sc_signal< sc_logic >t_reset;
    sc_signal< sc_lv< 8 > >t_io_out;
    Hello  inst_Hello("Hello" );
         inst_Hello.clock( t_clock);
         inst_Hello.reset( t_reset);
         inst_Hello.io_out( t_io_out);
    driver_Hello  inst_driver_Hello("driver_Hello" );
         inst_driver_Hello.d_clock( t_clock);
         inst_driver_Hello.d_reset( t_reset);
    monitor_Hello  inst_monitor_Hello("monitor_Hello" );
         inst_monitor_Hello.m_clock( t_clock);
         inst_monitor_Hello.m_reset( t_reset);
         inst_monitor_Hello.m_io_out( t_io_out);
             // tracing:
	// trace file creation, with VCD type output
	sc_trace_file *tf = sc_create_vcd_trace_file("RESULT");
	// External signals
	sc_trace(tf, inst_Hello.clock,          "inst_Hello.clock");
	sc_trace(tf, inst_Hello.reset,          "inst_Hello.reset");
	sc_trace(tf, inst_Hello.io_out,        "inst_Hello.io_out");
	sc_trace(tf, inst_driver_Hello.d_clock,      "inst_driver_Hello.d_clock");
	sc_trace(tf, inst_driver_Hello.d_reset,          "inst_driver_Hello.d_reset");
	sc_trace(tf, inst_monitor_Hello.m_clock,          "inst_monitor_Hello.m_clock");
	sc_trace(tf, inst_monitor_Hello.m_reset,        "inst_monitor_Hello.m_reset");
	sc_trace(tf, inst_monitor_Hello.m_io_out,          "inst_monitor_Hello.m_io_out");
    sc_start(100,SC_NS);
     sc_close_vcd_trace_file(tf);
    return 0;
}
