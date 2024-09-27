;;
;; Prime program using while
;;

defun prime ; n on stack, generates the nth prime
arg1  ; N (t)
1     ; N 1 (t)
ge    ; go into if-2 iff 1>=N
if
  2   ; return 2 on N<=1
else
  2    ; int res = 2 // 2 (t)
  arg1 ; int n // 2 N (t)
  dup  ; 2 N N (t)
  1    ; 2 N N 1 (t)
  lt   ; go into while-etc iff 1 < N
  ; res n (1 < n)
  while
    ; res n
    swap  ; n res
    1     ; n res isprime=true
    swap  ; n isprime=t res (t)
    1     ; n isprime=t res 1 (t)
    +     ; n isprime=t res++ (t)
    dup   ; n isprime=t res res (t)
    2     ; n isprime=t res res i(2) (t)

    dup   ; n isprime res res i(2) i(2)
    rot   ; n isprime res i(2) i(2) res
    gt    ; n isprime=t res i(2) (res > i(2))
    while ; n isprime res i(2)
      dup   ; n isprime res i i
      rot   ; n isprime i i res
      dup   ; n isprime i i res res
      rot   ; n isprime i res res i
      swap  ; n isprime i res i res
      %     ; n isprime i res (res % i)
      0     ; n isprime i res (res%i) 0
      eq    ; n isprime i res (res%i==0)
      if    ; n isprime i res
        ;     n isprime i res
        rot  ; n i res isprime
        drop ; n i res
        0    ; n i res isprime=false
        rot  ; n res isprime=false i
        rot  ; n isprime=false i res
        ; n isprime=f i res
      endif
      swap ; n isprime res i
      1 ; n isprime res i 1
      + ; n isprime res i++
      ;   n isprime res i
      dup ; n isprime res i i
      rot ; n isprime i i res
      dup ; n isprime i i res res
      rot ; n isprime i res res i
      lt  ; n isprime i res (i < res)
      rot ; n isprime res (i<res) i
      rot ; n isprime (i < res) i res
      swap ; n isprime (i<res) res i
      rot ; n isprime res i (i < res)
    endwhile
    ; n isprime res i
    drop ; n isprime res
    swap ; n res isprime
    if ; n res
      swap ; res n
      1    ; res n 1
      swap ; res 1 n
      - ; res n--
      swap ; n res
    endif
    swap ; res n
    dup
    1 ; res n n 1
    lt ; res n (1<n)
    ; res n (1 < n)
  endwhile
drop
  
endif
return

return

;;
;; main function - note that this calls 2 procedures, printnum and endl that are
;; actually written in C
;;

defun main
1 prime printnum endl  ; print the 1st prime on the ASCII display
2 prime printnum endl  ; print the 2nd prime on the ASCII display
3 prime printnum endl  ; print the 3th prime on the ASCII display
4 prime printnum endl  ; print the 4th prime on the ASCII display
5 prime printnum endl  ; print the 5th prime on the ASCII display
6 prime printnum endl  ; print the 6th prime on the ASCII display
7 prime printnum endl  ; print the 7th prime on the ASCII display
return 