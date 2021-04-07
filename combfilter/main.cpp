#include <systemc.h>
#include "combfiltr.h"
#include "tb.h"

int sc_main(int argc, char** argv){

    // Signals
    sc_signal<int > x_sig, a_sig;
    sc_signal<int > y_sig;
    sc_signal<bool> reset_sig;
    // Clock
    //period, timestep, duty, first edge, value of first edge
    sc_clock clk_sig("clk", 10, SC_NS, 0.5, 0.0, SC_NS);

    // Connections
    // andgate_delayed a1
    combfiltr fil1("f1");
    f1.clk(clk_sig);
    f1.rst(reset_sig)
    f1.x  (x_sig);
    f1.a  (a_sig);
    f1.y  (y_sig);

    // testbench
    tb tb1("TESTBENCH");
    tb1.clk(clk_sig);
    tb1.rst(reset_sig)
    tb1.x(x_sig);
    tb1.a(a_sig);
    tb1.f(y_sig);
    

    // start the simulation
    sc_start();
    return 0;
}