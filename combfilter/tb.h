#include <systemc.h>

SC_MODULE(tb)
{
    sc_out<int > x,a;
    sc_in<int > y;
    sc_in_clk clk;

    void tb_source();

    SC_CTOR(tb){
        SC_CTHREAD(tb_source, clk.pos() );
    }

};