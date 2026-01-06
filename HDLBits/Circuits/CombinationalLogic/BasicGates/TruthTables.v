module top_module( 
    input x3,
    input x2,
    input x1,  // three inputs
    output f   // one output
);
    
    assign f = ({x3,x2,x1} == 3'b010 | {x3,x2,x1} == 3'b011 | {x3,x2,x1} == 3'b101 | {x3,x2,x1} == 3'b111) ? 1 : 0;

endmodule