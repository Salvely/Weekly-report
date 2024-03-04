# Bomb lab recitation

## act1

依次输入如下指令：

```
(gdb) disassemble main // show the assembly instructions in main
```

其`main`函数反汇编结果如下：

```
(gdb) disassemble main
Dump of assembler code for function main:
   0x0000000000401730 <+0>:     endbr64
   0x0000000000401734 <+4>:     push   %rbx
   0x0000000000401735 <+5>:     movslq %edi,%rdi
   0x0000000000401738 <+8>:     mov    %rsi,%rbx
   0x000000000040173b <+11>:    xor    %eax,%eax
   0x000000000040173d <+13>:    mov    -0x8(%rsi,%rdi,8),%rdx
   0x0000000000401742 <+18>:    lea    0xa8eb6(%rip),%rsi        # 0x4aa5ff
   0x0000000000401749 <+25>:    mov    $0x1,%edi
   0x000000000040174e <+30>:    callq  0x44b9a0 <__printf_chk>
   0x0000000000401753 <+35>:    movq   $0x0,(%rbx)
   0x000000000040175a <+42>:    pop    %rbx
   0x000000000040175b <+43>:    retq
End of assembler dump.
```

该汇编代码的过程如下：

```c
int main(int argc, char*argv[])
{
    int ret = printf("%s\n",argv[argc-1]);
    return ret;
}
```

## act2

反汇编`main`函数：

```
(gdb) disas main
Dump of assembler code for function main:
   0x00000000004016c0 <+0>:     endbr64
   0x00000000004016c4 <+4>:     push   %rbx
   0x00000000004016c5 <+5>:     movslq %edi,%rdi
   0x00000000004016c8 <+8>:     mov    %rsi,%rbx
   0x00000000004016cb <+11>:    mov    -0x8(%rsi,%rdi,8),%rsi
   0x00000000004016d0 <+16>:    lea    0x9392d(%rip),%rdi        # 0x495004
   0x00000000004016d7 <+23>:    callq  0x401c75 <stc>
   0x00000000004016dc <+28>:    movq   $0x0,(%rbx)
   0x00000000004016e3 <+35>:    pop    %rbx
   0x00000000004016e4 <+36>:    retq
End of assembler dump.
```

输入下列指令用 16 进制打印`%rsi`和`%rdi`的值：

```
(gdb) print /x $rsi
$1 = 0x7fffffffdf18
(gdb) print /x $rdi
$2 = 0x1
```

由此看`$rdi`应该是`argc`,而`$rsi`应该是`argv`。

再输入`disas stc`，获得如下结果：

```
(gdb) disas stc
Dump of assembler code for function stc:
   0x0000000000401c75 <+0>:     push   %rbx
   0x0000000000401c76 <+1>:     mov    %rsi,%rbx
   0x0000000000401c79 <+4>:     callq  0x4115d0 <puts>
   0x0000000000401c7e <+9>:     mov    %rbx,%rdi
   0x0000000000401c81 <+12>:    callq  0x4115d0 <puts>
   0x0000000000401c86 <+17>:    pop    %rbx
   0x0000000000401c87 <+18>:    retq
   0x0000000000401c88 <+19>:    nopl   0x0(%rax,%rax,1)
End of assembler dump.
```

将其转化为 C 语言函数应该是：

```c
// a:rsi b:rdi
int stc(char* a, char* b)
{
   // 压入原rbx
   rbx = rsi;
   puts(rbx);
   rdi = rbx;
   puts(rbx);
   // 恢复rbx
   // nopl是干嘛用的？
   return rax;
}
```

## act3

观察`main`函数的 C 代码，发现只要`compare`函数返回 1 即可通关。对`compare`函数进行反汇编可得：

```
(gdb) disas compare
Dump of assembler code for function compare:
   0x0000000000401c95 <+0>:     push   %rbx
   0x0000000000401c96 <+1>:     mov    %rdi,%rbx
   0x0000000000401c99 <+4>:     add    $0x5,%rbx
   0x0000000000401c9d <+8>:     add    %rsi,%rbx
   0x0000000000401ca0 <+11>:    cmp    $0x3b6d,%rbx
   0x0000000000401ca7 <+18>:    sete   %al
   0x0000000000401caa <+21>:    movzbq %al,%rax
   0x0000000000401cae <+25>:    pop    %rbx
   0x0000000000401caf <+26>:    retq
End of assembler dump.
```

