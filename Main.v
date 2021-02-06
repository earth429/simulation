module Main (
    CLK, SW_START, SW_INST, SW_SEL, SEG_DIGIT, SEG_PATTERN, LED
);
    input CLK; // 発振器
    input SW_START; // SW17
    input [7:0]SW_INST; // SW1~8
    input [1:0]SW_SEL; // SW18,22
    output [1:0]SEG_DIGIT; // 7セグの制御
    output [7:0]SEG_PATTERN; // 7セグの表示
    output [1:0]LED; // ステータス

    wire [7:0]inst; // 命令
    wire alu_clk; // ALU制御
    wire dec_clk; // Decoder制御
    wire wri_clk; // Write制御

    wire [3:0]ar_data; // アキュムレータの出力値
    wire [3:0] ir_data; // インデックスレジスタの出力値
    wire as; // アキュムレータの制御
    wire is; // インデックスレジスタの制御

    wire [3:0]in_data1; // ALUへの入力
    wire [3:0]in_data2;
    wire [3:0]addr; // 演算結果の出力先
    wire [3:0]out_data; // ALUの出力(演算結果)
    wire ic; // キャリ
    wire c; // キャリフラグ
    wire z; // ゼロフラグ

    wire [7:0]seg; // 表示する値(2桁)
    wire s_slk; // ダイナミック点灯用クロック
    wire [3:0]disp; // 表示する値(1桁)

    // アキュムレータ
    Accumulator accumulator(.CLK(wri_clk), .S(as), .R_DATA(ar_data), .W_DATA(out_data));
    // インデックスレジスタ
    IndexRegister indexregister(.CLK(wri_clk), .R_ADDR(SW_INST[3:0]), .R_DATA(ir_data), .S(is), .W_ADDR(addr), .W_DATA(out_data));
    // 制御とfecth
    CLKCounter clkcounter(.CLK(CLK), .SW17(SW_START), .SW_INST(SW_INST), .INST(inst), .DEC_CLK(dec_clk), .ALU_CLK(alu_clk), .WRI_CLK(wri_clk), .ST_INST());
    InstructionDecoder instructiondecoder(.CLK(dec_clk), .INST(inst), .ACC(ar_data), .INDEX(ir_data), .DATA1(in_data1), .DATA2(in_data2), .IW_ADDR(addr), .IS(is), .AS(as));
    ALU alu(.CLK(alu_clk), .INST(inst[7:4]), .IN_DATA1(in_data1), .IN_DATA2(in_data2), .OUT_DATA(out_data), .C(ic));
    StatusRegister statusregister(.CLK(wri_clk), .IC(ic), .DATA(out_data), .C(c), .Z(z));
    // 表示
    Selector selector(.SW_SEL(SW_SEL), .INST(SW_INST), .INDEX(ir_data), .ACC(ar_data), .C(c),.Z(z), .SEG(seg), .LED(LED));
    DFCLW100 dfclw100(.CLK(CLK), .S_CLK(s_clk));
    Switcher switcher(.S_CLK(s_clk), .D(SEG_DIGIT));
    DispSelector dispselector(.SEG(seg), .S_CLK(s_clk), .DISP(disp));
    Decoder8 decorder8(.CNT(disp), .DOUT(SEG_PATTERN));


endmodule