;;
;; lots_of_ifs.j : Defines a completely useless function just to exercise nested if statements
;;

defun testIfs	; called with parameter n on top of stack
arg1            ; move n to the top of the stack
dup 10 gt     	; (10 > n)

if              ; if #1

dup 5 gt       	;  (5 > n)
if              ; if #2
11              ; result is 11
else            ; else for if  #2
12              ; result is 12
endif           ; endif for if #2

else            ; else for if #1

dup 20 gt       ; (20 > n)

if              ; if #3
13              ; result is 13
else            ; else for if #3
14              ; result is 14
endif           ; endif for if #3

endif           ; endif for if #1

return

defun main
8 testIfs printnum endl
4 testIfs printnum endl
45 testIfs printnum endl
return