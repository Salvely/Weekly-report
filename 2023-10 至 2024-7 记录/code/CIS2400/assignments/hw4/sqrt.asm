;; R0 is set to a 2C value greater than or equal to 0
;; determine the integer sqaure root of R0 and report the answer in R1.
;; At the end of your program R1 should contain the intger square root of R0. 

    .CODE 
    .ADDR 0X0000
    CONST R1, #1
LOOP
    MUL R2,R1,R1
    CMP R2,R0
    BRzp END
    ADD R1,R1,#1
    JMP LOOP
END
    
     

