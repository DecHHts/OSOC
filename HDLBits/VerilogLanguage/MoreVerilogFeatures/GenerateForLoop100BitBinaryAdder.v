module top_module( 
    input [99:0] a, b,
    input cin,
    output [99:0] cout,
    output [99:0] sum );
    
    wire [100:0] carry;
    assign carry[0] = cin;
    assign carry[100:1] = cout[99:0];

    genvar i;
    generate
        for (i = 0; i < 100; i = i + 1) begin : gen_loop
            fa U_fa(
                .a(a[i]),
                .b(b[i]),
                .cin(carry[i]),
                .cout(cout[i]),
                .sum(sum[i])
            );
    	end
	endgenerate
endmodule

module fa(
    input a,
    input b,
    input cin,
    output cout,
    output sum
);
    assign sum = a ^ b ^ cin;
    assign cout = a&b | a&cin | b&cin;
    
endmodule