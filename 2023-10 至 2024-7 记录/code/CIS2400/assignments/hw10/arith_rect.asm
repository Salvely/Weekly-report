   .CODE
   .FALIGN
main
   STR R7, R6, #-2
   STR R5, R6, #-4
   CONST R3, #4
   SUB R6, R6, R3
   ADD R5, R6, #0
   CONST R0, 0000
   HICONST R0, 0000
   STR R0, R6, #0
   CONST R1, #2
   SUB R6, R6, R1
   CONST R0, 0000
   HICONST R0, 0000
   STR R0, R6, #0
   CONST R1, #2
   SUB R6, R6, R1
   ADD R6, R6, #2
   LDR R0, R6, #0
   ADD R6, R6, #2
   LDR R1, R6, #0
   SUB R0, R0, R1
   STR R0, R6, #0
   CONST R1, #2
   SUB R6, R6, R1
   ADD R6, R6, #2
   LDR R0, R6, #0
   ADD R6, R6, #2
   LDR R1, R6, #0
   SUB R0, R0, R1
   STR R0, R6, #0
   CONST R1, #2
   SUB R6, R6, R1
   ADD R6, R6, #2
   LDR R0, R6, #0
   ADD R6, R6, #2
   LDR R1, R6, #0
   SUB R0, R0, R1
   STR R0, R6, #0
   CONST R1, #2
   SUB R6, R6, R1
   ADD R6, R6, #2
   LDR R0, R6, #0
   ADD R6, R6, #2
   LDR R1, R6, #0
   MUL R0, R0, R1
   STR R0, R6, #0
   CONST R1, #2
   SUB R6, R6, R1
   CONST R0, 0x63
   HICONST R0, 0000
   STR R0, R6, #0
   CONST R1, #2
   SUB R6, R6, R1
   CONST R0, 0x01
   HICONST R0, 0000
   STR R0, R6, #0
   CONST R1, #2
   SUB R6, R6, R1
   ADD R6, R6, #2
   LDR R0, R6, #0
   ADD R6, R6, #2
   LDR R1, R6, #0
   ADD R0, R0, R1
   STR R0, R6, #0
   CONST R1, #2
   SUB R6, R6, R1
   CONST R0, 0x0a
   HICONST R0, 0000
   STR R0, R6, #0
   CONST R1, #2
   SUB R6, R6, R1
   CONST R0, 0xe8
   HICONST R0, 0x03
   STR R0, R6, #0
   CONST R1, #2
   SUB R6, R6, R1
   ADD R6, R6, #2
   LDR R0, R6, #0
   ADD R6, R6, #2
   LDR R1, R6, #0
   DIV R0, R0, R1
   STR R0, R6, #0
   CONST R1, #2
   SUB R6, R6, R1
   CONST R0, 0x0e
   HICONST R0, 0000
   STR R0, R6, #0
   CONST R1, #2
   SUB R6, R6, R1
   JSR lc4_draw_rect
   ADD R6, R6, #2
   LDR R7, R6, #2
   ADD R6, R5, #0
   STR R7, R5, #4
   LDR R7, R5, #2
   LDR R5, R5, #0
   RET

