;;; Adapted from code by Amir Roth; CJT Oct 17, 2010

;;; OS Code
	.OS
	.CODE
	.ADDR x8000

; the TRAP vector table
	JMP TRAP_GETC	; x00
	JMP TRAP_PUTC	; x01
	JMP TRAP_DRAW_H_LINE	; x02
	JMP TRAP_DRAW_V_LINE	; x03
	JMP TRAP_GETC_ECHO	; x04
	JMP BAD_TRAP	; x05
	JMP BAD_TRAP	; x06
	JMP BAD_TRAP	; x07
	JMP TRAP_PUTS		; x08
	JMP BAD_TRAP	; x09
	JMP TRAP_DRAW_SQUARE	; x0A
	JMP TRAP_DRAW_SPRITE	; x0B
	JMP BAD_TRAP	; x0C
	JMP BAD_TRAP	; x0D
	JMP BAD_TRAP	; x0E
	JMP TRAP_GET_SEED_STATUS	; x0F
	JMP TRAP_GET_SEED       	; x10
	JMP BAD_TRAP	; x11
	JMP BAD_TRAP	; x12
	JMP BAD_TRAP	; x13
	JMP BAD_TRAP	; x14
	JMP BAD_TRAP	; x15
	JMP BAD_TRAP	; x16
	JMP BAD_TRAP	; x17
	JMP BAD_TRAP	; x18
	JMP BAD_TRAP	; x19
	JMP BAD_TRAP	; x1A
	JMP BAD_TRAP	; x1B
	JMP BAD_TRAP	; x1C
	JMP BAD_TRAP	; x1D
	JMP BAD_TRAP	; x1E
	JMP BAD_TRAP	; x1F
	JMP BAD_TRAP	; x20
	JMP BAD_TRAP	; x21
	JMP BAD_TRAP	; x22
	JMP BAD_TRAP	; x23
	JMP BAD_TRAP	; x24
	JMP TRAP_HALT		; x25
	JMP TRAP_RESET_VMEM	; x26
	JMP TRAP_BLT_VMEM	; x27
	JMP BAD_TRAP	; x28
	JMP BAD_TRAP	; x29
	JMP BAD_TRAP	; x2A
	JMP BAD_TRAP	; x2B
	JMP BAD_TRAP	; x2C
	JMP BAD_TRAP	; x2D
	JMP BAD_TRAP	; x2E
	JMP BAD_TRAP	; x2F
	JMP BAD_TRAP	; x30
	JMP BAD_TRAP	; x31
	JMP BAD_TRAP	; x32
	JMP BAD_TRAP	; x33
	JMP BAD_TRAP	; x34
	JMP BAD_TRAP	; x35
	JMP BAD_TRAP	; x36
	JMP BAD_TRAP	; x37
	JMP BAD_TRAP	; x38
	JMP BAD_TRAP	; x39
	JMP BAD_TRAP	; x3A
	JMP BAD_TRAP	; x3B
	JMP BAD_TRAP	; x3C
	JMP BAD_TRAP	; x3D
	JMP BAD_TRAP	; x3E
	JMP BAD_TRAP	; x3F
	JMP BAD_TRAP	; x40
	JMP BAD_TRAP	; x41
	JMP BAD_TRAP    ; x42
	JMP BAD_TRAP	; x43
	JMP BAD_TRAP	; x44
	JMP BAD_TRAP	; x45
	JMP BAD_TRAP	; x46
	JMP BAD_TRAP	; x47
	JMP BAD_TRAP	; x48
	JMP BAD_TRAP	; x49
	JMP BAD_TRAP	; x4A
	JMP BAD_TRAP	; x4B
	JMP BAD_TRAP	; x4C
	JMP BAD_TRAP	; x4D
	JMP BAD_TRAP    ; x4E
	JMP BAD_TRAP    ; x4F
	JMP BAD_TRAP    ; x50
	JMP BAD_TRAP	; x51
	JMP BAD_TRAP	; x52
	JMP BAD_TRAP	; x53
	JMP BAD_TRAP	; x54
	JMP BAD_TRAP	; x55
	JMP BAD_TRAP	; x56
	JMP BAD_TRAP	; x57
	JMP BAD_TRAP	; x58
	JMP BAD_TRAP	; x59
	JMP BAD_TRAP	; x5A
	JMP BAD_TRAP	; x5B
	JMP BAD_TRAP	; x5C
	JMP BAD_TRAP	; x5D
	JMP BAD_TRAP	; x5E
	JMP BAD_TRAP	; x5F
	JMP BAD_TRAP	; x60
	JMP BAD_TRAP	; x61
	JMP BAD_TRAP	; x62
	JMP BAD_TRAP	; x63
	JMP BAD_TRAP	; x64
	JMP BAD_TRAP	; x65
	JMP BAD_TRAP	; x66
	JMP BAD_TRAP	; x67
	JMP BAD_TRAP	; x68
	JMP BAD_TRAP	; x69
	JMP BAD_TRAP	; x6A
	JMP BAD_TRAP	; x6B
	JMP BAD_TRAP	; x6C
	JMP BAD_TRAP	; x6D
	JMP BAD_TRAP	; x6E
	JMP BAD_TRAP	; x6F
	JMP BAD_TRAP	; x70
	JMP BAD_TRAP	; x71
	JMP BAD_TRAP	; x72
	JMP BAD_TRAP	; x73
	JMP BAD_TRAP	; x74
	JMP BAD_TRAP	; x75
	JMP BAD_TRAP	; x76
	JMP BAD_TRAP	; x77
	JMP BAD_TRAP	; x78
	JMP BAD_TRAP	; x79
	JMP BAD_TRAP	; x7A
	JMP BAD_TRAP	; x7B
	JMP BAD_TRAP	; x7C
	JMP BAD_TRAP	; x7D
	JMP BAD_TRAP	; x7E
	JMP BAD_TRAP	; x7F
	JMP BAD_TRAP	; x80
	JMP BAD_TRAP	; x81
	JMP BAD_TRAP	; x82
	JMP BAD_TRAP	; x83
	JMP BAD_TRAP	; x84
	JMP BAD_TRAP	; x85
	JMP BAD_TRAP	; x86
	JMP BAD_TRAP	; x87
	JMP BAD_TRAP	; x88
	JMP BAD_TRAP	; x89
	JMP BAD_TRAP	; x8A
	JMP BAD_TRAP	; x8B
	JMP BAD_TRAP	; x8C
	JMP BAD_TRAP	; x8D
	JMP BAD_TRAP	; x8E
	JMP BAD_TRAP	; x8F
	JMP BAD_TRAP	; x90
	JMP BAD_TRAP	; x91
	JMP BAD_TRAP	; x92
	JMP BAD_TRAP	; x93
	JMP BAD_TRAP	; x94
	JMP BAD_TRAP	; x95
	JMP BAD_TRAP	; x96
	JMP BAD_TRAP	; x97
	JMP BAD_TRAP	; x98
	JMP BAD_TRAP	; x99
	JMP BAD_TRAP	; x9A
	JMP BAD_TRAP	; x9B
	JMP BAD_TRAP	; x9C
	JMP BAD_TRAP	; x9D
	JMP BAD_TRAP	; x9E
	JMP BAD_TRAP	; x9F
	JMP BAD_TRAP	; xA0
	JMP BAD_TRAP	; xA1
	JMP BAD_TRAP	; xA2
	JMP BAD_TRAP	; xA3
	JMP BAD_TRAP	; xA4
	JMP BAD_TRAP	; xA5
	JMP BAD_TRAP	; xA6
	JMP BAD_TRAP	; xA7
	JMP BAD_TRAP	; xA8
	JMP BAD_TRAP	; xA9
	JMP BAD_TRAP	; xAA
	JMP BAD_TRAP	; xAB
	JMP BAD_TRAP	; xAC
	JMP BAD_TRAP	; xAD
	JMP BAD_TRAP	; xAE
	JMP BAD_TRAP	; xAF
	JMP BAD_TRAP	; xB0
	JMP BAD_TRAP	; xB1
	JMP BAD_TRAP	; xB2
	JMP BAD_TRAP	; xB3
	JMP BAD_TRAP	; xB4
	JMP BAD_TRAP	; xB5
	JMP BAD_TRAP	; xB6
	JMP BAD_TRAP	; xB7
	JMP BAD_TRAP	; xB8
	JMP BAD_TRAP	; xB9
	JMP BAD_TRAP	; xBA
	JMP BAD_TRAP	; xBB
	JMP BAD_TRAP	; xBC
	JMP BAD_TRAP	; xBD
	JMP BAD_TRAP	; xBE
	JMP BAD_TRAP	; xBF
	JMP BAD_TRAP	; xC0
	JMP BAD_TRAP	; xC1
	JMP BAD_TRAP	; xC2
	JMP BAD_TRAP	; xC3
	JMP BAD_TRAP	; xC4
	JMP BAD_TRAP	; xC5
	JMP BAD_TRAP	; xC6
	JMP BAD_TRAP	; xC7
	JMP BAD_TRAP	; xC8
	JMP BAD_TRAP	; xC9
	JMP BAD_TRAP	; xCA
	JMP BAD_TRAP	; xCB
	JMP BAD_TRAP	; xCC
	JMP BAD_TRAP	; xCD
	JMP BAD_TRAP	; xCE
	JMP BAD_TRAP	; xCF
	JMP BAD_TRAP	; xD0
	JMP BAD_TRAP	; xD1
	JMP BAD_TRAP	; xD2
	JMP BAD_TRAP	; xD3
	JMP BAD_TRAP	; xD4
	JMP BAD_TRAP	; xD5
	JMP BAD_TRAP	; xD6
	JMP BAD_TRAP	; xD7
	JMP BAD_TRAP	; xD8
	JMP BAD_TRAP	; xD9
	JMP BAD_TRAP	; xDA
	JMP BAD_TRAP	; xDB
	JMP BAD_TRAP	; xDC
	JMP BAD_TRAP	; xDD
	JMP BAD_TRAP	; xDE
	JMP BAD_TRAP	; xDF
	JMP BAD_TRAP	; xE0
	JMP BAD_TRAP	; xE1
	JMP BAD_TRAP	; xE2
	JMP BAD_TRAP	; xE3
	JMP BAD_TRAP	; xE4
	JMP BAD_TRAP	; xE5
	JMP BAD_TRAP	; xE6
	JMP BAD_TRAP	; xE7
	JMP BAD_TRAP	; xE8
	JMP BAD_TRAP	; xE9
	JMP BAD_TRAP	; xEA
	JMP BAD_TRAP	; xEB
	JMP BAD_TRAP	; xEC
	JMP BAD_TRAP	; xED
	JMP BAD_TRAP	; xEE
	JMP BAD_TRAP	; xEF
	JMP BAD_TRAP	; xF0
	JMP BAD_TRAP	; xF1
	JMP BAD_TRAP	; xF2
	JMP BAD_TRAP	; xF3
	JMP BAD_TRAP	; xF4
	JMP BAD_TRAP	; xF5
	JMP BAD_TRAP	; xF6
	JMP BAD_TRAP	; xF7
	JMP BAD_TRAP	; xF8
	JMP BAD_TRAP	; xF9
	JMP BAD_TRAP	; xFA
	JMP BAD_TRAP	; xFB
	JMP BAD_TRAP	; xFC
	JMP BAD_TRAP	; xFD
	JMP BAD_TRAP	; xFE
	JMP BAD_TRAP	; xFF

