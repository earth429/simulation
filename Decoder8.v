module decoder8 (
    CNT, DOUT
);
    input [3:0]CNT;
    output [7:0]DOUT;

    function [7:0]dec;
        input [3:0]cnt;
        begin
            case (cnt)
                4'h0:dec = 8'b1100_0000;
                4'h1:dec = 8'b1111_1001;
                4'h2:dec = 8'b1010_0100;
                4'h3:dec = 8'b1011_0000;
                4'h4:dec = 8'b1001_1001;
                4'h5:dec = 8'b1001_0010;
                4'h6:dec = 8'b1000_0010;
                4'h7:dec = 8'b1101_1000;
                4'h8:dec = 8'b1000_0000;
                4'h9:dec = 8'b1001_1000;
                4'ha:dec = 8'b1000_1000;
                4'hb:dec = 8'b1000_0011;
                4'hc:dec = 8'b1100_0110;
                4'hd:dec = 8'b1010_0001;
                4'he:dec = 8'b1000_0110;
                4'hf:dec = 8'b1000_1110;
            endcase
        end
    endfunction

    assign DOUT = dec(CNT);
    
endmodule