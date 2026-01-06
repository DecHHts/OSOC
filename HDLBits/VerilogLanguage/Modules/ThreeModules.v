module top_module ( input clk, input d, output q );
    
    wire one;
    wire two;
    
    my_dff U_my_dff_1(
        .clk(clk),
        .d(d),
        .q(one)
    );
    
    my_dff U_my_dff_2(
        .clk(clk),
        .d(one),
        .q(two)
    );
    
    my_dff U_my_dff_3(
        .clk(clk),
        .d(two),
        .q(q)
    );

endmodule