#include <systemc.h>
#include <combfiltr.h>

void combfiltr::do_combfiltr(){
    //init
    //wait();

     if(rst){
        for (int i = 0; i < 4; i++) {

        comb_q.push(0); 

        }

        intg_q.push(0);

        a = 0;
        y = 0;
     }


    while(true){

        a = x + comb_q.remove();
        comb_q.pop();

        y = a + intg_q.remove();
        intg_q.pop();

        
        wait();
    }
}