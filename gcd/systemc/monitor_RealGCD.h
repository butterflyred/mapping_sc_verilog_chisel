#include "systemc.h" 
SC_MODULE(monitor_RealGCD) 
{
    sc_in_clk m_clock;
    sc_in<sc_logic> m_reset;
    sc_in<sc_logic> m_io_in_ready;
    sc_in<sc_logic> m_io_in_valid;
    sc_in< sc_lv< 16 > > m_io_in_bits_a;
    sc_in< sc_lv< 16 > > m_io_in_bits_b;
    sc_in<sc_logic> m_io_out_valid;
    sc_in< sc_lv< 16 > >  m_io_out_bits;
    void prc_monitor();

    SC_CTOR( monitor_RealGCD )
    {
        SC_METHOD(prc_monitor);
        sensitive << m_clock << m_reset << m_io_in_ready << m_io_in_valid << m_io_in_bits_a << m_io_in_bits_b << m_io_out_valid << m_io_out_bits;
    }
};
