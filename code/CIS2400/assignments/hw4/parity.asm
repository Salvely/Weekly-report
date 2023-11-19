;; 16 bit value stored in R0
;; store the number of 1 in R1

    .CODE
    .ADDR 0X0000
    CONST R1, #0
LOOP
    CMPI R0, #0
    BRz END
    AND R2, R0, 0X1
    ADD R1, R1, R2
    SRL R0, R0, 0X1
    JMP LOOP
END
