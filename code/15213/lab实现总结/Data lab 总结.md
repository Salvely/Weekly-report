# 15-213 Lab 1: Data lab 实验总结

部分的题目我参考了一下网上的内容（出处已注明），其他的均为自己实现（有的题目的实现过程可能会有些繁琐），部分 dlc 检测出来可能会报些 error，但是 btest 均能过。

> 没有 TA 可太难了！自己实现了一天多，终于苟完了。不算完美，但也能看吧。

## bitXor

```c
/*
 * bitXor - x^y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y)
{
   /**
    * x + y = ~( ~x & ~y)
    */
   return ~((~(x & ~y)) & (~(y & ~x)));
}
```

bitXor 要求我们使用位操作来实现`^`运算符。根据运算定律我们知道: `a ^ b = (a & (~b)) | (b & (~a))`。但是问题来了，我们这里不允许使用`|`，只能用`~`和`&`。那么我们就必须使用这两个操作符来实现`|`运算。
通过德摩根定律我们知道：`a | b = ~((~a) & (~b))`。这不就解决问题了嘛，所以将这两个式子综合一下，最后的结果是`~((~(x & ~y)) & (~(y & ~x)))`

## tmin

```c
/*
 * tmin - return minimum two's complement integer
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void)
{
   /**
    * the most significant bit = 1, others = 0, so (1 << 31)
    */
   return (1 << 31);
}
```

这题要求我们返回最小的补码整数，返回类型为`int`。首先，在二进制补码表示中，最高位的权值为-1，其他位的权值为 1。因此，最小的补码整数 tmin 的最高位为 1，其他位为 0。而题目中`int`类型为 32 位，因此只要返回`(1 << 31)`即可。

## isTmax

```c
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x)
{
   /**
    * Tmax ^ Tmin = 0xffffffff, ~0xffffffff = 0x0, !0x0 = 0x1
    */
   // return !(~(x ^ (1 << 31)));

   /**
    * ~Tmax = Tmin -> ~Tmin + 1 = Tmin 且 Tmin != 0
    */
   int num = ~x;
   return !(num ^ (~num + 1)) & !!num;
}
```

tmax 是二进制补码中最大的数，通过分析这个数的特点，我们可以完成这道题目。

1. 该数除了最高位是 0 外，其他位均是 1。因此该数和(1<<31)（也就是 tmin）的亦或（或者和）为`0xffffffff`。`0xffffffff`按位取反得到`0x0`，而`0x0`按位取反得到`0x1`。但是其他的数并没有这个特性。

```c
return !(~(x ^ (1 << 31)));
```

2. 该数取反后得到 tmin，tmin 的一个特点是 tmin 和 -tmin 的表示相同。因此两者亦或得到 0。还有一个树也有这样的特性，也就是 0。因此我们需要排除 0 的可能性。我们使用`&`操作符来实现两种特性的叠加。我本没有想到该方法，是从这篇[知乎帖子](https://zhuanlan.zhihu.com/p/614126795)学习到的。

```c
int num = ~x;
return !(num ^ (~num + 1)) & !!num;
```

但是题目不允许在该题中使用移位运算符，因此只能使用方法二。

## allOddBits

```c
/*
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x)
{
   /**
    * tear the number into 4 parts, get rid of the other digits except 0xaa
    * if the results are all the same, then compare it with 0xaa, if there are the same, xor returns 0
    * otherwise not all odd bits in word set is set to 1
    */
   int first = (x >> 24) & 0xaa;
   int second = (x >> 16) & 0xaa;
   int third = (x >> 8) & 0xaa;
   int fourth = x & 0xaa;
   return !((first & second & third & fourth) ^ 0xaa);
}
```

对于单个字节的奇数位，我们可以使用`0xaa`作为 mask。
本题目中我将位打成 4 个部分，每个部分与 mask 相与。如果每个奇数位都是 1 的话，四个部分的比较结果应该相同，都等于`0xaa`，该值与`0xaa`异或得到`0x0`，取`!`后得到`0x1`。否则该值不为`0xaa`，同`0xaa`亦或得到其他非零值，取`!`后得到`0x0`。

## negate

```c
/*
 * negate - return -x
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x)
{
   return (~x + 1);
}
```

该题目中我们需要求解某个数的相反数。在课堂中我们学过，一个数和它相反数的和为 0。那么如何获得其相反数呢？以`x`为例，我们知道`x + ~x = ~0`，也就是全 f，然后`~0 + 1 = 0`。因此，`-x`的补码表示即为`~x + 1`。

## isAsciiDigit

```c
/*
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x)
{
   /**
    * least = (x & 0xf) - 0xa
    * if least > 0 (with 0 in most significant bit) then least = 0
    * else least = 1
    */
   int least = ((((x & 0xf) + (~0xa + 1)) >> 31) & 0x1);
   int second = !((x >> 4) ^ 0x3);
   return least & second;
}
```

这里我使用的方法是将该数拆分为最低位和其他位来比较。我们将最低位与`0xa`相减，如果求得的结果为负数，符号位即为 1，代表该值在 0-9 之间。接下来判断其他位是否为`0x3`，如果是，则和`0x3`异或结果为 0，通过逻辑`!`返回 1。

## conditional

```c
/*
 * conditional - same as x ? y : z
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z)
{
   /**
    * judge if x != 0, if true, !!x = 1, return y, otherwise !!x = 0, return z
    */

   // cond gets all f when !!x == 1
   int cond = ((!!x) << 31) >> 31;
   return (cond & y) | (~cond & z);
}
```

这里我们先获取`x`的值，如果`x != 0`，则`!!x = 0x1`，否则为`0x0`。扩展该值，当该值为`0x1`时与`y`相与得到 y。当该值为`0x0`，取反后与 z 相与得到 z。因为这两个值只取其一，当一边不为 0 时另一边必然为 0，因此两边用`|`连接。

## isLessOrEqual

```c
/*
 * isLessOrEqual - if x <= y  then return 1, else return 0
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y)
{
   // first compare their sign bit
   int sign_x = (x >> 31) & 0x1;
   int sign_y = (y >> 31) & 0x1;
   // return true if sign = 1(>0)
   int sign_diff = sign_x + (~sign_y + 1);
   int sign_bit = (sign_diff >> 31) & 0x1;

   // then compare the magnitude
   int mask = (~0) + (0x1 << 31);
   int mag_x = x & mask;
   int mag_y = y & mask;
   int mag_diff = mag_x + (~mag_y + 1);
   int mag_sign = !(mag_x ^ mag_y) | ((mag_diff >> 31) & 0x1);

   /**
    * 2 conditions return true:
    * 1. sign of x = 1 and sign of y = 0
    * 2. sign of x and y equals, and magnitude of x <= y
    */
   return (((!sign_bit) & sign_diff) | ((!sign_diff) & mag_sign));
}
```

这里要分几种情况：

1. 比较符号位，若
2. 
