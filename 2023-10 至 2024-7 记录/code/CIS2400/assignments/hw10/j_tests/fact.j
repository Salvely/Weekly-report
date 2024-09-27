;;
;; Factorial program
;;

defun fact ; n on stack
	arg1        	  ; n

	dup 1 ge     	  ; n (1 >= n) 
	if
   		1 
	else
   		dup 1 swap -	  ; n (n-1)
   		fact  	   	  ; n (n-1) (n-1)!
   		swap drop * 	  ; n!
	endif

return

;;
;; main function - note that this calls 2 procedures, printnum and endl that are
;; actually written in C
;;

defun main
	4 fact printnum endl  ; print the factorial of 4 on the ASCII display
	5 fact printnum endl  ; print the factorial of 5 on the ASCII display
	6 fact printnum endl  ; print the factorial of 6 on the ASCII display
	7 fact printnum endl  ; print the factorial of 7 on the ASCII display
return 