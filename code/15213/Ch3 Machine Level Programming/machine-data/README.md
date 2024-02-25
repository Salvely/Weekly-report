# Machine Programming: Data 记录

- [Machine Programming: Data 记录](#machine-programming-data-记录)
  - [Integers and Local Variables](#integers-and-local-variables)
  - [Arrays](#arrays)
  - [Structs](#structs)
  - [Arrays of Structs](#arrays-of-structs)
  - [2-D Arrays](#2-d-arrays)
  - [Endianness (Optional)](#endianness-optional)

输入`gdb ./data-layout`，开启`Data activity`之旅。

## Integers and Local Variables

`returnOne`的 C 语言版本如下：

```c
int returnOne (void) {
    int local = -1;
    return abs(local);
}
```

输入`disassemble returnOne`，得到如下结果：

```
(gdb) disassemble returnOne
Dump of assembler code for function returnOne:
   0x0000000000400581 <+0>:     sub    $0x8,%rsp
   0x0000000000400585 <+4>:     mov    $0xffffffff,%edi
   0x000000000040058a <+9>:     callq  0x400613 <abs>
   0x000000000040058f <+14>:    add    $0x8,%rsp
   0x0000000000400593 <+18>:    retq
End of assembler dump.
```

可以看到首先我们为`returnOne`预留了 8 个字节的栈空间。将`0xffffffff`放入`%edi`（应该是传入函数的第一个参数寄存器）。然后调用`abs`，最后还原栈空间。

对`abs`进行反汇编结果如下：

```
(gdb) disassemble abs
Dump of assembler code for function abs:
   0x0000000000400613 <+0>:     mov    %edi,%edx
   0x0000000000400615 <+2>:     sar    $0x1f,%edx
   0x0000000000400618 <+5>:     mov    %edi,%eax
   0x000000000040061a <+7>:     xor    %edx,%eax
   0x000000000040061c <+9>:     sub    %edx,%eax
   0x000000000040061e <+11>:    retq
End of assembler dump.
```

`abs`所做的是把`%edi`放入`%edx`，然后将其右移 31 位（也就是让符号位充满），将其和原值相异或，然后再减去全符号位。最后返回`%eax`。此处`local`变量应该是存储在寄存器`%edi`中。这里的问题是如果`local`不在栈上，那么我们就没有办法获取它的地址。如果需要`local`的地址的话，我们可能需要将其压在栈上，然后使用`leaq %rsp, %rdi`获取它的地址。

为了验证我们的结论，我们对`returnOneTwo`进行反汇编：

```
(gdb) disassemble returnOneTwo
Dump of assembler code for function returnOneTwo:
   0x0000000000400594 <+0>:     sub    $0x18,%rsp
   0x0000000000400598 <+4>:     movl   $0xffffffff,0xc(%rsp)
   0x00000000004005a0 <+12>:    lea    0xc(%rsp),%rdi
   0x00000000004005a5 <+17>:    callq  0x40061f <absp>
   0x00000000004005aa <+22>:    add    $0x18,%rsp
   0x00000000004005ae <+26>:    retq
End of assembler dump.
```

该函数所做的是预留 24 个字节的空间，然后把`0xffffffff`放入`M[%rsp + 12]`的位置上，并且将指向该位置的指针赋给`%rdi`，随后调用`absp`。由此推测，`absp`的传入参数是一个指针（`%rdi`中）。调用完成后恢复栈空间。

因此，`absp`的函数原型应该是`int absp(int* p)`。

## Arrays

`x`的几种不同格式的显示[见此](https://www.jianshu.com/p/589308dd36dc)。这里的显示需要指明 3 个内容：

1. 显示几个单位
2. 每个单位几个字节：如 b=1 byte, h=2 bytes,w=4 bytes,g=8 bytes（如果不指定，默认 1 字节）
3. 用几进制显示：`b`就是 2 进制，`x`就是 16 进制，`d`就是 10 进制

使用`x/4b courses`只能查看 4 个字节，以 10 进制数显示，结果如下：

```
(gdb) x/4b courses
0x601110 <courses>:     19      82      1       0
```

使用`x/4x courses`只能查看 4 个字节，以 16 进制数显示，结果如下：

```
(gdb) x/4x courses
0x601110 <courses>:     0x13    0x52    0x01    0x00
```

使用`x/4wx courses`查看`courses`处的 4 个`int`类型值。`w`是 4 个字节。结果如下：

```
(gdb) x/4wx courses
0x601110 <courses>:     0x00015213      0x00015513      0x00018213      0x00018600
```

可以看到`courses`处存放了 4 个值：15213 15513 18213 18600，对应数组中的 4 个元素。

`getNth`函数的 C 语言形式如下：

```c
int getNth(int *arr , size_t index) {
    return arr[index];
}
```

其中`%rdi`是数组的起始位置(`arr`)，`%rsi`是索引(`index`)。因为一个`int`类型是 4 个字节，因此计算地址的时候是`*(rdi + 4 * rsi)`

对`getNth`函数进行反汇编可得：

```
(gdb) disassemble getNth
Dump of assembler code for function getNth:
   0x00000000004005af <+0>:     mov    (%rdi,%rsi,4),%eax
   0x00000000004005b2 <+3>:     retq
End of assembler dump.
```

重新运行，输入一次`c`，输入`x/bx $rdi`可得：

```
(gdb) x/s $rdi
0x4007f8:       "15213 CSAPP"
```

此处的字符串是`15213 CSAPP`。（推测`x/s $rdi`的意思以字符串的形式打印从`$rdi`开始的内存）。输入`x/12bx $rdi`，可以得到如下结果：

```
(gdb) x/12bx $rdi
0x4007f8:       0x31    0x35    0x32    0x31    0x33    0x20    0x43    0x53
0x400800:       0x41    0x50    0x50    0x00
```

字符串的结尾是`0x00`，`x/s`命令应该是通过`0x00`判断字符串的结尾，进而计算字符串的长度的。

## Structs

定义`struct course`如下：

```c
struct course {
    int cs_ugrad;
    int cs_grad;
    int ece_ugrad ;
    int ece_grad;
};
```

继续输入`c`，handout 提示断点处的函数将`struct course`结构的值作为传入参数，使用` x/4wx $rdi`查看`%rdi`处的内存可以看到：

```
(gdb) x/4wx $rdi
0x601100 <course>:      0x00015213      0x00015513      0x00018213      0x00018600
```

我们可以发现该处的四个值就是：`0x15213 0x15513 0x18213 0x18600`

我们定义结构体：

```c
struct increasing {
    char a;
    short b;
    int c;
    long d;
};
```

假设

```c
a = 0x0a;
b = 0x0b0b;
c = 0x0c0c0c0c;
d = 0x0d0d0d0d0d0d0d0d;
```

继续输入`c`，我们使用`x/32bx $rdi`来查看结构体内容，内容如下：

```
(gdb) x/32bx $rdi
0x6010e0 <increasing>:  0x0a    0x00    0x0b    0x0b    0x0c    0x0c    0x0c    0x0c
0x6010e8 <increasing+8>:        0x0d    0x0d    0x0d    0x0d    0x0d    0x0d    0x0d    0x0d
0x6010f0 <increasing+16>:       0x00    0x00    0x00    0x00    0x00    0x00    0x00    0x00
0x6010f8 <increasing+24>:       0x00    0x00    0x00    0x00    0x00    0x00    0x00    0x00
```

和我们料想的情况一致。

将结构体内容重新排列如下：

```c
struct rearranged {
    char a;
    long b;
    short c;
    int d;
};
```

这种方法按理论来说应该比上面那种多用 8 个字节。结果验证如下：

```
(gdb) x/32bx rearranged
0x6010a0 <rearranged>:  0x0a    0x00    0x00    0x00    0x00    0x00    0x00    0x00
0x6010a8 <rearranged+8>:        0x0b    0x0b    0x0b    0x0b    0x0b    0x0b    0x0b    0x0b
0x6010b0 <rearranged+16>:       0x0c    0x0c    0x00    0x00    0x0d    0x0d    0x0d    0x0d
0x6010b8 <rearranged+24>:       0x00    0x00    0x00    0x00    0x00    0x00    0x00    0x00
```

## Arrays of Structs

有结构体如下：

```c
struct pair {
    int large;
    char small;
};
struct pair pairs [2] = {
    {0 xabababab , 0x1},
    {0 xcdcdcdcd , 0x2}
};
```

每个`pair`应该是 8 个字节。因为`int`类型占 4 个字节，`char`类型占 1 个字节。**此外结构体的长度必须是结构体中体积最大的类型的整数倍**，该结构体中最大的是`int`类型，4 个字节，因此结构体的长度必须是 4 个字节的倍数，因此是 8 个字节，需要在`char`后再加 3 个字节的`padding`。`pairs`是一个包含两个结构体变量的数组，1 个变量是 8 个字节，2 个就是 16 个字节。

我们验证一下(此处`pairs`也可以替换成`&pairs`)：

```
(gdb) x/16bx pairs
0x601080 <pairs>:       0xab    0xab    0xab    0xab    0x01    0x00    0x00    0x00
0x601088 <pairs+8>:     0xcd    0xcd    0xcd    0xcd    0x02    0x00    0x00    0x00
```

此外，结构体中可以包含数组，此时`结构体的alignment = max(数组中最大元素，结构体其他元素)`。例如：

```c
struct triple {
    short large [2];
    char small;
};
```

其中`short`类型 2 个字节，`char`类型 1 个字节。该结构体的长度 = 2 字节的整数倍。

## 2-D Arrays

一个嵌套的数组如下：

```c
int8_t nested [2][3] = {{0x00 , 0x01 , 0x02}, {0x10 , 0x11 , 0x12 }};
```

输入如下命令查看内存`nested`处的值：

```
(gdb) x/6bx nested
0x601076 <nested>:      0x00    0x01    0x02    0x10    0x11    0x12
```

可以看到一个单元是 1 个字节，一共 6 个单元。数组元素按照行顺序排列。

函数`access`的 C 版本如下：

```c
int8_t access(int8_t (* arr)[3], size_t row, size_t column) {
    return arr[row][column];
}
```

仔细查了一下[资料](https://zhuanlan.zhihu.com/p/335693933)，在 C 语言中这里有两种写法要注意一下区分：

```c
int (*arr)[10]; // 定义一个指针arr，指向一个包含 10 个元素的数组，arr 可以是 new int[n][3], 它可以是个二维数组
int* arr[10]; // 定义一个包含 10 个元素的数组，其中每个元素都是一个int类型的指针，其起始地址为 arr
```

这样声明的原因是：`[]`运算符的优先级比`*`高，因此需要通过`()`来把`*arr`括起来。

由此，`access`函数的传入参数`arr`是一个指针，该指针指向一个 3 个元素的数组。可以有`n`个这样的指针，构成一个二维数组。如`arr = new int[n][3]`，那么`arr`有 n 行，每行都是一个指向三个元素的数组。这种表示不能用于第二维度（列）不等于 3 的数组，如`int flipped [3][2]`。

如果要将 C 语言版本的`access`转化为汇编指令，`&arr[row][col] = arr + row * 3 + col`（因为这里每个`int`都是一个字节，因此不需要乘上多余的`sizeof(T)`，否则就需要乘上`sizeof(T)`。可以使用一个寄存器作为`arr`，计算`3 * row`，再加上`col`，最后对指针解引，放到返回值中。

对函数`access`进行反汇编，得到如下指令：

```
(gdb) disassemble access
Dump of assembler code for function access:
   0x00000000004005b5 <+0>:     lea    (%rsi,%rsi,2),%rax ;; rax = 3 * rsi
   0x00000000004005b9 <+4>:     add    %rax,%rdi ;; rdi += 3 * rsi
   0x00000000004005bc <+7>:     movzbl (%rdi,%rdx,1),%eax ;; eax = *(rdi + 3 * rsi + rdx)
   0x00000000004005c0 <+11>:    retq
End of assembler dump.
```

这里我想`%rdi`是`arr`的基地址，`%rsi`是`row`，`rdx`是`col`。我们首先计算了`3 * rsi`，将其加到`%rdi`中，然后计算`3 * %rsi + %rdx`。

现在给 3 个数组：

```c
int8_t first [3] = {0x00 , 0x01 , 0x02 };
int8_t second [3] = {0x10 , 0x11 , 0x12 };
int8_t * multilevel [2] = {first , second };
```

这里`multilevel`是一个嵌套的数组，其第一个元素`first`是一个 3 个字节的数组，其本身是个指针。第二个元素`second`同理。
`multilevel`的每个元素是 8 个字节。数组的每个元素是 1 个字节。输入如下指令检验：

```
(gdb) x/2gx multilevel
0x601060 <multilevel>:  0x0000000000601073      0x0000000000601070
(gdb) x/3bx first
0x601073 <first>:       0x00    0x01    0x02
(gdb) x/3bx multilevel[0]
0x601073 <first>:       0x00    0x01    0x02
(gdb) p &first
$4 = (int8_t (*)[3]) 0x601073 <first>
(gdb) p &second
$5 = (int8_t (*)[3]) 0x601070 <second>
```

将上述 C 语言程序换成如下程序：

```c
int8_t accessMultilevel (int8_t **arr , size_t row , size_t column) {
    return arr[row][column];
}
```

这里将`int8_t (*arr)[3]`换成了`int8_t **arr`，也就是说这个`arr`可以指向一个二维数组，而这个二维数组的长和宽可以不定。
这里的计算公式就是`a[row][col] = *(*(arr + row * 8) + column)`(因为`int8_t`是 1 个字节，所以无需乘上`sizeof(T)`)。此处`arr`应该是基地址，`row`存储在一个寄存器中，`column`存储在一个寄存器中。

对该函数进行反汇编，结果如下：

```
(gdb) disassemble accessMultilevel
Dump of assembler code for function accessMultilevel:
   0x00000000004005c1 <+0>:     add    (%rdi,%rsi,8),%rdx ;; %rdx += *(%rdi + 8 * %rsi)
   0x00000000004005c5 <+4>:     movzbl (%rdx),%eax ;; %eax = *(%rdx)
   0x00000000004005c8 <+7>:     retq
End of assembler dump.
```

这里`%rdx`中存储的是`column`，`%rdi`中存储的是`arr`的基地址，`%rsi`中存储的是`row`。如果`first`和`second`都含有 4 个元素的话，地址的计算不影响。但是如果俩数组长度不一样，那么索引的时候可能会出现地址越界的问题。

如果数组这样定义：

```c
int8_t * multilevel [2] = {first, first};
```

那么如果修改一个`first`的元素值的话，两个索引指向同一个数组，两索引对应数组那个值都会改变。

## Endianness (Optional)

还是之前那个`courses`结构体，我们先按照 4 个字节一组的单位打印它的值看看，再按照 1 个字节一组为单位打印前 4 个字节看看：

```
(gdb) x/4wx courses
0x601110 <courses>:     0x00015213      0x00015513      0x00018213      0x00018600
(gdb) x/4bx courses
0x601110 <courses>:     0x13    0x52    0x01    0x00
```

我们可以看到一个数(`int`类型，4 个字节)，按照 4 个字节一组打印的时候，显示的是`0x15213`，但是按照单个字节打印的时候发现低地址字节存放在低地址处，高地址字节存放在高地址处，因此该机器为小端序机器。小端序机器的缺陷在于不方便单字节读取，字节的顺序是倒过来的。

但是小端序机器也有优点，`narrowingCast`函数的 C 语言版本如下：

```c
int narrowingCast (long *num) {
    return (int) *num;
}
```

我们对`narrowingCast`函数进行反汇编，得到如下结果：

```
(gdb) disassemble narrowingCast
Dump of assembler code for function narrowingCast:
   0x00000000004005c9 <+0>:     mov    (%rdi),%eax
   0x00000000004005cb <+2>:     retq
End of assembler dump.
```

这个函数的功能是，将一个`long*`类型的指针解引，然后把它指向的地址的 4 个字节赋给`%eax`。
这里的一个问题是，对于一个数字：`0x0000000012345678`。如果是小端法，低位字节存储在`%rsp`处，一直到`%rsp + 3`。而如果是大端法，低位字节存储在`%rsp + 7`，高位字节存储在`%rsp + 4`。因此如果是大端法，就没法用`mov (%rdi),%eax`来获取值，而应该用`mov 4(%rdi),%eax`来获取值
