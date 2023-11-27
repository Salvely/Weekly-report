;;
;; xmas.j : Draw some boxes calling lc4_draw_rect
;;

defun main   
0x7000 0x0C00 + 50 dup + 10 30 - swap 40 drop 2 28 / swap 100 rot lc4_draw_rect
;; (0x7C00) (100) (20) swap (14) (100) rot
;; 0x7C00 20 100 14 100 rot
return