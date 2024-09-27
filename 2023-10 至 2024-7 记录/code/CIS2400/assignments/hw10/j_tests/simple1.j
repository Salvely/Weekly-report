;;
;; Very basic test - no ifs or comparisons
;;

defun main
5 3 2 * + printnum endl		;; Should output (3 * 2) + 5 = 11
3 4 5 rot * + printnum endl	;; Should output (3 * 5) + 4 = 19
return