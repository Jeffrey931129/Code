`timescale 1ns/1ps
module find_MAX(
    input wire clk,
    input wire rst_n,
    input wire start,
    input wire valid,
    input wire [7:0] data_A,
    input wire [7:0] data_B,
    input wire [7:0] data_C,
    input wire [7:0] instruction,
    input wire [2:0] count,
    input wire [2:0] select,
    output reg [7:0] second_maximum
);
    wire [7:0] result;

    // Functional_Unit instantiation
    Functional_Unit fu(
        .instruction(instruction), 
        .A(data_A),
        .B(data_B),
        .C(data_C),
        .select(select),
        .F(result)
    );
    //TODO: write your design below
    //You cannot modify anything above

    reg [0:0] current_state;
    reg [7:0] max1, max2;
    reg [2:0] now_count;
    
    initial begin
        max1 = 8'b00000000;
        max2 = 8'b00000000;
        second_maximum = 8'b00000000;
        now_count = 3'b000;
        current_state = 1'b0;
    end

    // Output and counter logic
    always @(posedge clk) begin
        case (current_state)
            1'b0: begin
                if (start) begin
                    current_state = 1'b1;
                    max1 = 8'b00000000;
                    max2 = 8'b00000000;
                    second_maximum = 8'b00000000;
                end
            end
            1'b1: begin
                if (valid) begin
                    // $display("%3d : %8d\n", now_count, result);
                    now_count = now_count - 1;
                    if (result > max1) begin
                        max2 = max1;
                        max1 = result;
                    end else if (result > max2) begin
                        max2 = result;
                    end
                    if (!now_count) begin
                        second_maximum = max2;
                        current_state = 1'b0;
                    end
                end
            end
            default: ;
        endcase
    end

    always @(count) begin
        if(count) begin
            now_count = count;
        end
    end
    
endmodule