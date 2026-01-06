module top_module (
    input a,
    input b,
    input c,
    input d,
    output out_sop,
    output out_pos
); 
    
    // SOP (积之和) 实现: CD + a'b'c
    assign out_sop = (c & d) | (~a & ~b & c);

    // POS (和之积) 实现: C * (a' + b) * (b' + d)
    assign out_pos = c & (~a | b) & (~b | d);

endmodule