还原其 C 代码如下：

```c
// rdi:a rsi:b
int compare(int a,int b)
{
   int ret;
   //压入原rbx
   rbx = a;
   rbx += 0x5;
   rbx += b;
   rbx = a + b + 0x5;
   if(rbx == 0x3b6d) {
      ret = 1;
   }
   else {
      ret = 0;
   }
   // 恢复原Rbx
   return ret;
}
```

发现`compare`就要求`a + b = 0x3b68(10进制15208)`。在`gdb`中只能输入 10 进制数字，如果输入 16 进制数字的话会被当成字符串。运行`./act3 15208 0`，成功！

```
gwen@gwen-virtual-machine:~/Documents/report/code/15213/Ch3 Machine Level Programming/rec4$ ./act3 15208 0
good args!
```

## act4

先查看`act4.c`的代码，看看是干嘛的：

```c
void compute(int inArg)
{
    int st;
    inArg *= 3;
    st = inArg & 0xf;
    do {
        switch(st)
        {
            case 0: printf("Finish\n"); inArg = -1; break;
            case 1: inArg *= 2; break;
            case 2: inArg >>= 2; break;
            case 3: inArg &= 1; break;
            case 4: inArg--; break;
            default:  break;
        }
        st = inArg & 0xf;
    } while (inArg >= 0);
}

int main(int argc, char** argv)
{
    int inArg;
    if (argc == 1) {fprintf(stderr, "Please rerun with a positive number argument\n"); return 1;}

    inArg = atoi(argv[1]);
    if (inArg < 0) {fprintf(stderr, "Argument was not a positive integer\n"); return 1;}
    compute(inArg);

    return 0;
}
```

所以我们要让 gdb 打印`Finish`，st 就得为 0，`inArg`就得为 0，那么就输入 1 个参数`0`即可。

```
gwen@gwen-virtual-machine:~/Documents/report/code/15213/Ch3 Machine Level Programming/rec4$ ./act4 0
Finish
```

我们要对汇编代码进行分析，就要使用`gdb`。输入`gdb act4`，输入`disas main`，得到如下结果：

```
(gdb) disas main
Dump of assembler code for function main:
   0x0000000000401730 <+0>:     endbr64
   0x0000000000401734 <+4>:     sub    $0x8,%rsp
   0x0000000000401738 <+8>:     lea    0x938e1(%rip),%rdx        # 0x495020
   0x000000000040173f <+15>:    cmp    $0x1,%edi
   0x0000000000401742 <+18>:    je     0x40176d <main+61>
   0x0000000000401744 <+20>:    mov    0x8(%rsi),%rdi
   0x0000000000401748 <+24>:    mov    $0xa,%edx
   0x000000000040174d <+29>:    xor    %esi,%esi
   0x000000000040174f <+31>:    callq  0x410310 <strtoq>
   0x0000000000401754 <+36>:    test   %eax,%eax
   0x0000000000401756 <+38>:    js     0x401766 <main+54>
   0x0000000000401758 <+40>:    mov    %eax,%edi
   0x000000000040175a <+42>:    callq  0x401d20 <compute>
   0x000000000040175f <+47>:    xor    %eax,%eax
   0x0000000000401761 <+49>:    add    $0x8,%rsp
   0x0000000000401765 <+53>:    retq
   0x0000000000401766 <+54>:    lea    0x938e3(%rip),%rdx        # 0x495050
   0x000000000040176d <+61>:    mov    0xbef54(%rip),%rdi        # 0x4c06c8 <stderr>
   0x0000000000401774 <+68>:    mov    $0x1,%esi
   0x0000000000401779 <+73>:    xor    %eax,%eax
   0x000000000040177b <+75>:    callq  0x44c080 <__fprintf_chk>
   0x0000000000401780 <+80>:    mov    $0x1,%eax
   0x0000000000401785 <+85>:    jmp    0x401761 <main+49>
End of assembler dump.
```

这里代码分析如下：