;;; OS memory address constants
USER_CODE_ADDR 	.UCONST x0000
OS_CODE_ADDR 	.UCONST x8000

OS_GLOBALS_ADDR .UCONST xA000
OS_STACK_ADDR 	.UCONST xBFFF
OS_VIDEO_ADDR 	.UCONST xC000

OS_RNGSR_ADDR   .UCONST xAFF0           ; status of RNG register. 0 if seed
                                        ; hasn't been generated yet. non-zero
                                        ; if the seed has been generated
OS_RNGDR_ADDR   .UCONST xAFF2           ; register to contain a 16-bit 'seed'
                                        ; that stays fixed once set. Based on
                                        ; how long it takes for user to input
                                        ; their first input through Keyboard
                                        ; The seed should then be used at the
                                        ; user level with some kind of
                                        ; psuedo-random number generator
                                        ; like an LFSR
				
OS_KBSR_ADDR	.UCONST xFE00		; keyboard status register
OS_KBDR_ADDR	.UCONST xFE02		; keyboard data register
OS_ADSR_ADDR	.UCONST xFE04		; display status register
OS_ADDR_ADDR	.UCONST xFE06		; display data register
OS_TSR_ADDR	.UCONST xFE08		; timer register
OS_TIR_ADDR	.UCONST xFE0A		; timer interval register
OS_VDCR_ADDR	.UCONST xFE0C	        ; video display control register
OS_MCR_ADDR	.UCONST xFFEE		; machine control register

