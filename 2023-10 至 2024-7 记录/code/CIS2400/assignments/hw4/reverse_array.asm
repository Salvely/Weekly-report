;; R0 should contain the address of the start of the array to be reversed
;; R1 should contain the length of the array. 

    .DATA
    .ADDR 0X4000

global_array:
    .FILL #1
    .FILL #2
    .FILL #3
    .FILL #4
    .FILL #5

    .CODE
    .ADDR 0X0000
    LEA R0, global_array ; R0 as the array
    CONST R1, #5 ; R1 as the length of the array
    CONST R2, #0 ; R2 as the counter i
    CONST R7, #2
    DIV R3, R1, R7 ; R3 as the iteration times

LOOP
    CMP R2, R3
    BRzp END

    ;; int temp = a[i]
    ADD R4, R0, R2 ;; get the address at (R0 + i)
    LDR R5, R4, #0 ;; decomposs the value at the address, store it in R5

    ;; a[i] = a[length - 1 - i];
    ;; get the address at R0 + (length - 1 - i) -> R6
    CONST R7, #1
    SUB R6, R1, R7
    SUB R6, R6, R2
    ADD R6, R0, R6
    ;; decomposs the value at the address -> R7
    LDR R7, R6, #0
    ;; use STR, store it(R7) in R4 + 0
    STR R7, R4, #0

    ;; a[length - 1 - i] = temp; -> mem[R6] = R5
    STR R5, R6, #0
    
    ;; R2 += 1
    ADD R2, R2, #1
    JMP LOOP
END