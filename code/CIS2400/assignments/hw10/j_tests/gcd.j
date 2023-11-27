;;
;; gcd - Compute the greatest common divisor of two numbers using the Eucldiean algorithm
;;

defun gcd  ;  arguments - b, a
arg2 	   ;  b, a, RV, RA, FP, b
0 eq   	   ;  b, a, RV, RA, FP, (b == 0)
if   
arg1     ;  b, a, RV, RA, FP, a
else
arg2	   ;  b, a, RV, RA, FP, b
arg1 	   ;  b, a, RV, RA, FP, b, a
% 	   ;  b, a, RV, RA, FP, (a % b)
arg2 	   ;  b, a, RV, RA, FP, (a % b), b
gcd        ;  b, a, RV, RA, FP, (a % b), b, gcd((a % b),b)
endif
return


;;
;; main function - note that this calls 2 procedures, printnum and endl that are
;; actually written in C
;;

defun main
462 1071 gcd printnum endl ; print the gcd of 1071 and 462 which should be 21
return