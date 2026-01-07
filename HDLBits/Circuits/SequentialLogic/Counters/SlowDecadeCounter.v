module top_module (
    input clk,
    input slowena,
    input reset,
    output [3:0] q);
    
    always@(posedge clk)begin
        if(reset)
            q = 4'b0;
        else if(!slowena)
            q = q;
        else if(q < 9)
            q = q + 4'b1;
        else
            q = 4'b0;
    end

endmodule