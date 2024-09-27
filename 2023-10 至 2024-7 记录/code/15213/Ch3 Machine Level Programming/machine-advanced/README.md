# Machine Advanced Activity 记录

- [Machine Advanced Activity 记录](#machine-advanced-activity-记录)
  - [Getting Started](#getting-started)
  - [Gets](#gets)
  - [Overwritting Stack](#overwritting-stack)
  - [Exploit](#exploit)
  - [Defense](#defense)
  - [ROP](#rop)

## Getting Started

```c
typedef struct {
    int a[2];
    double d;
} struct_t;

double fun(int i) {
    volatile struct_t s;
    s.d = 3.14;
    s.a[i] = 1073741824; /* Possibly out of bounds */
    return s.d;
}
```

执行`fun(0)`，对`fun`函数进行反汇编可得到如下内容：

```
(gdb) disassemble fun
Dump of assembler code for function fun:
   0x0000555555555169 <+0>:     endbr64
   0x000055555555516d <+4>:     push   %rbp
   0x000055555555516e <+5>:     mov    %rsp,%rbp
   0x0000555555555171 <+8>:     sub    $0x30,%rsp
   0x0000555555555175 <+12>:    mov    %edi,-0x24(%rbp)
   0x0000555555555178 <+15>:    mov    %fs:0x28,%rax
   0x0000555555555181 <+24>:    mov    %rax,-0x8(%rbp)
   0x0000555555555185 <+28>:    xor    %eax,%eax
   0x0000555555555187 <+30>:    movsd  0xe81(%rip),%xmm0        # 0x555555556010
   0x000055555555518f <+38>:    movsd  %xmm0,-0x18(%rbp)
   0x0000555555555194 <+43>:    mov    -0x24(%rbp),%eax
   0x0000555555555197 <+46>:    cltq
   0x0000555555555199 <+48>:    movl   $0x40000000,-0x20(%rbp,%rax,4)
   0x00005555555551a1 <+56>:    movsd  -0x18(%rbp),%xmm0
   0x00005555555551a6 <+61>:    mov    -0x8(%rbp),%rax
   0x00005555555551aa <+65>:    xor    %fs:0x28,%rax
   0x00005555555551b3 <+74>:    je     0x5555555551ba <fun+81>
   0x00005555555551b5 <+76>:    callq  0x555555555060 <__stack_chk_fail@plt>
   0x00005555555551ba <+81>:    leaveq
   0x00005555555551bb <+82>:    retq
End of assembler dump.
```

该反汇编代码的思路如下：

1. 将`old %rbp`压在栈上，并让`%rbp = %rsp`（变长栈帧）
2. 保留 48 个字节的位置(`%rsp - 48`)
3. 让`*(%rbp - 36) = %edi`
4. 设置`canary`的值
5. 将`%eax`置为 0
6. 将`3.14`中间经过浮点寄存器，移动到`*(%rbp - 24)`
7. `%eax = *(%rbp - 36)`
8. `movl   $0x40000000,-0x20(%rbp,%rax,4)`
9. 取出浮点数
10. 取出`canary`的值，进行比对
11. `canary`未被改变，则正常返回；否则就调用`fail`过程

几个比较重要的值的位置分别是（一共48个字节位置）：
1. `*(%rbp - 24) = 3.14`
2. `*(%rbp - 36) = i`
3. `%eax = *(%rbp - 36)`
4. `%canary = *(%rbp - 8)`

如果不加`canary`，该`fun`函数的反汇编代码如下：

```
(gdb) disassemble fun
Dump of assembler code for function fun:
   0x0000000000001149 <+0>:     endbr64
   0x000000000000114d <+4>:     push   %rbp
   0x000000000000114e <+5>:     mov    %rsp,%rbp
   0x0000000000001151 <+8>:     mov    %edi,-0x14(%rbp)
   0x0000000000001154 <+11>:    movsd  0xeb4(%rip),%xmm0        # 0x2010
   0x000000000000115c <+19>:    movsd  %xmm0,-0x8(%rbp)
   0x0000000000001161 <+24>:    mov    -0x14(%rbp),%eax
   0x0000000000001164 <+27>:    cltq
   0x0000000000001166 <+29>:    movl   $0x40000000,-0x10(%rbp,%rax,4)
   0x000000000000116e <+37>:    movsd  -0x8(%rbp),%xmm0
   0x0000000000001173 <+42>:    pop    %rbp
   0x0000000000001174 <+43>:    retq
End of assembler dump.
```

Problem 1. Where is the struct allocated in the system?
这个结构分配在栈上。

Problem 2. What critical value is pushed onto the stack for every function call?
`%rip`的值在执行`call`的时候被压入栈上，`%rbp`也会被压入栈上。

Problem 3. The `s.a[i]` line is writing to memory. In lecture 1, `fun(6)` crashed the
program. Why did writing to this location cause the process to crash? 因为超过了程序分配的栈空间，触发了 `canary` 警报。

## Gets

## Overwritting Stack

## Exploit

## Defense

## ROP
