# Procedure Activity 记录

## Activity 1

输入`gdb --args ./calls`，输入`r`，提示如下：

```
  (gdb) r
If you didn't run it that way, it will now crash.
Otherwise, you will get the (gdb) prompt back.

Type 'c' (short for 'continue') at the (gdb) prompt.

Program received signal SIGTRAP, Trace/breakpoint trap.
main (argc=<optimized out>, argv=<optimized out>) at machine-procedures/calls.c:148
148     machine-procedures/calls.c: No such file or directory.
```

输入两次`c`，提示如下：

```
(gdb) c
Continuing.

showStack has been called again. Let's look at the contents
of the stack right now (just before the pop is executed):
(gdb) x/2gx $rsp

(Recall that the 'x' command prints memory. The '/2gx' modifier
tells it to print two 'g'iant (64-bit) values in he'x'adecimal,
and '$rsp' means to start at the current value of the %rsp
register, i.e. the stack pointer.)

Answer Problem 1 now: fill in the blanks with the value of the stack pointer
and the contents of the stack. When you are finished, 'c'ontinue.


Program received signal SIGTRAP, Trace/breakpoint trap.
0x00000000004011e1 in showStack ()
```

输入`x/2gx $rsp`，得到如下信息：

```
(gdb) x/2gx $rsp
0x7fffffffdde0: 0x0000000000015213      0x000000000040117a
```

此时`$rsp = (void *) 0x7fffffffdde0`，其指向的地址的值如上图所示。打印`0x000000000040117a`处的值，可以看到如下结果：

```
(gdb) x/2gx 0x000000000040117a
0x40117a <main+48>:     0xe37e02fb8301c383      0xfea4e800402108bf
```

`gdb`显示这里是`<main + 48>`，那么我们对`main`函数进行反汇编：

```
(gdb) disassemble main
Dump of assembler code for function main:
   0x000000000040114a <+0>:     push   %rbx
   0x000000000040114b <+1>:     mov    (%rsi),%rsi
   0x000000000040114e <+4>:     mov    $0x402010,%edi
   0x0000000000401153 <+9>:     mov    $0x0,%eax
   0x0000000000401158 <+14>:    callq  0x401040 <printf@plt>
   0x000000000040115d <+19>:    int3
   0x000000000040115e <+20>:    mov    $0x0,%ebx
   0x0000000000401163 <+25>:    jmp    0x40117d <main+51>
   0x0000000000401165 <+27>:    movslq %ebx,%rax
   0x0000000000401168 <+30>:    mov    0x402e60(,%rax,8),%rdi
   0x0000000000401170 <+38>:    callq  0x401030 <puts@plt>
   0x0000000000401175 <+43>:    callq  0x4011db <showStack>
   0x000000000040117a <+48>:    add    $0x1,%ebx
   0x000000000040117d <+51>:    cmp    $0x2,%ebx
   0x0000000000401180 <+54>:    jle    0x401165 <main+27>
--Type <RET> for more, q to quit, c to continue without paging--
   0x0000000000401182 <+56>:    mov    $0x402108,%edi
   0x0000000000401187 <+61>:    callq  0x401030 <puts@plt>
   0x000000000040118c <+66>:    int3
   0x000000000040118d <+67>:    mov    $0x402270,%edi
   0x0000000000401192 <+72>:    callq  0x401030 <puts@plt>
   0x0000000000401197 <+77>:    int3
   0x0000000000401198 <+78>:    mov    $0x402478,%edi
   0x000000000040119d <+83>:    callq  0x401030 <puts@plt>
   0x00000000004011a2 <+88>:    mov    $0x0,%eax
   0x00000000004011a7 <+93>:    pop    %rbx
   0x00000000004011a8 <+94>:    retq
End of assembler dump.
```

可以看到这个值是`callq  0x4011db <showStack>`的下一条指令地址，也就是`callq`调用的返回地址。

输入`c`继续，提示如下：

```
(gdb) c
Continuing.

showStack has been called a third time. Now let's watch it return.
GDB provides many commands for advancing through the program
other than 'c'ontinue. The 'si' command, for instance,
executes a single assembly instruction.

Use this command twice now.
After each step, print the values of %rsp and %rip:

(gdb) si
(gdb) p $rsp
(gdb) p $rip

Based on how %rsp and %rip changed after each instruction,
answer Problems 2 and 3 now. When you are finished, 'c'ontinue.


Program received signal SIGTRAP, Trace/breakpoint trap.
```

