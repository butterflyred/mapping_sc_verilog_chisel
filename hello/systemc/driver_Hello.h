#include <systemc.h>
SC_MODULE(driver_Hello) 
{
    sc_in_clk d_clock;
    sc_out<sc_logic> d_reset;
    void drive_reset();
    SC_CTOR( driver_Hello )
    {
        SC_THREAD( drive_reset );
    }
};
