module Ins (
    CLK, INST, ACC, INDEX, DATA1, DATA2, IW_ADDR, IS, AS
);

input CLK; // クロック
input [7:0]INST; // 命令
input [3:0]ACC; // アキュムレータの値
input [3:0]INDEX; // インデックスレジスタの値
output [3:0]DATA1; // 演算器への入力
output [3:0]DATA2;
output [3:0]IW_ADDR; // インデックスレジスタのレジスタ番号
output IS; // インデックスレジスタの入力制御
output AS; // アキュムレータの入力制御

reg [3:0]DATA1;
reg [3:0]DATA2;
reg [3:0]IW_ADDR;
reg IS;
reg AS;

always @(posedge CLK) begin

    // アキュムレータへ即値格納
    if (INST[7:4] == 4'b0001)
    begin
        DATA1 <= INST[3:0]; // 下位4ビットが即値になる
        DATA2 <= 4'bzzzz;
        IW_ADDR <= 4'bzzzz;
        IS <= 0;
        AS <= 1; // 格納先はアキュムレータとする
    end

    // インデックスレジスタからアキュムレータへ格納
    if (INST[7:4] == 4'b0010)
    begin
        DATA1 <= INDEX; // インデックスレジスタの値
        DATA2 <= 4'bzzzz;
        IW_ADDR <= 4'bzzzz;
        IS <= 0;
        AS <= 1; // 格納先はアキュムレータ
    end

    // アキュムレータからインデックスレジスタへ格納
    if (INST[7:4] == 4'b0011)
    begin
        DATA1 <= ACC; // アキュムレータの値
        DATA2 <= 4'bzzzz;
        IW_ADDR <= INST[3:0] // 下位4ビットがインデックスレジスタのアドレス
        IS <= 1; // 格納先はインデックスレジスタ
        AS <= 0;
    end

    // アキュムレータからインデックスレジスタへの加算、減算、論理和、論理積、排他的論理和
    if (INST[7:4] == 4'b0100 || INST[7:4] == 4'b0110 || INST[7:4] == 4'b1010 || INST[7:4] == 4'b1100 || INST[7:4] == 4'b1110) 
    begin
        DATA1 <= INDEX;
        DATA2 <= ACC;
        IW_ADDR <= 4'bzzzz;
        IS <= 0;
        AS <= 1; // 格納先はアキュムレータ
    end

    // アキュムレータから即値への加算、減算、論理和、論理積、排他的論理和
    if (INST[7:4] == 4'b0101 || INST[7:4] == 4'b0111 || INST[7:4] == 4'b1011 || INST[7:4]==4'1101 || INST[7:4] == 4'b1111)
    begin
        DATA <= ACC;
        DATA2 <= INST[3:0]; // 下位4ビットが即値
        IW_ADDR <= 4'bzzzz;
        IS <= 0;
        AS <= 1; // 格納先はアキュムレータ
    end

    // アキュムレータの論理反転
    if (INST[7:4] == 4'b1000)
    begin
        DATA1 <= ACC; // アキュムレータの値
        DATA2 <= 4'bzzzz;
        IW_ADDR <= 4'bzzzz;
        IS <= 0;
        AS <= 1; // 格納先はアキュムレータ
    end

    // 即値の論理反転
    if (INST[7:4] == 4'b1001)
    begin
        DATA1 <= INST[3:0]; // 下位4ビットが即値
        DATA2 <= 4'bzzzz;
        IW_ADDR <= 4'bzzzz;
        IS <= 0;
        AS <= 1; // 格納先はアキュムレータ
    end

end
endmodule