输入`si`，`%rsp`和`%rip`的值如下：

```
(gdb) p $rsp
$1 = (void *) 0x7fffffffdde8
(gdb) p $rip
$2 = (void (*)()) 0x4011e2 <showStack+7>
```

对`showStack`函数进行反汇编可以看到：

```
(gdb) disassemble showStack
Dump of assembler code for function showStack:
   0x00000000004011db <+0>:     pushq  $0x15213
   0x00000000004011e0 <+5>:     int3
   0x00000000004011e1 <+6>:     pop    %rax
=> 0x00000000004011e2 <+7>:     retq
End of assembler dump.
```

这里`%rip`指向的是`retq`指令，再次打印`%rsp`和`%rip`的值可以看到：

```
(gdb) p $rsp
$3 = (void *) 0x7fffffffddf0
(gdb) p $rip
$4 = (void (*)()) 0x40117a <main+48>
```

这里`%rsp`的值相对于`retq`前+8，并且`$rip`的值等于下一条指令的地址。由此可以推断，此处`ret`指令将栈顶的地址弹出，并赋值给`%rip`。那么`callq`指令做的事就是将下一条指令的地址压栈，然后将`%rip`的值设置为`callq`的目标地址。

输入`c`继续，指令如下：

```
(gdb) c
Continuing.

As you've seen, a ret pops a 64-bit address off the
top of the stack and jumps to that location.

Now disassemble the function returnOne. It calls another function, abs.
Based on what you see, and your knowledge of the ret instruction,
answer Problem 4 now. When you are finished, 'c'ontinue.


Program received signal SIGTRAP, Trace/breakpoint trap.
main (argc=<optimized out>, argv=<optimized out>) at machine-procedures/calls.c:156
156     in machine-procedures/calls.c
```

对`returnOne`进行反汇编可以看到：

```
(gdb) disassemble returnOne
Dump of assembler code for function returnOne:
   0x00000000004011e7 <+0>:     mov    $0xffffffff,%edi
   0x00000000004011ec <+5>:     callq  0x401142 <abs>
   0x00000000004011f1 <+10>:    retq
End of assembler dump.
```

对`returnOneOpt`进行反汇编即可看到：

```
(gdb) disassemble returnOneOpt
Dump of assembler code for function returnOneOpt:
   0x00000000004011f2 <+0>:     mov    $0xffffffff,%edi
   0x00000000004011f7 <+5>:     jmpq   0x401142 <abs>
End of assembler dump.
```

对`abs`反汇编结果如下：

```
(gdb) disassemble abs
Dump of assembler code for function abs:
   0x0000000000401142 <+0>:     mov    %edi,%eax
   0x0000000000401144 <+2>:     cltd
   0x0000000000401145 <+3>:     xor    %edx,%eax
   0x0000000000401147 <+5>:     sub    %edx,%eax
   0x0000000000401149 <+7>:     retq
End of assembler dump.
```

`returnOne`中的过程是，先`callq  0x401142 <abs>`，然后`retq`。`returnOneOpt`改为直接`jmpq   0x401142 <abs>`。而`abs`执行完后直接`retq`。

对`returnOne`，其过程为：

1. 将 main 函数中下一条指令地址压栈，将`returnOne`地址赋给`%rip`
2. 执行一段，调用`abs`
3. 将`returnOne`中下一条指令地址压栈，把`abs`地址付给`%rip`
4. 执行一段，从`abs`返回（执行`abs`的`retq`），从栈中弹出`returnOne`中`retq`地址赋给`$rip`，`$rip`跳转到`returnOne`的`retq`。
5. 执行`returnOne`的`retq`，将栈顶返回地址弹出，赋给`$rip`。

对`returnOneOpt`，其过程为：

1. 将 main 函数中下一条指令地址压栈，将`returnOne`地址赋给`%rip`
2. 执行一段，跳转到`abs`
3. 将`returnOne`中下一条指令地址压栈，把`abs`地址付给`%rip`
4. 执行一段，从`abs`返回（执行`abs`的`retq`），从栈中弹出`main`中`retq`地址赋给`$rip`

