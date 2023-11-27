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


defun fact_caller
arg1 fact
return 


defun main
4 fact_caller
0x3300 swap dup 10 20 lc4_draw_rect
3 fact_caller
0x7A00 swap dup 60 60 lc4_draw_rect
return

