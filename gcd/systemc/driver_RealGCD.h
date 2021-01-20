#include "systemc.h" 
SC_MODULE(driver_RealGCD) 
{
    sc_in_clk d_clock;
    sc_out<sc_logic> d_reset;
    sc_out<sc_logic> d_io_in_valid;
    sc_out< sc_lv< 16 > >d_io_in_bits_a;
    sc_out< sc_lv< 16 > >d_io_in_bits_b;
    void drive_reset();
    void drive_io_in_valid();
    void drive_io_in_bits_a();
    void drive_io_in_bits_b();
    SC_CTOR( driver_RealGCD )
    {
        SC_THREAD( drive_reset );
        SC_THREAD( drive_io_in_valid );
        SC_THREAD( drive_io_in_bits_a );
        SC_THREAD( drive_io_in_bits_b );
    }
};
