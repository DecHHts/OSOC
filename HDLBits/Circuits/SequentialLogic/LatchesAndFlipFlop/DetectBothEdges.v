module top_module (
    input clk,
    input [7:0] in,
    output [7:0] anyedge
);
    
    reg [7:0] temp_in;
    always @(posedge clk) begin
        temp_in <= in;
        anyedge <= temp_in^in;
    end

endmodule