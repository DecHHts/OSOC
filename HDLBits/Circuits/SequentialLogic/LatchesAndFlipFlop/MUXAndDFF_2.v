module top_module (
    input clk,
    input w, R, E, L,
    output Q
);
    wire mid, d;
    assign mid = E ? w : Q;
    assign d = L ? R : mid;
    always@(posedge clk) Q = d;

endmodule
