;;
;; Simple program that uses print functions and while
;;


;;
;; main function - note that this calls 2 procedures, printnum and endl that are
;; actually written in C
;;

defun main
5
dup
  while
  printnum endl drop drop
  1 swap -
  dup
endwhile

return 