```c
// 初始化 $rdi = 0x1, $rsi = 0x7fffffffdf18。因此 rdi = argc, rsi = argv
int main(int argc, char* argv[])
{
   // 预留8个字节的栈空间
   rdx = rip + 0x938e1 -> 这句是干嘛的？
   if(edi == 1) {
      rdi = rip + 0xbef54; -> stderr
      esi = 0x1;
      eax = 0;
      call fprintf
      eax = 1;
      // rsp 恢复
      return eax;
   }
   else {
      rdi = *(rsi + 0x8);
      ecx = 0xa;
      esi = 0;
      call strtoq;
      if(eax < 0) {
         rdx = 0x938e3 + rip;
         rdi = *(rip + 0xbef54); -> stderr
         esi = 0x1;
         eax = 0;
         call fprintf
         eax = 1;
         // rsp 恢复
         return eax;
      }
      else {
         edi = eax;
         call compute
         eax = 0;
         // rsp 恢复
         return eax;
      }
   }
}
```

这里涉及到三个函数：`fprintf`，`strtoq`,`compute`。`fprintf`通常和`stderr`结合在一起。

对`strtoq`进行反汇编得到如下结果：

```
(gdb) disas strtoq
Dump of assembler code for function strtoq:
   0x0000000000410310 <+0>:     endbr64
   0x0000000000410314 <+4>:     mov    $0xffffffffffffffa8,%rax
   0x000000000041031b <+11>:    xor    %ecx,%ecx
   0x000000000041031d <+13>:    mov    %fs:(%rax),%r8
   0x0000000000410321 <+17>:    jmpq   0x410370 <____strtoll_l_internal>
End of assembler dump.
```

对`compute`进行反汇编得到如下结果：

```
(gdb) disas compute
Dump of assembler code for function compute:
   0x0000000000401d20 <+0>:     endbr64
   0x0000000000401d24 <+4>:     lea    (%rdi,%rdi,2),%edx
   0x0000000000401d27 <+7>:     lea    0x932de(%rip),%rcx        # 0x49500c
   0x0000000000401d2e <+14>:    mov    %edx,%eax
   0x0000000000401d30 <+16>:    and    $0xf,%eax
   0x0000000000401d33 <+19>:    cmp    $0x4,%eax
   0x0000000000401d36 <+22>:    ja     0x401d53 <compute+51>
   0x0000000000401d38 <+24>:    movslq (%rcx,%rax,4),%rax
   0x0000000000401d3c <+28>:    add    %rcx,%rax
   0x0000000000401d3f <+31>:    notrack jmpq *%rax
   0x0000000000401d42 <+34>:    nopw   0x0(%rax,%rax,1)
   0x0000000000401d48 <+40>:    and    $0x1,%edx
   0x0000000000401d4b <+43>:    mov    %edx,%eax
   0x0000000000401d4d <+45>:    jmp    0x401d33 <compute+19>
   0x0000000000401d4f <+47>:    nop
   0x0000000000401d50 <+48>:    sar    $0x2,%edx
   0x0000000000401d53 <+51>:    mov    %edx,%eax
   0x0000000000401d55 <+53>:    and    $0xf,%eax
   0x0000000000401d58 <+56>:    test   %edx,%edx
   0x0000000000401d5a <+58>:    jns    0x401d33 <compute+19>
   0x0000000000401d5c <+60>:    retq
   0x0000000000401d5d <+61>:    nopl   (%rax)
   0x0000000000401d60 <+64>:    add    %edx,%edx
   0x0000000000401d62 <+66>:    jmp    0x401d53 <compute+51>
   0x0000000000401d64 <+68>:    nopl   0x0(%rax)
   0x0000000000401d68 <+72>:    sub    $0x1,%edx
   0x0000000000401d6b <+75>:    jmp    0x401d53 <compute+51>
   0x0000000000401d6d <+77>:    nopl   (%rax)
   0x0000000000401d70 <+80>:    lea    0x9328d(%rip),%rsi        # 0x495004
   0x0000000000401d77 <+87>:    mov    $0x1,%edi
   0x0000000000401d7c <+92>:    xor    %eax,%eax
   0x0000000000401d7e <+94>:    jmpq   0x44bfb0 <__printf_chk>
End of assembler dump.
```