TIM_INIT 	.UCONST #320

MASK_L15 	.UCONST x7FFF
MASK_H4		.UCONST xF000
MASK_H1		.UCONST x8000
	
;;; OS_START - operating system entry point (always starts at x8200)
	
	.CODE
	.ADDR x8200
OS_START
	;; initialize timer
	LC R0, TIM_INIT
	LC R1, OS_TIR_ADDR
	STR R0, R1, #0

	;; R7 <- User code address (x0000)
	LC R7, USER_CODE_ADDR 
	RTI			; RTI removes the privilege bit

;;; Video memory
	.DATA
	.ADDR xC000	
OS_VIDEO_MEM .BLKW x3E00

;;; Space for globals
	.ADDR xA000
OS_GLOBALS_MEM	.BLKW x1000


OS_VIDEO_NUM_COLS .UCONST #128
OS_VIDEO_NUM_ROWS .UCONST #124		
	
;;; TRAP_HALT - trap handler for halting machine

;;; BAD_TRAP - code to execute for undefined trap
	.CODE
BAD_TRAP
	JMP TRAP_HALT	; execute HALT

;;; TRAP_HALT - halts the program and jumps to OS_START
	.CODE
TRAP_HALT	
	; clear run bit in MCR
	LC R3, OS_MCR_ADDR
	LDR R0, R3, #0
	LC R1, MASK_L15
	AND R0,R0,R1
	STR R0, R3, #0
	JMP OS_START 	; restart machine

	
