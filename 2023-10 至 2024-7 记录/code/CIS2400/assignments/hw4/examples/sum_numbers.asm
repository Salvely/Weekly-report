;; sum_numbers program
;; Calculates the sum of integers of an array who's address is loaded into R0
;; and who's length is stored in R1. The final sum is stored in R2.

;; Psuedo code:
;;
;; R0 = array_addr
;; R1 = array_len
;; R2 = 0 // sum so far
;; R3 = memory[R0] // current integer
;;
;; while (R1 != 0) {
;;    R3 = memory[R0] // current integer
;;    R2 = R2 + R3
;;    R0 = R0 + 1
;;    R1 = R1 - 1
;; }

	;; This is the data section
	.DATA
	.ADDR x4000		; Start the data at address 0x4000
	
global_array
	.FILL #11
	.FILL #7
	.FILL #6
	.FILL #2
	.FILL #-5

	;; Start of the code section
	.CODE
	.ADDR 0x0000		; Start the code at address 0x0000
INIT
	LEA R0, global_array	; R0 contains the address of the start of te array
	CONST R1, 5		; R1 is our loop counter init to 5 (5 is the length of the array)
	CONST R2, 0		; R2 stores the running sum init to 0
TEST
	CMPI R1, #0		; check if the loop counter is zero yet
	BRz END                 ; if loop counter is zero, we are done
BODY
	LDR R3, R0, #0		; Load the data value into R3  
	ADD R2, R2, R3		; update the sum
	ADD R0, R0, #1		; increment the address
	ADD R1, R1, #-1		; decrement the loop counter
        JMP TEST                ; go back to the top of the loop

END
	NOP
