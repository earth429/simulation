module ALU (
    CLK, INST, IN_DATA1, IN_DATA2, OUT_DATA, C
);
    input CLK; // クロック
    input [3:0]INST; // 命令種別
    input [3:0]IN_DATA1; // 演算器からの入力
    input [3:0]IN_DATA2;
    output [3:0]OUT_DATA; // 演算器からの出力
    output C; // キャリフラグ

    reg [3:0]OUT_DATA;
    reg C;

    always @(posedge CLK) begin

        // 値格納
        if (INST >= 4'b0001 && INST <= 4'b0011)
        begin
            OUT_DATA <= IN_DATA1;
            C <= 0;
        end

        // アキュムレータとの加算
        else if (INST >= 4'b0100 && INST <= 4'b0101)
            {C, OUT_DATA} <= IN_DATA1 + IN_DATA2;
        
        // アキュムレータからの減算
        else if (INST >= 4'b0110 && INST <= 4'b0111)
            {C, OUT_DATA} <= IN_DATA1 - INDATA2;

        // 論理反転
        else if (INST >= 4'b1000 && INST <= 4'b1001)
        begin
            OUT_DATA <= =IN_DATA1;
            C <= 0;
        end

        // 論理和
        else if (INST >= 4'b1010 && INST <= 4'b1011)
        begin
            OUT_DATA <= IN_DATA1 | IN_DATA2;
            C <= 0;
        end

        // 論理積
        else if (INST >= 4'b1110 && INST <= 4'b1101)
        begin
            OUT_DATA <= IN_DATA1 & IN_DATA2;
            C <= 0;
        end

        // 排他的論理和
        else if (INST >= 4'b1110 && INST <= 4'b1111)
        begin
            OUT_DATA <= IN_DATA1 ^ IN_DATA2;
            C <= 0;
        end
    end

endmodule