;;; TRAP_RESET_VMEM - In double-buffered video mode, resets the video
;;; display, i.e., turns it to black.
;;; Inputs - none
;;; Outputs - none
	.CODE	
TRAP_RESET_VMEM
	LC R4, OS_VDCR_ADDR
	CONST R5, #1
	STR R5, R4, #0
	RTI

;;; TRAP_BLT_VMEM - In double-buffered video mode, copies the contents
;;; of video memory to the video display.
;;; Inputs - none
;;; Outputs - none
	.CODE
TRAP_BLT_VMEM
	LC R4, OS_VDCR_ADDR
	CONST R5, #2
	STR R5, R4, #0
	RTI
	
;;; TRAP_GETC - Check for a character from the keyboard
;;; Inputs - none
;;; Outputs - R0 the value of the KBSR - the MSB is 1 if a character was read
;;; 	      R1 the value of the character read from the keyboard

	.CODE
TRAP_GETC
        
        LC R4, OS_RNGSR_ADDR
        LDR R4, R4, #0
        BRnp GETC_START

        LEA R4 OS_GLOBALS_MEM
        STR R7, R4, #0
        JSR OS_GEN_SEED
        LEA R4 OS_GLOBALS_MEM
        LDR R7, R4, #0
                                
GETC_START
	LC R4, OS_KBSR_ADDR
	LDR R4, R4, #0		; Read the KBSR into R0
	BRzp GETC_START		; Check if the MSB is zero

	LC R4, OS_KBDR_ADDR
	LDR R1, R4, #0		; Read the character into R1
	
GETC_END

	RTI
	
;;; TRAP_PUTC - Put a character on the console
;;; Inputs - R0 - ASCII caharacter value to be output
;;; Outputs - none

	.CODE
TRAP_PUTC
	LC R4, OS_ADSR_ADDR
	LDR R1, R4, #0
	BRzp TRAP_PUTC		; Loop while the MSB is zero

	LC R4, OS_ADDR_ADDR
	STR R0, R4, #0		; Write out the character
	
	RTI


;;; TRAP_DRAW_H_LINE - Draw a horizontal line on the video display
;;; Inputs R0 - row to draw on
;;;        R1 - column address 1
;;;        R2 - column address 2
;;;        R3 - color to draw with
;;;  Outputs - none

	.CODE
TRAP_DRAW_H_LINE
;;;  First we figure out whether R1 or R2 is larger - they should both be 0-127
	CMP R1, R2
	BRnz NO_SWAP_H
