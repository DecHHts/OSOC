module top_module(
    input clk,
    input reset,    // Active-high synchronous reset to 5'h1
    output [4:0] q
); 
    always @(posedge clk) begin
        if(reset)
            q<=5'h1;
        else
        	begin
               q<=q>>1;
               q[2]<=q[0]^q[3];
               q[4]<=0^q[0];
            end       
    end
endmodule