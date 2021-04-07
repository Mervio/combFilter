#include "tb.h"
#include "terminal_color.h"

void tb::tb_source(){
   	rst.write( 1 );
	wait();
	rst.write( 0 );
	wait();

    for(int i = 0; i < 10; i++){
        x.write(i);
        
        wait();
        cout<<"i: "<< i<< " "<< y.read() << endl;
    }
    wait();
    sc_stop();
}
//void tb::tb_sink(){
  //  int y_in;


//}