可以这样进行优化的原因是两条`retq`指令连在一起，所以没有必要`retq`两次，将`abs`和`returnOne`的过程接在一起构成一个`procedure`，`retq`一次即可。

输入`c`，题目中给出了答案：

```
(gdb) c
Continuing.

The transformation you just witnessed is a simple example of tail-call
optimization. Because a call was the last instruction before a ret,
within a function that doesn't adjust the stack pointer, the compiler
could skip allocating a stack frame: both the call and the ret could be
replaced with a simple jmp to the called function. That function must
end in its own ret instruction, which will use the return address
pushed by the call to returnOneOpt. This optimization is especially
valuable when applied to recursive functions.

End of Activity 1. This program will now exit.

Use the 'q'uit command to leave GDB.

[Inferior 1 (process 68527) exited normally]
```

原来这里是尾递归优化的精髓啊！明白啦！

## Activity 2

输入`gdb --args ./locals`，输入`r`，再输入`c`，得到的提示如下：

```
The stack is also used to pass data between procedures, but nowadays
most function arguments are passed in registers instead.  You have
already seen the first two argument-passing registers (%rdi and %rsi,
in that order) in use.

Dissassemble the function seeArgs.
It calls printf with six arguments.  Arguments 2-6 are labeled for you
in the assembly.
Based on what you see in the disasssembly, answer Problem 6.
Check your answer using:
(gdb) x/s <value passed in %rdi>.

When you are finished, 'c'ontinue.


Program received signal SIGTRAP, Trace/breakpoint trap.
main (argc=<optimized out>, argv=<optimized out>) at machine-procedures/locals.c:156
156     in machine-procedures/locals.c
```

输入`disassemble seeArgs`，提示如下：

```
(gdb) disassemble seeArgs
Dump of assembler code for function seeArgs:
   0x0000000000401152 <+0>:     sub    $0x8,%rsp
   0x0000000000401156 <+4>:     mov    $0x6,%r9d
   0x000000000040115c <+10>:    mov    $0x5,%r8d
   0x0000000000401162 <+16>:    mov    $0x4,%ecx
   0x0000000000401167 <+21>:    mov    $0x3,%edx
   0x000000000040116c <+26>:    mov    $0x2,%esi
   0x0000000000401171 <+31>:    mov    $0x402016,%edi
   0x0000000000401176 <+36>:    mov    $0x0,%eax
   0x000000000040117b <+41>:    callq  0x401050 <printf@plt>
   0x0000000000401180 <+46>:    add    $0x8,%rsp
   0x0000000000401184 <+50>:    retq
End of assembler dump.
```

第一个传入的参数保存在`%edi`中，其值是`0x402016`。估摸着是`int`类型。输入`x/s 0x402016`，显示：

```
(gdb) x/s 0x402016
0x402016:       "%d %d %d %d %d"
```

确实是`int`类型，那么此处猜测`x/s`是打印从该处开始的字符串。

输入`c`，提示如下：

```
(gdb) c
Continuing.

Now disassemble the function seeMoreArgs.
It calls printf with eight arguments.
Based on what you see in the disasssembly, answer Problem 7.
When you are finished, 'c'ontinue.


Program received signal SIGTRAP, Trace/breakpoint trap.
main (argc=<optimized out>, argv=<optimized out>) at machine-procedures/locals.c:156
```

输入`disassemble seeMoreArgs`，输出如下：

```
(gdb) disassemble seeMoreArgs
Dump of assembler code for function seeMoreArgs:
   0x0000000000401185 <+0>:     sub    $0x8,%rsp
   0x0000000000401189 <+4>:     pushq  $0x8
   0x000000000040118b <+6>:     pushq  $0x7
   0x000000000040118d <+8>:     mov    $0x6,%r9d
   0x0000000000401193 <+14>:    mov    $0x5,%r8d
   0x0000000000401199 <+20>:    mov    $0x4,%ecx
   0x000000000040119e <+25>:    mov    $0x3,%edx
   0x00000000004011a3 <+30>:    mov    $0x2,%esi
   0x00000000004011a8 <+35>:    mov    $0x402010,%edi
   0x00000000004011ad <+40>:    mov    $0x0,%eax
   0x00000000004011b2 <+45>:    callq  0x401050 <printf@plt>
   0x00000000004011b7 <+50>:    add    $0x18,%rsp
   0x00000000004011bb <+54>:    retq
End of assembler dump.
```

