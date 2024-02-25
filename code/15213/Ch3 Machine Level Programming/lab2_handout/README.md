# Bomb lab activity 记录

## Part I

输入如下命令：

```
$ gcc -o phase1 -g -std=c99 phase1.c
$ gdb ./phase1
```

按照 handout 依次输入命令并观察结果。

### 打断点

```
(gdb) break main
Breakpoint 1 at 0x13b2: file phase1.c, line 54.
(gdb) break unscramble
Breakpoint 2 at 0x1308: file phase1.c, line 39.
(gdb) break reverse
Breakpoint 3 at 0x1274: file phase1.c, line 30.
(gdb) break toggleCase
Breakpoint 4 at 0x11e7: file phase1.c, line 18.
(gdb) info break
Num     Type           Disp Enb Address            What
1       breakpoint     keep y   0x00000000000013b2 in main at phase1.c:54
2       breakpoint     keep y   0x0000000000001308 in unscramble at phase1.c:39
3       breakpoint     keep y   0x0000000000001274 in reverse at phase1.c:30
4       breakpoint     keep y   0x00000000000011e7 in toggleCase at phase1.c:18
```

### 运行程序 & 打印值

```
(gdb) run
Starting program: /home/gwen/Documents/report/code/15213/Ch3 Machine Level Programming/lab2_handout/phase1

Breakpoint 1, main () at phase1.c:54
54      int main () {
(gdb) n
55          word_t *secret_msg = (word_t *) calloc(1, sizeof(word_t));
(gdb) n
56          secret_msg->str = (char *) calloc(length, sizeof(char));
(gdb) print *(word_t*)secret_msg
$1 = {str = 0x0, len = 0}
(gdb) next
57          strncpy(secret_msg->str, "!312 Av XPHy QBBt", length);;
(gdb) print *(word_t*)secret_msg
$2 = {str = 0x5555555592c0 "", len = 0}
```

### 单步调试 & watchpoint

```
Breakpoint 2, unscramble (msg=0x555555555480 <__libc_csu_init>) at phase1.c:39
39      void unscramble (word_t *msg) {
(gdb) step
41          char chng = 13;
(gdb) next
42          for (int i = 0; i < msg->len; i++) {
(gdb) next
43              ltr = msg->str[i];
(gdb) print(ltr)
$3 = 85 'U'
(gdb) print isAlpha(ltr)
$4 = true
(gdb) watch ltr
Hardware watchpoint 5: ltr
(gdb) c
Continuing.

Hardware watchpoint 5: ltr

Old value = 85 'U'
New value = 33 '!'
unscramble (msg=0x5555555592a0) at phase1.c:44
44              if (isAlpha(ltr)) {
(gdb) step
isAlpha (ltr=85 'U') at phase1.c:13
13      bool isAlpha (char ltr) {
(gdb) backtrace
#0  isAlpha (ltr=85 'U') at phase1.c:13
#1  0x0000555555555345 in unscramble (msg=0x5555555592a0) at phase1.c:44
#2  0x0000555555555429 in main () at phase1.c:60
```

### 3 Questions

1. What does `unscramble(word_t *msg)` do? And how?
   将`secret_msg`指向的结构体中的`!312 Av XPHy QBBt`替换成了`!312 Ni KCUl DOOg`。
   `unscramble`的作用是：判断`msg_str`当前的字符，如果`M < ltr <= Z`，就将其字符值减去 13。否则加上 13。
2. What does `reverse(word_t *msg)` do? And how?
   将`secret_msg`指向的结构体中的`!312 Ni KCUl DOOg`替换成了`gOOD lUCK iN 213!`。该函数反转字符串。
3. What does `toggleCase(word_t *msg)` do? And how?
   将`secret_msg`指向的结构体中的`gOOD lUCK iN 213!`替换成了`Good Luck In 213!`。该函数反转字符串大小写。

## Part II

输入`gcc -std=c99 -o phase2 -g phase2.c`编译生成`phase2`，对其利用`gdb`进行排错发现`S->top->len`为 0，导致浮点数相除时发生错误。我们进行如下修改：

1. 在初始化栈的时候让栈顶的长度为 0
2. `push`新结点的时候让结点的`len`为栈顶结点的长度加 1，然后让栈顶指向结点
3. `pop`时结点弹出，栈顶指向的新结点的长度值为弹出结点长度减 1
