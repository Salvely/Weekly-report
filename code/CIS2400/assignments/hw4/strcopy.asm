;; R0 should contain the address of the start of the string to be copied
;; R1 should contain the address of the start of the memory location where the copy should be stored.
;; you are allowed to modify the address stored in R0 and R1 over the duration of your program

    .DATA
    .ADDR 0x4000

global_string
    .FILL x48   ; x48 is ASCII number for 'H'
	.FILL x45   ; x45 is ASCII number for 'E'
	.FILL x4C   ; x4C is ASCII number for 'L'
	.FILL x4C   ; x4C is ASCII number for 'L'
	.FILL x4F   ; x4F is ASCII number for 'O'
	.FILL x0    ; x0 is ASCII number for null-terminator '\0'

new_string

    .CODE
    .ADDR 0x0000
    LEA R0, global_string ;; R0 stores the string to be copied
    LEA R1, new_string ;; R1 stores the new string to be copied

    CONST R2, #0 ;; R2 stores the length of the string
    ADD R3, R0, #0 ;; set pointer R3 = R0
LOOP1
    LDR R4, R3, #0 ;; store the value at mem[R3] in R4
    CMPI R4, #0 ;; compare R4 and x0
    BRz CALCLEN
    ADD R2, R2, #1
    ADD R3, R3, #1
    JMP LOOP1
CALCLEN
    CONST R4, #0 ;; set R4 = 0
LOOP2
    CMP R4, R2
    BRzp COPYEND
    ADD R5, R0, R4
    LDR R6, R5, #0

    ADD R5, R1, R4 ;; R1 uninitialize

    STR R6, R5, #0
    ADD R4, R4, #1 
    JMP LOOP2
COPYEND
    ADD R7, R1, R2
    CONST R6, x0
    STR R6, R7, #0
END