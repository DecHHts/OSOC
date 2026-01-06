module top_module(
    input [31:0] a,
    input [31:0] b,
    input sub,
    output [31:0] sum
);
    wire [31:0] mid;
    wire carry;
    assign mid = {32{sub}} ^ b;
    
    add16 U_add16_0(
        .a(a[15:0]),
        .b(mid[15:0]),
        .cin(sub),
        .cout(carry),
        .sum(sum[15:0])
    );
    add16 U_add16_1(
        .a(a[31:16]),
        .b(mid[31:16]),
        .cin(carry),
        .sum(sum[31:16])
    );

endmodule