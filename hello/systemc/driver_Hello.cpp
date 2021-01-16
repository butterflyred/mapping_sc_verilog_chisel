#include <systemc.h>
#include "driver_Hello.h" 

    void driver_Hello::drive_reset()
    {
        d_reset.write((sc_logic) 0 );
        wait(10,SC_NS);
        d_reset.write((sc_logic) 1 );
        wait(40,SC_NS);
        d_reset.write((sc_logic) 0 );
        wait(10,SC_NS);
        d_reset.write((sc_logic) 1 );
        wait(10,SC_NS);
    }