;;;  Swap R1 and R2 using R4
	ADD R4, R1, #0
	ADD R1, R2, #0
	ADD R2, R4, #0
;;; Now R1 <= R2
NO_SWAP_H
	LEA R4, OS_VIDEO_MEM
	LC R5, OS_VIDEO_NUM_COLS

	MUL R5, R0, R5		; Compute (row * NUM_COLS)
	ADD R5, R5, R1		; Compute (row * NUM_COLS) + col
	ADD R4, R4, R5		; Add the offset to the start of video memory
R1_LE_R2_H
	STR R3, R4, #0		; Fill in the pixel
	ADD R4, R4, #1		; Update the pixel address
	ADD R1, R1, #1		; Update R1

	CMP R1, R2		; Test whether R1 <= R2
	BRnz R1_LE_R2_H

	RTI

	
;;; TRAP_DRAW_V_LINE - Draw a horizontal line on the video display
;;; Inputs R0 - column to draw on
;;;        R1 - row address 1
;;;        R2 - row address 2
;;;        R3 - color to draw with
;;;  Outputs - none

	.CODE
TRAP_DRAW_V_LINE
;;;  First we figure out whether R1 or R2 is larger - they should both be 0-123
	CMP R1, R2
	BRnz NO_SWAP_V
;;;  Swap R1 and R2 using R4
	ADD R4, R1, #0
	ADD R1, R2, #0
	ADD R2, R4, #0
NO_SWAP_V
;;; Now R1 <= R2
	LEA R4, OS_VIDEO_MEM
	LC R5, OS_VIDEO_NUM_COLS

	MUL R6, R1, R5		; Compute (R1 * NUM_COLS)
	ADD R6, R6, R0		; Compute (row * NUM_COLS) + col
	ADD R4, R4, R6		; Add the offset to the start of video memory
R1_LE_R2_V
	STR R3, R4, #0		; Fill in the pixel
	ADD R4, R4, R5		; Update the pixel address
	ADD R1, R1, #1		; Update R1

	CMP R1, R2		; Test whether R1 <= R2
	BRnz R1_LE_R2_V

	RTI


;;; TRAP_PUTS - for writing null-terminated string to ASCII display
;;; Input
;;;   r0 - address of first character in string
;;; Output
;;;   none

	.CODE
TRAP_PUTS

	;; R2 = the OS_ADSR_ADDR status value

	;; R0 = the string address
	;; R1 = the counter register
	;; R3 = the character read
	;; R2 = the current address of the character

	;; R4 = the OS_ADDR_ADDR data value
	
	;; keep check while OS_ADSR_ADDR value = 0
	;; if it's 1, start printing character until it reaches '\0'

CHECK
	LC R2, OS_ADSR_ADDR
	LDR R2, R2, #0
	CMPI R2, #0
	BRz CHECK
	
	CONST R1, #0
	LC R4, OS_ADDR_ADDR
LOOP
	ADD R2, R0, R1 ;; get the value at R0[R1]
	LDR R3, R2, #0 ;; store it in R3
	STR R3, R4, #0 ;; print it to R4

	CMPI R3, x00   ;; judge if it's '\0', if it is, then break the loop
	BRz ENDLOOP
	ADD R1, R1, #1
	JMP LOOP
ENDLOOP
	RTI


;;; TRAP_GETC_ECHO - waits for a keypress and echos it to the ASCII display
;;; Input
;;;   none
;;; Output
;;;   r5 - an integer indicating the keypress code
;;;       

	.CODE
TRAP_GETC_ECHO
;;;  This version of the code does not respect the stack
        LC R4, OS_RNGSR_ADDR
        LDR R4, R4, #0
        BRnp EGETC

        LEA R4 OS_GLOBALS_MEM
        STR R7, R4, #0
        JSR OS_GEN_SEED
        LEA R4 OS_GLOBALS_MEM
        LDR R7, R4, #0

EGETC	LC R0, OS_KBSR_ADDR	; Loop while KBSR[15] == 0
	LDR R0, R0, #0
	BRzp EGETC
	LC R0, OS_KBDR_ADDR
	LDR R5, R0, #0 		; Read the Keyboard character

EGETC_E	LC R1, OS_ADSR_ADDR	; Loop while ADSR[15] == 0 ie output not ready
	LDR R1, R1, #0
	BRzp EGETC_E
	LC R1, OS_ADDR_ADDR
	STR R5, R1, #0
	RTI

