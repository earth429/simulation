module dfclw100 (
    CLK, S_CLK
);
    input CLK;
    output S_CLK;

    reg S_CLK = 1'b0;
    reg [25:0]CEOUT = 16'd1;

    always @(posedge CLK) begin
        if (CEOUT == 15'd20000)
        begin
            CEOUT <= 15'd1;
            S_CLK <= ~S_CLK; // check
        end
        else
        begin
            CEOUT <= CEOUT + 15'd1;
        end
    end
endmodule