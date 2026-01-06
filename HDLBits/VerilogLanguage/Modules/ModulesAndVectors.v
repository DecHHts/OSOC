module top_module ( 
    input clk, 
    input [7:0] d, 
    input [1:0] sel, 
    output [7:0] q 
);
    
    wire [7:0] one;
    wire [7:0] two;
    wire [7:0] three;
    
    my_dff8 U_my_dff8_1(
        .clk(clk),
        .d(d),
        .q(one)
    );
    
    my_dff8 U_my_dff8_2(
        .clk(clk),
        .d(one),
        .q(two)
    );
    
    my_dff8 U_my_dff8_3(
        .clk(clk),
        .d(two),
        .q(three)
    );
    
    always@(sel)begin
        case (sel)
            2'b00: q = d;
            2'b01: q = one;
            2'b10: q = two;
            2'b11: q = three;
            default: q = 8'b0;
        endcase
    end

endmodule