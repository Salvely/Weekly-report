;;
;; Simple j program
;;

defun square ; called with parameter n
arg1   ;  n
dup *  ; (n*n)
return

defun main
4 square printnum endl ; print 4 squared
5 square printnum endl ; print 5 squared
return