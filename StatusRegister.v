module statusregister (
    CLK, IC, DATA, C, Z
);
    input CLK;
    input IC;
    input [3:0]DATA;
    output C;
    output Z;

    reg Z;
    reg C;

    always @(posedge CLK) begin
        C <= IC;
        if (DATA == 4'b0000)
        begin
            Z <= 1;
        end
        else
        begin
            Z <= 0;
        end
    end
endmodule