# GDB and assembly activity 记录

## Activity 1

运行

```bash
gdb ./act1
(gdb) r 1
```

出现如下提示:

```
If you have questions about the commands, type (gdb) help <command>
Now type (gdb) info registers
This will display all of the integer registers.
Registers are basically the only local "variables" in assembly.
They are not located in memory, but instead directly within the CPU core.
  As such, they have no memory addresses and are referred to by name.
Although historically each register had a special purpose, now only %rsp does.
  It points to the top of the stack.
Look over the other registers: do any of them have familiar values, such as 1?
Q.  Given the information that GDB just stopped the program at the beginning
    of a function taking one or more arguments, write down your best guess at the
    purposes of the %rsp, %rdi, and %rax registers.

During this activity, gdb will print ... SIGTRAP ....  This is expected.
It indicates that the program, such as act1, triggered a breakpoint.
When you are finished looking at the registers, type r 2 <enter>
GDB may ask you if you want to start the program from the beginning (y or n) y

Program received signal SIGTRAP, Trace/breakpoint trap.
```

根据提示，输入`info registers`后，显示值如下：

```bash
(gdb) info registers
rax            0x4f                79
rbx            0x0                 0
rcx            0x7ffff7ec3297      140737352839831
rdx            0x0                 0
rsi            0x6042a0            6308512
rdi            0x1                 1
rbp            0x0                 0x0
rsp            0x7fffffffde40      0x7fffffffde40
r8             0x4f                79
r9             0x39                57
r10            0x400397            4195223
r11            0x246               582
r12            0x400590            4195728
r13            0x7fffffffdf40      140737488346944
r14            0x0                 0
r15            0x0                 0
rip            0x40077f            0x40077f <printStep2+191>
eflags         0x246               [ PF ZF IF ]
cs             0x33                51
ss             0x2b                43
ds             0x0                 0
es             0x0                 0
--Type <RET> for more, q to quit, c to continue without paging--
fs             0x0                 0
gs             0x0                 0
```

该处`%rdi`寄存器的值为 1，`%rsp`的值为`0x7fffffffde40`,`%rax`的值为`79`。`%rsp`寄存器中存储的值应当是地址，`%rax`中存储返回值，`%rdi`中存储传入参数。

接下来输入`r 2`。提示信息如下：

```
(gdb) r 2
The program being debugged has been started already.
Start it from the beginning? (y or n) y
Starting program: /home/gwen/Documents/report/code/15213/Ch3 Machine Level Programming/gdb-and-assembly/act1 2
Let's look at some assembly and registers.
There are two styles of assembly printing: AT&T and Intel
AT&T prints OP SRC, DEST, while Intel prints OP DEST, SRC
OP - opcode or instruction such as mov, ret, add, etc
SRC - source or input, instructions may have 0, 1, or 2 sources
DEST - destination, update this location, instructions may have 0 or 1
        destinations
Linux is based on Unix which was originally developed at Bell Labs, so GNU tools
default to AT&T style printing.
Also, sometimes a DEST is also a SRC, kind of like x += 5
Type (gdb) c
This will continue execution, please do so after each question.

Program received signal SIGTRAP, Trace/breakpoint trap.
```

该提示介绍了一下`AT & T`格式和`intel`格式的区别，主要是`src`和`dest`的位置不一样。按照提示输入`c`查看：

```
(gdb) c
Continuing.
You will commonly dissassemble a function.  There will be a header and footer.
Most of the output will be 0x....... <+0>:  OP SRC, DEST
This indicates that at address 0x..., which is 0 bytes from the start of the
function, there is an instruction OP with SRC and DEST as shown.
Type (gdb) disassemble squareInt
MOV is a common and powerful instruction.  It can "move" (actually, copy) values
between registers, load from memory, or store to memory.
   In this case, %edi holds the argument to the function and %eax its return value.
Q.  Fill in the blank in the pseudo C code for this function.

Program received signal SIGTRAP, Trace/breakpoint trap.
```

输入`disassemble squareInt`，得到如下结果：

```asm
(gdb) disassemble squareInt
Dump of assembler code for function squareInt:
   0x00000000004009c3 <+0>:     mov    %edi,%eax
   0x00000000004009c5 <+2>:     imul   %edi,%eax
   0x00000000004009c8 <+5>:     retq
End of assembler dump.
```

