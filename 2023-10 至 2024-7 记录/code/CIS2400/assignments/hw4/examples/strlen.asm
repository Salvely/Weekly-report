;; strlen program
;; Calculates the length of a string who's address is loaded into R0
;; The lenght is stored in R2 and does not include the null-terminator character '\0'

;; Psuedo code:
;;
;; R0 = str_addr
;; R1 = memory[str_addr] // first character
;; R2 = 0 // length so far
;;
;; while (R1 != '\0') {
;;    R0 = R0 + 1
;;    R1 = memory[R0]
;;    R2 = R2 + 1
;; }

	;; This is the data section
	.DATA
	.ADDR x4000		; Start the data at address 0x4000
	
global_string
	.FILL x48   ; x48 is ASCII number for 'H'
	.FILL x45   ; x45 is ASCII number for 'E'
	.FILL x4C   ; x4C is ASCII number for 'L'
	.FILL x4C   ; x4C is ASCII number for 'L'
	.FILL x4F   ; x4F is ASCII number for 'O'
	.FILL x0    ; x0 is ASCII number for null-terminator '\0'

	;; Start of the code section
	.CODE
	.ADDR 0x0000		; Start the code at address 0x0000
INIT
	LEA R0, global_string	; R0 contains the address of the start of te array
        LDR R1, R0, #0          ; R1 contains the current character of the string
	CONST R2, 0		; R2 will contain our length calculation
TEST
	CMPI R1, x0		; check if the current counter is the null-termiantor (zero) yet
	BRz END                 ; if the current character is zero, we are done
BODY
	ADD R0, R0, #1		; increment the address
	LDR R1, R0, #0		; Load the next character into R1 
	ADD R2, R2, #1		; update the length
        JMP TEST                ; go back to the top of the loop

END
	NOP
