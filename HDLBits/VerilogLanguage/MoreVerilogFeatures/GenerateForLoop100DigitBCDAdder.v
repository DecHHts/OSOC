module top_module( 
    input [399:0] a, b,
    input cin,
    output cout,
    output [399:0] sum );
    
    wire [100:0] carry;
    assign carry[0] = cin;
    assign cout = carry[100];

    genvar i;
    generate
        for(i = 0; i < 100; i = i + 1)begin : gen_loop
            bcd_adder U_bcd_adder(
                .a(a[4*i+3:4*i]),
                .b(b[4*i+3:4*i]),
                .cin(carry[i]),
                .cout(carry[i+1]),
                .sum(sum[4*i+3:4*i])
            );
        end
    endgenerate
    
endmodule

module bcd_adder(
    input [3:0] a,
    input [3:0] b,
    input cin,
    output cout,
    output [3:0] sum
);
    wire [4:0] raw = a + b + cin;          // 0..19
    wire       need_correction = (raw > 9);
    wire [4:0] corrected = raw + (need_correction ? 5'd6 : 5'd0);
    assign sum  = corrected[3:0];
    assign cout = corrected[4];
    
endmodule