;;; CHECK_BOUNDARY - check the boundary value for R0 and R1
;;; Input: r0, r1
	.CODE
	.FALIGN
CHECK_BOUNDARY
	CMPI R0, #0
	BRn SET0
	JMP ENDSET0 
SET0
	CONST R0, #0
ENDSET0

	CMPIU R0, #127
	BRp SET1
	JMP ENDSET1
SET1
	CONST R0, #127
ENDSET1

	CMPI R1, #0
	BRn SET2
	JMP ENDSET2 
SET2
	CONST R1, #0
ENDSET2

	CMPIU R1, #123
	BRp SET3
	JMP ENDSET3
SET3
	CONST R1, #123
ENDSET3
	RET


;;; TRAP_DRAW_SQUARE - draws a square block on the screen.
;;; Input
;;;   r0 - video column (left)
;;;   r1 - video row (upper)
;;;   r2 - width & height of block in pixels
;;;   r3 - color
;;; Output
;;;   video memory will be updated to place block of approriate color

TEMPS .UCONST X4200

	.CODE
TRAP_DRAW_SQUARE

;;;
;;;  EXTRA CREDIT: add bounds checking. e.g. If the sqaure would go "off the screen"
;;;                either across the top/bottom/left/right edge, don't draw the pixels
;;;                that would go over the edge. Still draw all other pixels of the square
;;;                if there are any. We highly suggest you don't try this until you have
;;;                gotten the trap to work without checking for boundaries.
	
	ADD R4, R7, #0
	JSR CHECK_BOUNDARY
	CONST R7, #0
	ADD R7, R4, #0

	ADD R5, R1, #0
	ADD R6, R0, #0 ;; R6 = R0

	;; R0: the width
	ADD R0,R0,R2
	;; R1: the height
	ADD R1,R1,R2

	; TEMPS = R6
	LC R2, TEMPS
	STR R6, R2, #0

	ADD R4, R7, #0
	JSR CHECK_BOUNDARY
	CONST R7, #0
	ADD R7, R4, #0
	
	;; r4 - store the base address of the device
	LC R4, OS_VIDEO_ADDR

OUTER
	CMP R5, R1
	BRzp ENDOUTER
	
	LC R2, TEMPS
	LDR R6, R2, #0

INNER
	CMP R6, R0
	BRzp ENDINNER
	
	;; get the address of the pixel in R2
	;; location = R4 + (r5 * OS_VIDEO_NUM_COLS) + r6 
	LC R2, OS_VIDEO_NUM_COLS
	MUL R2, R2, R5
	ADD R2, R2, R6
	ADD R2, R2, R4

	;; store the current value to the pixel
	STR R3, R2, #0

	ADD R6, R6, #1
	JMP INNER
ENDINNER

	ADD R5, R5, #1
	JMP OUTER
ENDOUTER

	RTI
	
;;; TRAP_DRAW_SPRITE - draws a 15x15 sprite on the screen.
;;; Input
;;;   r0 - video column (left)
;;;   r1 - video row (upper) 
;;;   r2 - color
;;;   r3 - Address of sprite bitmap - an array of 15 words
;;; Output
;;;   video memory will be updated to include sprite of approriate color
	.CODE
TRAP_DRAW_SPRITE

;; STORE R0, R1 and R7
	LEA R6, OS_GLOBALS_MEM
	STR R0, R6, #0
	STR R1, R6, #1
	STR R7, R6, #2

;;; for (i=0; i < 15; ++i, ++ptr) {
;;;    temp = i + start_row;
;;;    if (temp < 0) continue;
;;;    if (temp >= NUM_ROWS) end;
;;;    bits = *ptr;
;;;    col = start_col + 14;
;;;    temp = VIDEO_MEM + (temp * 128) + col
;;;    do {
;;;       if (col >= 0 && col < NUM_COLS && bits & 0x0002)
;;;          *temp = color
;;;       --col;
;;;       --temp;
;;;       bits >>= 1;
;;;    } while (bits)
;;; }
;;; 
;;; Register Allocation
;;;   R0 - i
;;;   R1 - temp
;;;   R2 - color
;;;   R3 - ptr
;;;   R4 - bits
;;;   R5 - col
;;;   R6 - scratch
;;;   R7 - scratch

	CONST R0, #0		; i = 0
	JMP TRAP_DRAW_SPRITE_F12

