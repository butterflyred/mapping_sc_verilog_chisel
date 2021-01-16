#include <systemc.h>
#include "monitor_Hello.h" 

void monitor_Hello::prc_monitor()
{
    cout <<"Simulation Time: "<<sc_time_stamp()  << ", clock = "<< m_clock << ", reset = "<< m_reset << ", io_out = "<< m_io_out << endl;
}