第 7 个和第 8 个被压在栈上。寄存器只有 6 个，多的就压在栈上。

输入`c`，提示如下：

```
(gdb) c
Continuing.

The stack can also be used to store local variables.

Now disassemble the function getV.
It contains a local array of 4 ints.
(The compiler has chosen to reserve some extra stack space.)
Based on what you see in the disasssembly, answer Problems 7 and 8.
When you are finished, 'c'ontinue.


Program received signal SIGTRAP, Trace/breakpoint trap.
main (argc=<optimized out>, argv=<optimized out>) at machine-procedures/locals.c:156
```

输入`disassemble getV`，结果如下：

```
(gdb) disassemble getV
Dump of assembler code for function getV:
   0x00000000004011bc <+0>:     sub    $0x18,%rsp
   0x00000000004011c0 <+4>:     movslq %edi,%rsi
   0x00000000004011c3 <+7>:     mov    %rsp,%rdi
   0x00000000004011c6 <+10>:    callq  0x401284 <getValue>
   0x00000000004011cb <+15>:    add    $0x18,%rsp
   0x00000000004011cf <+19>:    retq
End of assembler dump.
```

`getV`的调用过程如下：

1. `%rsp - 24`，留出 24 个字节的位置
2. `%rsi = %edi, %rdi = %rsp`
   将`%rsp`的位置通过`%rdi`传入。`%rsp`指向数组的起始位置。

对`getValue`进行反汇编结果如下：

```
(gdb) disassemble getValue
Dump of assembler code for function getValue:
   0x0000000000401284 <+0>:     mov    (%rdi,%rsi,4),%eax
   0x0000000000401287 <+3>:     retq
End of assembler dump.
```

输入`c`继续，结果如下：

```
(gdb) c
Continuing.

There are also rules for whether a function is allowed to change
the value in each register--all the registers, not just those
used for arguments.

Each register is either call-preserved or call-clobbered.
When a function returns, all the call-preserved registers must
have the same values that they did when the function was called.
That means, if a function wants to use a call-preserved register,
it must save the old value first, and restore it when it's done using
the register. (The push and pop instructions are often used for this.)

(More text to follow, 'c'ontinue to go on...)


Program received signal SIGTRAP, Trace/breakpoint trap.
main (argc=<optimized out>, argv=<optimized out>) at machine-procedures/locals.c:156
```

继续输入`c`，提示如下：

```
(gdb) c
Continuing.

... The call-clobbered registers, on the other hand, don't have to be
saved and restored. A function that wants to use them can just use
them, without worrying about whether its callers were using them also.
However, if a function has an important value in a call-clobbered
register, and it needs to call some other function, and then use that
important value afterward, it has to save the value itself!

(Some people use the term 'callee-save' instead of 'call-preserved',
and 'caller-save' instead of 'call-clobbered'. We don't like those
terms because there's only one letter of difference between them.)

Disassemble the function mult4 and think about how it is using the registers.
Using what you find, answer Problem 9. When you are finished, 'c'ontinue.


Program received signal SIGTRAP, Trace/breakpoint trap.
main (argc=<optimized out>, argv=<optimized out>) at machine-procedures/locals.c:156
156     in machine-procedures/locals.c
```

本段提示主要讲了`caller saved registers`的概念。

`caller saved registers`(我个人觉得更准确的说法是`caller preserver & restore`)，例如下列的过程调用（写的比较粗糙）：

```asm
call_echo:
    pushq %rbx
    callq echo<xxxx>
    popq %rbx
    ret

echo:
    %rbx += 1
    call printf<xxxx>
    ret
```

在`echo`的过程中会修改`%rbx`的值，那么在对其进行调用前就必须`pushq %rbx`，并且在调用完后`popq %rbx`。

输入`disassemble mult4`可得如下结果：