TRAP_DRAW_SPRITE_F11

	LEA R6, OS_GLOBALS_MEM
	LDR R1, R6, #1		; load start_row
	ADD R1, R1, R0		; temp = i + start_row
	BRn TRAP_DRAW_SPRITE_F13 ; temp < 0 continue
	LC R7 OS_VIDEO_NUM_ROWS
	CMP R1, R7
	BRzp TRAP_DRAW_SPRITE_END ; (temp >= NUM_ROWS) end
	LDR R4, R3, #0		  ; bits = *ptr

	LEA R6, OS_GLOBALS_MEM
	LDR R5, R6, #0		; load start_col
	ADD R5, R5, #14		; col = start_col + 14

	SLL R1, R1, #7		; temp = temp * 128
	ADD R1, R1, R5		; temp = temp + col
	LEA R7, OS_VIDEO_MEM
	ADD R1, R1, R7		; temp = temp + OS_VIDEO_MEM

	LC R7, OS_VIDEO_NUM_COLS

TRAP_DRAW_SPRITE_W1

	CMPI R5, #0
	BRn TRAP_DRAW_SPRITE_W2	; col < 0 continue

	CMP R5, R7
	BRzp TRAP_DRAW_SPRITE_W2 ; col >= NUM_COLS continue

	AND R6, R4, 0x02
	BRz TRAP_DRAW_SPRITE_W2	; bits & 0x2 == 0 continue
	
	STR R2, R1, 0		; *temp = color
TRAP_DRAW_SPRITE_W2
	ADD R5, R5, #-1		; --col
	ADD R1, R1, #-1		; --temp
	SRL R4, R4, #1		; bits >>= 1
	
	BRnp TRAP_DRAW_SPRITE_W1
	
TRAP_DRAW_SPRITE_F13	
	ADD R0, R0, #1		; ++i
	ADD R3, R3, #1		; ++ptr
TRAP_DRAW_SPRITE_F12
	CMPI R0, #15
	BRn TRAP_DRAW_SPRITE_F11

	
TRAP_DRAW_SPRITE_END
	LEA R6, OS_GLOBALS_MEM
	LDR R7, R6, #2
	RTI

;;; TRAP_GET_SEED_STATUS - returns whether a seed has been generated yet
;;; Input
;;;   none
;;; Output
;;;   R0 will contain non-zero if a seed has been generated
;;;   zero if it hasn't been generated
	.CODE
TRAP_GET_SEED_STATUS
        LC R0 OS_RNGSR_ADDR
        LDR R0, R0, #0
        RTI

;;; TRAP_GET_SEED - returns a "randomly" generated seed
;;; Input
;;;   none
;;; Output
;;;   R0 will contain the randomly genrerated seed
;;;   undefined behavior if it hasn't been generated
	.CODE
TRAP_GET_SEED
        LC R0 OS_RNGDR_ADDR
        LDR R0, R0, #0
        RTI

; Subroutine used by getc and getc_echo to generate the first random seed.
; Made into a subroutine to keep readability of getc and getc_echo higher.
; If you are a student reading this, you can pretty much ignore this, it
; should have no other affects other than setting up things for random
; number generation
	.CODE
        .FALIGN
OS_GEN_SEED
        LC R0, OS_RNGSR_ADDR
        LDR R0, R0, #0
        BRz OS_GEN_SEED_START
        RET
OS_GEN_SEED_START
        LC R0, OS_KBSR_ADDR
        LC R1, OS_TSR_ADDR
        LC R2, OS_TIR_ADDR
        CONST R3, #0
OS_GEN_SEED_LOOP
        LDR R4, R0, #0
        BRn OS_GEN_SEED_END
        LDR R4, R1, #0
        BRzp OS_GEN_SEED_LOOP
        ADD R3, R3, #1
        CONST R4, #10
        STR R4, R2, #0
        JMP OS_GEN_SEED_LOOP
OS_GEN_SEED_END
        ; set status and seed register
        LC R0, OS_RNGDR_ADDR
        STR R3, R0, #0
        CONST R3, #1
        LC R0, OS_RNGSR_ADDR
        STR R3, R0, #0
        RET

