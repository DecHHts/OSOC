module top_module (input x, input y, output z);
    
    wire one, two, three,four;
    
    circuit_a IA1(
        .x(x),
        .y(y),
        .z(one)
    );
    circuit_b IB1(
        .x(x),
        .y(y),
        .z(two)
    );
    circuit_a IA2(
        .x(x),
        .y(y),
        .z(three)
    );
    circuit_b IB2(
        .x(x),
        .y(y),
        .z(four)
    );

    assign z = (one | two) ^ (three & four);

endmodule

module circuit_a (input x, input y, output z);

    assign z = (x^y) & x;
    
endmodule

module circuit_b ( input x, input y, output z );
    
    assign z = ~(x ^ y);

endmodule