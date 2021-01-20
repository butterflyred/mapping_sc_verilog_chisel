#include "systemc.h" 
#include "driver_RealGCD.h" 


    void driver_RealGCD::drive_reset()
    {
        d_reset.write((sc_logic) 1 );
        wait(10,SC_NS);
        d_reset.write((sc_logic) 0 );
        wait(10,SC_NS);
    }
    void driver_RealGCD::drive_io_in_valid()
    {
        d_io_in_valid.write((sc_logic) 1 );
        wait(20,SC_NS);
        d_io_in_valid.write((sc_logic) 0 );
        wait(80,SC_NS);
        d_io_in_valid.write((sc_logic) 1 );
        wait(20,SC_NS);
        d_io_in_valid.write((sc_logic) 0 );
        wait(80,SC_NS);
        d_io_in_valid.write((sc_logic) 1 );
        wait(20,SC_NS);
        d_io_in_valid.write((sc_logic) 0 );
        wait(80,SC_NS);
    }
    void driver_RealGCD::drive_io_in_bits_a()
    {
        d_io_in_bits_a.write((sc_lv< 16 >) 48 );
        wait(100,SC_NS);
        d_io_in_bits_a.write((sc_lv< 16 >) 7 );
        wait(100,SC_NS);
        d_io_in_bits_a.write((sc_lv< 16 >) 100 );
        wait(100,SC_NS);
    }
    void driver_RealGCD::drive_io_in_bits_b()
    {
        d_io_in_bits_b.write((sc_lv< 16 >) 32 );
        wait(100,SC_NS);
        d_io_in_bits_b.write((sc_lv< 16 >) 3 );
        wait(100,SC_NS);
        d_io_in_bits_b.write((sc_lv< 16 >) 10 );
        wait(100,SC_NS);
    }
