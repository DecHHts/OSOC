 module top_module (
    input clk,
    input reset,   // Synchronous active-high reset
    output [3:1] ena,
    output [15:0] q);
    reg [3:0] one;
    reg [3:0] ten;
    reg [3:0] hundred;
    reg [3:0] thousand;
    always @(posedge clk)
        begin
            if(reset || one==4'd9)
                one <= 4'b0;
            else
                one <= one+1'b1;
        end
    always @(posedge clk)
        begin
            if(reset || ((one == 4'd9)&&(ten == 4'd9)))
                ten <= 4'b0;
            else if(one == 4'd9)
                begin
                      ten <= ten+1'b1;
                end
        end
     always @(posedge clk)
        begin
            if(reset || ((one == 4'd9)&&(ten == 4'd9)&&(hundred == 4'd9)))
                hundred <= 4'b0;
            else if((one == 4'd9)&&(ten == 4'd9))
                hundred <= hundred+1'b1;
        end
     always @(posedge clk)
        begin
            if(reset || ((one == 4'd9)&&(ten == 4'd9)&&(hundred == 4'd9)&&(thousand == 4'd9)))
                thousand <= 4'b0;
            else if((one == 4'd9)&&(ten == 4'd9)&&(hundred == 4'd9))
                thousand <= thousand+1'b1;
        end
   
    assign q = {thousand,hundred,ten,one};
    assign ena[1] = (one == 4'd9)?1'b1:1'b0;
    assign ena[2] = ((one == 4'd9)&&(ten == 4'd9))?1'b1:1'b0;
    assign ena[3] = ((one == 4'd9)&&(ten == 4'd9)&&(hundred == 4'd9))?1'b1:1'b0;
endmodule