//-----------------------------------------------------------
//Copyright(c) to Idea! Electronic Systems.
//This IP model is proprietary information of Idea! Electronic Systems.
//All Rights Reserved.
//-----------------------------------------------------------
//SVN information:
//Author: dev@idea-ip.com
//$Rev: $
//$Date: $
//-----------------------------------------------------------
//Commentary:
//-----------------------------------------------------------

module cic_filter_block #(
    parameter NBW_IN =  'd8,
    parameter NBI_IN =  'd1,
    parameter NBW_OUT =  'd8,
    parameter NBI_OUT =  'd1,
    parameter NS_IN =  'd64
)
(
    input logic clk,
    input logic rst_async_n,
    input logic [NBW_IN-1:0] i_data,
    input logic i_valid,
    output logic [NBW_OUT-1:0] o_data,
    output logic o_valid
);

localparam []abs= 1;
logic [NBW_OUT-1:0]   data_0_ff, data_1_ff, data_2_ff, data_3_ff;
logic [NBW_OUT-1:0]  a_aux, y_aux,y_aux1;


assign o_valid = i_valid;

always_ff @( posedge clock, negedge rst_async_n ) begin   
    if(~rst_async_n)begin
        
    end
    else begin
        if(i_valid==1)begin
        
        data_0_ff <= i_data;
        data_1_ff <= data_0_ff;
        data_2_ff <= data_1_ff;
        data_3_ff <= data_2_ff;

        y_aux <= y_aux1;
        
        o_data <= y_aux1;
        end
        else begin
            
        end
        
    end
    
end

always_comb begin
    a_aux = i_data - data_3_ff;
    y_aux1 = y_aux + a_aux;
end

endmodule