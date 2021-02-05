always @(posedge CLK) begin
    if (SW17 == 1'b1) // fetch
    begin
        if (sw_status == 1'b0) // SW17が立ち上がったとき一度だけfetch
        begin
            ST_INST <= 1'b1;
            INST  <= SW_INST;
            sw_status <= 1'b1;
        end
    end
    else
        sw_status <= 1'b0;

    if (ST_INST == 1'b1)
    begin
        if (cnt == 2'b00) // decode
        begin
            cnt <= cnt + 1;
            DEC_CLK <= 1; // decode開始
        end
        else if (cnt == 2'b01) // execute
        begin
            cnt <= cnt + 1;
            DEC_CLK <= 0;
            ALU_CLK <= 1; // ALUスタート
        end
        else if (cnt == 2'b10) // write
        begin
            cnt <= cnt + 1;
            ALU_CLK <= 0;
            WRI_CLK <= 1; // write開始
        end
        else if (cnt == 2'b11) // 終了
        begin
            cnt <= 2'b00;
            ST_INST <= 0;
            WRI_CLK <= 0;
        end
    end
end