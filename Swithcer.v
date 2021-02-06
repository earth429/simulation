module seitcher (
    S_CLK, D
);
    input S_CLK;
    output [1:0]D;

    function [1:0]sw;
        input s_clk;
        begin
            case (s_clk)
                1'b0:sw = 2'b01;
                1'b1:sw = 2'b10;
            endcase
        end
    endfunction

    assign D = sw(S_CLK);

endmodule