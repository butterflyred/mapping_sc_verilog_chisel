#include <systemc.h>
SC_MODULE(monitor_Hello) 
{
    sc_in_clk m_clock;
    sc_in<sc_logic> m_reset;
    sc_in< sc_lv< 8 > > m_io_out;    

    void prc_monitor();

    SC_CTOR( monitor_Hello )
    {
        SC_METHOD(prc_monitor);
        // sensitive << m_clock << m_reset << m_io_out;
        sensitive << m_io_out ;
    }
};