提示说`%edi holds the argument to the function and %eax its return value`，那么还原`squareInt`函数如下：

```c
// x in %edi, return value in %eax
int squareInt(int x)
{
    return x * x;
}
```

输入`c`，提示

```
(gdb) c
Continuing.
Type (gdb) disassemble squareLInt  (Note the L before Int)
Q.  How do the names of the registers differ between the functions?

Program received signal SIGTRAP, Trace/breakpoint trap.
```

按照提示输入`disassemble squareLInt`，看看`Q.  How do the names of the registers differ between the functions?`，结果如下：

```asm
Dump of assembler code for function squareLInt:
   0x00000000004009c9 <+0>:     mov    %rdi,%rax
   0x00000000004009cc <+3>:     imul   %rdi,%rax
   0x00000000004009d0 <+7>:     retq
End of assembler dump.
```

可以看到此处使用的是`%rdi`和`%rax`。`%rdi`和`%rax`是 64 位，而`%edi`和`%eax`是 32 位。因为前面用的是`int`，此处可能用的是`long`。`int`类型是 4 个字节，32 位，存储在`%eax`和`%edi`中。而`long`类型是 64 位，可以存储在`%rdi`和`%rax`中。

继续输入`c`，提示如下：

```
(gdb) c
Continuing.
squareLInt used long ints, hence it accessed %rdi, which is 64 bits.
squareInt used ints, hence it accessed %edi which is the lower 32 bits of %rdi
Type (gdb) disassemble squareFloat
Q.  Did squareFloat use the same registers from before?

Program received signal SIGTRAP, Trace/breakpoint trap.
```

输入`diassemble squareFloat`看看，结果如下:

```asm
(gdb) disassemble squareFloat
Dump of assembler code for function squareFloat:
   0x00000000004009d1 <+0>:     mulss  %xmm0,%xmm0
   0x00000000004009d5 <+4>:     retq
End of assembler dump.
```

浮点数和之前使用的不是同一套寄存器。继续输入`c`，可以看到程序退出。按照课程提示，输入`r 3`，提示如下：

```
Starting program: /home/gwen/Documents/report/code/15213/Ch3 Machine Level Programming/gdb-and-assembly/act1 3
We are going to look at how to access memory.
We already saw the mov instruction between registers.  Now we will load and
store.  When a register is in (), then it is serving as a memory location.
While mov is powerful, we cannot directly mov (%rax), (%rbx).  The ISA requires
a register to be used.
Please disassemble function: whatIsThis
Q.  Knowing that %rdi is the first argument and %rsi is the second, what do
    you think the function is doing?
After you have an answer, continue execution.  The following code will loop, as
We conclude activity 1.  When you are finished, please exit (q <enter>) and run act2.

Program received signal SIGTRAP, Trace/breakpoint trap.
0x0000000000400918 in runStep4 ()
```

这部分让我们掌握`load & store`指令，输入`disassemble whatIsThis`，可得如下结果：

```
(gdb) disassemble whatIsThis
Dump of assembler code for function whatIsThis:
   0x00000000004008a1 <+0>:     mov    (%rdi),%edx
   0x00000000004008a3 <+2>:     mov    (%rsi),%eax
   0x00000000004008a5 <+4>:     mov    %edx,(%rsi)
   0x00000000004008a7 <+6>:     mov    %eax,(%rdi)
   0x00000000004008a9 <+8>:     retq
End of assembler dump.
```

