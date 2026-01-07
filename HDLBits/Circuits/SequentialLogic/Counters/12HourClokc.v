module top_module(
    input clk,
    input reset,
    input ena,
    output pm,
    output [7:0] hh,
    output [7:0] mm,
    output [7:0] ss); 
    reg pm_temp;
    reg [3:0] ss_one;
    reg [3:0] ss_ten;
    reg [3:0] mm_one;
    reg [3:0] mm_ten;
    reg [3:0] hh_one;
    reg [3:0] hh_ten;
    wire pm_ding;
    always @(posedge clk)
        begin
            if(reset)
                begin
                    ss_one <= 4'b0;
                end
            else if(ena)
                begin
                    if(ss_one == 4'd9)
                        ss_one <= 4'b0;
                    else
                        ss_one <= ss_one+1'b1;
                end
        end
    always @(posedge clk)
        begin
            if(reset)
                begin
                    ss_ten <= 4'b0;
                end
            else if((ena)&&(ss_one == 4'd9))
                begin
                    if(ss_ten == 4'd5)
                        ss_ten <= 4'b0;
                    else
                        ss_ten <= ss_ten+1'b1;
                end
        end
    always @(posedge clk)
        begin
            if(reset)
                begin
                    mm_one <= 4'b0;
                end
            else if((ena)&&(ss_one == 4'd9)&&(ss_ten == 4'd5))
                begin
                    if(mm_one == 4'd9)
                        mm_one <= 4'b0;
                    else
                        mm_one <= mm_one+1'b1;
                end
        end
    always @(posedge clk)
        begin
            if(reset)
                begin
                    mm_ten <= 4'b0;
                end
            else if((ena)&&(ss_one == 4'd9)&&(ss_ten == 4'd5)&&(mm_one == 4'd9))
                begin
                    if(mm_ten == 4'd5)
                        mm_ten <= 4'b0;
                    else
                        mm_ten <= mm_ten+1'b1;
                end
        end
    always @(posedge clk)
        begin
            if(reset)
                begin
                    hh_one <= 4'd2;
                end
            else if((ena)&&(ss_one == 4'd9)&&(ss_ten == 4'd5)&&(mm_one == 4'd9)&&(mm_ten == 4'd5))
                begin
                    if(hh_one == 4'd9)
                        hh_one <= 4'b0;
                    else if((hh_one == 4'd2)&&(hh_ten == 4'd1))
                        begin
                            hh_one <= 4'b1;
                        end
                    else
                        hh_one <= hh_one+1'b1;
                end
        end   
    always @(posedge clk)
        begin
            if(reset)
                begin
                    hh_ten <= 4'd1;
                end
            else if((ena)&&(ss_one == 4'd9)&&(ss_ten == 4'd5)&&(mm_one == 4'd9)&&(mm_ten == 4'd5))
                begin
                    if((hh_one == 4'd2)&&(hh_ten == 4'd1))
                        hh_ten <= 4'b0;
                    else if(hh_one == 4'd9)
                        begin
                            hh_ten <= hh_ten+1'b1;;
                        end
                end
        end
    always @(posedge clk)
        begin
            if(reset)
                begin
                    pm_temp <= 1'b0;
                end
            else if(pm_ding)
                begin
                    pm_temp <= ~pm_temp;
                end
        end
    assign pm_ding = (hh_ten == 4'd1)&&(hh_one == 4'd1)&&(ena)&&(ss_one == 4'd9)&&(ss_ten == 4'd5)&&(mm_one == 4'd9)&&(mm_ten == 4'd5);
    assign ss = {ss_ten,ss_one};
    assign mm = {mm_ten,mm_one};
    assign hh = {hh_ten,hh_one};
    assign pm = pm_temp;
endmodule