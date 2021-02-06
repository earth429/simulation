module selector (
    SW_SEL, INST, INDEX, ACC, C, Z, SEG, LED
);
    input [1:0]SW_SEL;
    input [7:0]INST;
    input [3:0]INDEX;
    input [3:0]ACC;
    input C;
    input Z;
    output [7:0]SEG;
    output [1:0]LED;

    function [9:0]sel;
        input [1:0]sw_sel;
        input [7:0]inst;
        input [3:0]index;
        input [3:0]acc;
        input c;
        input z;
        begin
            case (sw_sel)
                2'b00:sel = {inst, 2'b11};
                2'b01:sel = {inst, 2'b11};
                2'b10:sel = {4'b0, index, 2'b11};
                2'b11:sel = {4'b0, acc, ~c, ~z};
            endcase
        end
    endfunction

    assign {SEG, LED} = sel(SW_SEL, INST, INDEX, ACC, C, Z);
endmodule