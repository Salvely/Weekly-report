;;
;; xmas.j : Draw some boxes calling lc4_draw_rect
;;

defun main
5 5 eq
if
0x7C00 20 100 100 14 lc4_draw_rect
else
0x7FF0 20  20  20 54 lc4_draw_rect
endif
return