其中`%rdi`是第一个参数，`%rsi`是第二个参数。设第一个参数为`x`，第二个参数为`y`，(本来以为`x`和`y`是`long`类型整数，后来发现有指针，而赋值的变量又是`int`类型，那么可能`x`和`y`是`int*`类型的指针变量）。那么`whatIsThis`函数如下：

```c
// x in %rdi, y in %rsi
void whatIsThis(int* x, int* y) {
    int edx = *x;
    int eax = *y;
    *y = edx;
    *x = eax;
}
```

可以看到，此函数的作用为交换两个变量的位置。输入`c`，提示如下：

```
(gdb) c
Continuing.
Input two integers to test whatIsThis: <x> <y>
2 3
Let's examine memory before we execute whatIsThis
Please type (gdb) x/8d $rsp
  This will dump the memory (x) containing eight (8) decimal integers ([%]d)
  starting from the stack pointer ($rsp).
Once you've examined the memory dump, continue.
```

> 注意 gdb 中寄存器以`$`开头，而不是`%`

输入`2 3`，提示要求我们在执行`whatIsThis`之前，查看一下当前的内存分布。首先输入`x/8d $rsp`查看一下`%rsp`开始处 8 个整数的值。结果如下：

```
(gdb) p $rsp
$1 = (void *) 0x7fffffffde30
(gdb) x/8d $rsp
0x7fffffffde30: -8384   32767   2       3
0x7fffffffde40: 0       0       4196939 0`
```

输入`c`，提示再次查看`%rsp`处的值：

```
0x7fffffffde30: -8384   32767   3       2
0x7fffffffde40: 0       0       4196939 0
```

可以看到 2 和 3 的位置交换了。Activity 1 完成。

## Activity 2

输入`./act2`，提示显示`Did whatIsThis(): compare, swap, add, or multiply two numbers? Enter the keyword corresponding to the correct operation. `，根据上一问结果，输入`swap`。因为`whatIsThis`交换了两个变量的值。提示`Correct! Please rerun in gdb with r s.`

输入`gdb ./act2`，再输入`r s`，提示如下：

```
(gdb) r s
Starting program: /home/gwen/Documents/report/code/15213/Ch3 Machine Level Programming/gdb-and-assembly/act2 s
We are going to learn about memory access.  First, displacements.
A displacement is an immediate added to a memory access.
It is of the form: D(mem), so that the address accessed is D + mem.
Please disassemble viewThis.
Q.  What are the function's argument(s)?
Q.  What is the return register of the function?
Q.  Which instruction(s) initialize the return register?
Q.  What does the function do?
After you have your answer, please rerun with r a.

Program received signal SIGTRAP, Trace/breakpoint trap.
```

提示要求我们反汇编`viewThis`函数，并且回答四个问题。输入`disassemble viewThis`，显示如下：

```
(gdb) disassemble viewThis
Dump of assembler code for function viewThis:
   0x0000000000400687 <+0>:     mov    0x4(%rdi),%eax
   0x000000000040068a <+3>:     add    (%rdi),%eax
   0x000000000040068c <+5>:     add    0x8(%rdi),%eax
   0x000000000040068f <+8>:     add    0xc(%rdi),%eax
   0x0000000000400692 <+11>:    retq
End of assembler dump.
```

四个问题的回答分别是：

```
Q1: 函数的参数在M[%rdi + 4],M[%rdi],M[%rdi + 8],M[%rdi + 12]中
Q2: 函数返回值在%eax中
Q3: mov    0x4(%rdi),%eax 指令初始化了返回值寄存器%rax
Q4: 对一个4个int类型的数组求和
```

根据提示，输入`r a`，提示信息如下：

```
(gdb) r a
The program being debugged has been started already.
Start it from the beginning? (y or n) y
Starting program: /home/gwen/Documents/report/code/15213/Ch3 Machine Level Programming/gdb-and-assembly/act2 a
Since viewThis added 4 numbers from an array, let's look at more array
accesses.  The general form of a memory reference is D(B,I,S)
D + B + I * S
Disassemble: viewThisNext.
Q.  What does this function do?
We are going to call this function with array: arr.
Print its address with: p/x &arr
Then continue.

Program received signal SIGTRAP, Trace/breakpoint trap.
```

上一题答对啦：`viewThis`就是累加 4 个 int 类型元素的数组。输入`disassemble viewThisNext`，显示如下：

```
(gdb) disassemble viewThisNext
Dump of assembler code for function viewThisNext:
   0x0000000000400693 <+0>:     mov    (%rdi,%rsi,4),%eax
   0x0000000000400696 <+3>:     retq
End of assembler dump.
```

上述代码的逻辑为：`int ret = *(rdi + rsi * 4);
因为汇编代码是从字节出发，而`C`代码的指针递增，每次加`sizeof(T)`个字节。这里是`4`,那么推测`sizeof(T) = 4`，这里的类型应该是 int。那么`%rdi`应该是数组的起始位置，`%rsi`等于要取的数字的索引，最后返回到`%eax`中。其 C 语言描述如下：

```c
int get_val(int* arr,long index)
{
    return arr[index];
}
```

输入`p/x &arr`，结果如下：

```
(gdb) p/x &arr
$1 = 0x602080
```

输入`x/10d &arr`来打印从`arr`地址开始处后 10 个整数。显示结果如下：

```
(gdb) x/10d &arr
0x602080 <arr>: 0       1       2       3
0x602090 <arr+16>:      4       5       6       7
0x6020a0 <arr+32>:      8       9
```

可以看到 arr 地址开始后存储了 10 个整数，从 0 到 9。输入`c`继续，提示显示：

```
(gdb) c
Continuing.
Now we'll actually call viewThisNext.  Please input a number between 0 and 9.
5
You requested: 0x602094 = 5

Now rerun with r L.
[Inferior 1 (process 42895) exited normally]
```

我想要 5，该值在 0x605094 位置处。输入`r L`。提示如下：

```
(gdb) r L
Starting program: /home/gwen/Documents/report/code/15213/Ch3 Machine Level Programming/gdb-and-assembly/act2 L
Many times, the compiler will need to compute the address before it is used.
The instruction LEA provides this capability.
Disassemble: viewThisL.
It does the same calculation as before, except it passes along the pointer.
Once you're done looking at the disassembly dump, continue.

Program received signal SIGTRAP, Trace/breakpoint trap.
```

输入`diassemble viewThisL`后，提示显示：

```
(gdb) disassemble viewThisL
Dump of assembler code for function viewThisL:
   0x0000000000400697 <+0>:     sub    $0x8,%rsp
   0x000000000040069b <+4>:     lea    (%rdi,%rsi,4),%rdi
   0x000000000040069f <+8>:     callq  0x4004e0 <free@plt>
   0x00000000004006a4 <+13>:    add    $0x8,%rsp
   0x00000000004006a8 <+17>:    retq
End of assembler dump.
```

输入`c`，提示如下：

```
(gdb) c
Continuing.
LEA can also be used to do actual math.  The function mx mutliplies its
argument by some value.  Note the use of the SHL instruction to left shift.
Disassemble: mx.
Q.  Write down the four parts of LEA's displacement-mode address.
Q.  After accounting for the left shift, what value does mx() multiply its argument by?
For your final exercise, leave gdb and type head -n 8 act3.c.

Program received signal SIGTRAP, Trace/breakpoint trap.
```

输入`disassemble mx`，显示结果如下：

```
(gdb) disassemble mx
Dump of assembler code for function mx:
   0x00000000004006a9 <+0>:     lea    (%rdi,%rdi,2),%rax
   0x00000000004006ad <+4>:     shl    $0x2,%rax
   0x00000000004006b1 <+8>:     retq
End of assembler dump.
```

LEA 内存地址偏移计算模式为 D(B,I,S)。其中地址 = B + I*S + D。这里的指令为`lea    (%rdi,%rdi,2),%rax`。那么结果为`%rax = %rdi + 2 * %rdi = 3 \_ %rdi`。然后左移两位，也就是 * 4。最后`%rax`的值为`12 \* %rdi`。

## Activity 3

接下来，退出 gdb，并且输入`head -n 8 act3.c`。显示如下：

```
//
// This quick activity looks at compilation and assembly.
//   type gcc -Og -S act3.c
// Then view act3.s in your favorite editor
//   Notice the assembly is there, plus some other lines.
// Now compile with gcc -Og -c act3.c
// Then type objdump -d act3.o
//
```
根据提示，输入`gcc -Og -S act3.c`，然后输入`objdump -d act3.o`。显示如下：
```asm

act3.o:     file format elf64-x86-64


Disassembly of section .text:

0000000000000000 <mx>:
   0:   f3 0f 1e fa             endbr64 
   4:   48 8d 04 7f             lea    (%rdi,%rdi,2),%rax
   8:   48 c1 e0 02             shl    $0x2,%rax
   c:   c3                      retq   

000000000000000d <addm>:
   d:   f3 0f 1e fa             endbr64 
  11:   e8 00 00 00 00          callq  16 <addm+0x9>
  16:   48 83 c0 01             add    $0x1,%rax
  1a:   c3                      retq   
```