```
(gdb) disassemble mult4
Dump of assembler code for function mult4:
   0x0000000000401250 <+0>:     push   %rbx
   0x0000000000401251 <+1>:     push   %r12
   0x0000000000401253 <+3>:     push   %r13
   0x0000000000401255 <+5>:     mov    %edx,%r12d
   0x0000000000401258 <+8>:     mov    %ecx,%r13d
   0x000000000040125b <+11>:    callq  0x40124a <mult2>
   0x0000000000401260 <+16>:    mov    %r12d,%edi
   0x0000000000401263 <+19>:    mov    %r13d,%esi
   0x0000000000401266 <+22>:    mov    %eax,%ebx
   0x0000000000401268 <+24>:    callq  0x40124a <mult2>
   0x000000000040126d <+29>:    mov    %eax,%edi
   0x000000000040126f <+31>:    mov    %ebx,%esi
   0x0000000000401271 <+33>:    callq  0x40124a <mult2>
   0x0000000000401276 <+38>:    pop    %r13
   0x0000000000401278 <+40>:    pop    %r12
   0x000000000040127a <+42>:    pop    %rbx
   0x000000000040127b <+43>:    retq
End of assembler dump.
```

然后`disassemble mult2`，结果如下：

```
(gdb) disassemble mult2
Dump of assembler code for function mult2:
   0x000000000040124a <+0>:     mov    %edi,%eax
   0x000000000040124c <+2>:     imul   %esi,%eax
   0x000000000040124f <+5>:     retq
End of assembler dump.
```

可以看到`mult2`函数中主要使用到的是`%edi`和`%esi`两个寄存器。返回值在`%eax`中。在`mult4`中，压入了`%rbx %r12 %r13`。

输入`c`，提示如下：

```
(gdb) c
Continuing.

For the final step in today's activity, we will look at recursive
calls. Each recursive invocation of a function has its own space on
the stack, separate from any other call's space.

Disassemble the function mrec and think about what it does.
Answer Problem 10. When you are finished, 'c'ontinue.


Program received signal SIGTRAP, Trace/breakpoint trap.
main (argc=<optimized out>, argv=<optimized out>) at machine-procedures/locals.c:156
```

输入`disassemble mrec`，得到如下结果：

```
(gdb) disassemble mrec
Dump of assembler code for function mrec:
   0x00000000004011d0 <+0>:     push   %rbx
   0x00000000004011d1 <+1>:     mov    %edi,%ebx
   0x00000000004011d3 <+3>:     cmp    $0x1,%edi
   0x00000000004011d6 <+6>:     je     0x4011e5 <mrec+21>
   0x00000000004011d8 <+8>:     lea    -0x1(%rdi),%edi
   0x00000000004011db <+11>:    callq  0x4011d0 <mrec>
   0x00000000004011e0 <+16>:    imul   %ebx,%eax
   0x00000000004011e3 <+19>:    pop    %rbx
   0x00000000004011e4 <+20>:    retq
   0x00000000004011e5 <+21>:    mov    %edi,%eax
   0x00000000004011e7 <+23>:    jmp    0x4011e3 <mrec+19>
End of assembler dump.
```

将该函数转化为 C 函数，如下：

```c
// arg in %rbx
int mrec(int* rbx)
{
    // int* temp = rbx; // 保存%rbx
    ebx = edi; // rbx 重新赋值
    if(edi == 0x1) {
        eax = edi; // 返回值 = edi
        // rbx = temp; // 获得rbx原值
        return eax;
    }
    edi = rdi - 0x1; // edi -= 1
    int eax = mrec(rbx); // 获得返回值
    eax *= ebx; // 返回值 * ebx
    // rbx = temp; // 获得rbx原值
    return eax;
}

// 一个更加C的版本
int mrec(int x)
{
    if(x == 0x1) {
        return x;
    }
    return x * mrec(x-1);
}
```

推测该函数实现了`x`的阶乘？

## Activity 3

重新运行`gdb -args ./calls`，运行到`showStack`处，打印`$rip`前 3 个字节，得到如下结果：

```
(gdb) x/3b $rsp
0x7fffffffdde0: 0x13    0x52    0x01
```

可以看到数字`0x15213`的高位存放在高字节中，低位存放在低字节中，该机器使用的是小端法。
