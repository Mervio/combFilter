#include <systemc.h>
#include <queue>

SC_MODULE(combfiltr)
{	
	std::queue<int> comb_q;
	std::queue<int> intg_q;
	sc_in<bool> clk;
	sc_in<bool> rst;
	sc_in<int> x;
	sc_out<int> o_y;
	sc_out<int>y;

    void do_combfiltr();

    SC_CTOR(combfiltr){
        SC_CTHREAD(do_combfiltr, clk.pos());
        reset_signal_is(rst,true);
    }

};
