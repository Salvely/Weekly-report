;;
;; program to test nested while
;;

defun testWhile  ;; called with one param N
1                 ; res=1
arg1        	  ; res=N?/n? n // inv:res==N?/n? where f(x)=x?=1*(product of all odd numbers y where 1<=y<=x), and N is original arg

dup               ; res=N?/n? n n
while             ; res=N?/n? n // inv:n>0
  ; do the mod2 check
  dup             ; res=N?/n? n n
  2               ; res=N?/n? n n 2
  swap            ; res=N?/n? n 2 n
  %               ; res=N?/n? n (n%2)
  if              ; res=N?/n? n // inv:n%2==1
    ; set up the multiply
    dup           ; res=N?/n? n n
    rot           ; n n res=N?/n?
    dup           ; n n res=N?/n? res=N?/n?
    rot           ; n res=N?/n? res=N?/n? n
    1             ; n res=N?/n? res=N?/n? n 1
    swap          ; n res=N?/n? res=N?/n? 1 n
    -             ; n res=N?/n? res=N?/n? (n-1) , aka: n res resx i // inv:resx=res*(n-i)
    dup           ; n res resx=res*(n-i) i i
    ; emulate multiply using only add operations
    while         ; n res resx=res*(n-i) i // inv:i>0
      swap        ; n res i resx=res*(n-i)
      rot         ; n i resx=res*(n-i) res
      dup         ; n i resx=res*(n-i) res res
      rot         ; n i res res resx=res*(n-i)
      +           ; n i res res*(n-i+1)
      rot         ; n res res*(n-(i-1)) i
      1           ; n res res*(n-(i-1)) i 1
      swap        ; n res res*(n-(i-1)) 1 i
      -           ; n res res*(n-(i-1)) (i-1) , aka: n res resx=res*(n-i) i
      dup         ; n res resx=res*(n-i) i i
    endwhile      ; n res resx=res*(n-i) i // inv:i==0 , aka: n res resx=res*n 0
    drop          ; n res resx=res*n=N?/(n-1)?
    swap          ; n resx=N?/(n-1)? res
    drop          ; n resx=N?/(n-1)?
    swap          ; res=N?/(n-1)? n
  endif           ; res=N?/(n-1)? n
  ; do the decrement
  1               ; res=N?/(n-1)? n 1
  swap            ; res=N?/(n-1)? 1 n
  -               ; res=N?/(n-1)? (n-1)
  dup             ; res=N?/(n-1)? (n-1) (n-1) , aka: res=N?/n? n n
endwhile          ; res=N?/n? n // inv:n==0

drop              ; res=N?/1   // inv:res==N? as 0?==1

return

defun main 
4 testWhile printnum endl
7 testWhile printnum endl
5 testWhile printnum endl
6 testWhile printnum endl
return
