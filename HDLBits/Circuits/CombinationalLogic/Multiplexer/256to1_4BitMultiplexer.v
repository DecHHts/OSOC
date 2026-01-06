module top_module( 
    input [1023:0] in,
    input [7:0] sel,
    output [3:0] out );
    
    always@(*) begin
        out[3] = in[4*sel+8'd3];
        out[2] = in[4*sel+8'd2];
        out[1] = in[4*sel+8'd1];
        out[0] = in[4*sel];
    end

endmodule