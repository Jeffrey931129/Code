`timescale 1ns/1ps

module Functional_Unit(instruction, A, B, C, select, F);
    input wire [7:0] instruction;
    input wire [7:0] A;
    input wire [7:0] B;
    input wire [7:0] C;
    input wire [2:0] select;
    output [7:0] F;
    reg [7:0] X, Y;
    reg [7:0] F;
    wire [2:0] encoder_instruction;

    encoder e1(instruction,encoder_instruction);


    //TODO: write your design below
    //You can define F as 'reg' or 'wire'
    //You must only use "encoder_instructions", not "instruction".
    always @(*) begin
        case (select)
            3'b011: begin
                X = B;
                Y = C;
            end
            3'b101: begin
                X = A;
                Y = C;
            end
            3'b110: begin
                X = A;
                Y = B;
            end
            default: begin
                X = C;
                Y = A;
            end
        endcase
    end

    always @(*) begin
        case (encoder_instruction)
            3'b000: F = X + Y;
            3'b001: F = X + ~Y;
            3'b010: F = X & Y;
            3'b011: F = X | Y;
            3'b100: F = (X > Y) ? X : Y;
            3'b101: F = (X < Y) ? X : Y;
            3'b110: F = ({X[0], X[7:1]} + Y); // Right rotate X by 1 bit and add Y
            3'b111: F = ({X[6:0], X[7]} + Y); // Left rotate X by 1 bit and add Y
            default: F = 8'b0;
        endcase
    end

endmodule

module encoder (instruction,encoder_instruction);

    input wire[7:0] instruction;
    output [3:0] encoder_instruction;
    reg [3:0] encoder_instruction;

    //TODO: write your design below
    //You can define encoder_instruction as 'reg' or 'wire'
    always @(*) begin
        casez (instruction)
            8'b00000001: encoder_instruction = 3'b000;
            8'b0000001Z: encoder_instruction = 3'b001;
            8'b000001ZZ: encoder_instruction = 3'b010;
            8'b00001ZZZ: encoder_instruction = 3'b011;
            8'b0001ZZZZ: encoder_instruction = 3'b100;
            8'b001ZZZZZ: encoder_instruction = 3'b101;
            8'b01ZZZZZZ: encoder_instruction = 3'b110;
            8'b1ZZZZZZZ: encoder_instruction = 3'b111;
            default: encoder_instruction = 3'b000;
        endcase
    end

endmodule