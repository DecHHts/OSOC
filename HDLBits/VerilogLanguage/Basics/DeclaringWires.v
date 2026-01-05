module top_module(
    input a,
    input b,
    input c,
    input d,
    output out,
    output out_n   ); 

    wire and_or_1;
    wire and_or_2;
    
    assign and_or_1 = a & b;
    assign and_or_2 = c & d;
    assign out = and_or_1 | and_or_2;
    assign out_n = !(and_or_1 | and_or_2);
endmodule