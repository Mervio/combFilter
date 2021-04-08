#include <systemc.h>

SC_MODULE(tb)
{
    sc_out <int> x;
    sc_in <int>o_y;
    sc_out<bool>rst;
    sc_in_clk clk;

    void tb_source();

    SC_CTOR(tb){
        SC_CTHREAD(tb_source, clk.pos() );
    }

};
