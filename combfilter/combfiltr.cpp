#include <systemc.h>
#include <combfiltr.h>

void combfiltr::do_combfiltr(){
    //init
    //wait();

     if(rst){
        for (int i = 0; i < 4; i++) {

        comb_q.push(0); 

        }
        y = 0;
    }
 
    while(true){
	cout<<"Comb Queue:"<<comb_q.front()<<endl<<"Integer Queue:"<<intg_q.front()<<endl;
	cout<<"===================================="<<endl;

	comb_q.push(x);

        y = (x - comb_q.front()) + y;

	o_y.write(y);
        comb_q.pop();
	
        wait();
    }
}
