#include "systemc.h" 
#include "monitor_RealGCD.h" 

void monitor_RealGCD::prc_monitor()
{
    cout <<"Simulation Time: "<<sc_time_stamp()  << ", clock = "<< m_clock << ", reset = "<< m_reset << ", io_in_valid = "<< m_io_in_valid << ", io_in_bits_a = "<< m_io_in_bits_a << ", io_in_bits_b = "<< m_io_in_bits_b << ", io_in_ready = "<< m_io_in_ready << ", io_out_valid = "<< m_io_out_valid << ", io_out_bits = "<< m_io_out_bits << endl;
}
