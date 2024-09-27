;;
;; xmas.j : Draw some boxes calling lc4_draw_rect
;;

defun main   
0x7C00 20 100 100 14 lc4_draw_rect
0x3300 20  80  80 24 lc4_draw_rect
0x7C00 20  60  60 34 lc4_draw_rect
0x3300 20  40  40 44 lc4_draw_rect
0x7FF0 20  20  20 54 lc4_draw_rect
return