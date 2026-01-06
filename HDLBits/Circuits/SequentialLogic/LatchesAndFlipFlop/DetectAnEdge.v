module top_module (
    input clk,
    input [7:0] in,
    output [7:0] pedge
);
    reg [7:0] temp_in;
    always @(posedge clk) begin
        temp_in <= in;
        pedge <= ~temp_in&in;
    end
endmodule
