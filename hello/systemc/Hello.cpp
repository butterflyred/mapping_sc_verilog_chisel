
#include <systemc.h>
#include "Hello.h" 

void Hello::func()
{
    while( true )
    {
        wait();
        if (/* condition */reset.read() == 1)
        {
            /* code */
        io_out = (sc_lv< 8 >)( 7 );
        } else
        {
        io_out = (sc_lv< 8 >)( 42 );
            /* code */
        }
        
        
    }
}
