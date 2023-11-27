;;
;; xmas.j : Draw some boxes calling lc4_draw_rect
;;

defun main   
0x7C00 20 100 50 50 + 7 2 * lc4_draw_rect
return