;;
;; xmas.j : Draw some boxes calling lc4_draw_rect
;;

defun main   
0x7000 0x0C00 or 0xFFEB not 0x64 0xFFFF and 100 14 lc4_draw_rect
return