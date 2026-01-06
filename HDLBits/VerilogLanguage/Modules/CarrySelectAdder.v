module top_module(
    input [31:0] a,
    input [31:0] b,
    output [31:0] sum
);
    wire sel;
    wire [31:0] result;
    
    add16 U_add16_0(
        .a(a[15:0]),
        .b(b[15:0]),
        .cin(1'b0),
        .cout(sel),
        .sum(sum[15:0])
    );
    add16 U_add16_1(
        .a(a[31:16]),
        .b(b[31:16]),
        .cin(1'b0),
        .sum(result[15:0])
    );
    add16 U_add16_2(
        .a(a[31:16]),
        .b(b[31:16]),
        .cin(1'b1),
        .sum(result[31:16])
    );
    
    always@(sel) begin
        case (sel)
            0: sum[31:16] = result[15:0];
            1: sum[31:16] = result[31:16];
            default: sum[31:16] = 16'b0;
        endcase
    end

endmodule