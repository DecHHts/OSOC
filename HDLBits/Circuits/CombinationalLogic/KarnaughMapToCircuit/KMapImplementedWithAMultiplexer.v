module top_module (
    input c,
    input d,
    output [3:0] mux_in
); 
    
    always@(*) begin
        case({c,d})
            2'b00: mux_in[0] = 1'b0;
            default: mux_in[0] = 1'b1;
        endcase
        case({c,d})
            default: mux_in[1] = 1'b0;
        endcase
        case({c,d})
            2'b11: mux_in[3] = 1'b1;
            default: mux_in[3] = 1'b0;
        endcase
        case({c,d})
            2'b00: mux_in[2] = 1'b1;
            2'b10: mux_in[2] = 1'b1;
            default: mux_in[2] = 1'b0;
        endcase
    end
        

endmodule
