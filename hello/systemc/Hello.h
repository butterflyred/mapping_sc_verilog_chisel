
#include <systemc.h>
SC_MODULE(Hello) 
{
    sc_in_clk clock;
    sc_in<sc_logic> reset;

    sc_out< sc_lv< 8 > > io_out;
    
    void func();
    SC_CTOR( Hello )
    {
        SC_CTHREAD(func, clock.pos());
    }
};

