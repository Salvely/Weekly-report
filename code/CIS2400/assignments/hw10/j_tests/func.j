;;
;; xmas.j : Draw some boxes calling lc4_draw_rect
;;

defun times_5
arg1
5 *
return

defun half
2 arg1 /
return

defun plus_50
arg1 50 +
return

defun main   
0x7C00 20 times_5 100 14 lc4_draw_rect
return