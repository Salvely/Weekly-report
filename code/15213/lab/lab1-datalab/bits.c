/*
 * CS:APP Data Lab
 *
 * Gwen
 *
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */

#endif
// 1
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

// 2
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
// 3
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

// 4
/*
 * logicalNeg - implement the ! operator, using all of
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */
int logicalNeg(int x)
{
   /**
    * if x == 0, x ^ 0x0 = 0
    */
   return ((x | (x + ~0 + (~(1 << 31) + 1))) >> 31) + 1;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x)
{
   /**
    * divide and conquer
    * for positive number, the number of bits = the last position of 1 + 1
    * for negative number, the number of bits = the last position of 1
    * inverse negative number and deal with it as the same as positive number
    * 1. judge the sign bit of x, if x is negative, inverse it
    * 2. judge the high 16 bits, if true(high 16 bits != 0x0), result + 16
    * 3. judge the high 8 bits, if true, result + 8
    * 4. judge the high 4 bits, if true, result + 4
    * 5. judge the high 2 bits, if true, result + 2
    * 6. judge the high 1 bits, if true, result + 1
    * 7. judge the last 1 bit, if true, result + !!x
    * 8. the final sum must + 1
    * 9. return the result
    */
   // neg x if it's negative
   int sign = ((x & (1 << 31)) >> 31);
   x = (sign & ~x) | (~sign & x);

   int b16, b8, b4, b2, b1, b0;

   // int mask_16 = (1 << 15) >> 15;
   b16 = !!(x >> 16) << 4;
   x = x >> b16;

   // int mask_8 = 0xff;
   b8 = !!(x >> 8) << 3;
   x = x >> b8;

   // int mask_4 = 0xf;
   b4 = !!(x >> 4) << 2;
   x = x >> b4;

   // int mask_2 = 0x3;
   b2 = !!(x >> 2) << 1;
   x = x >> b2;

   // int mask_1 = 0x1;
   b1 = !!(x >> 1);
   x = x >> b1;

   //! judge if the last bit == 1
   b0 = !!x;

   return b16 + b8 + b4 + b2 + b1 + b0 + 1;
}
// float
/*
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf)
{
   // first get the sign, exp and mag bit of the number
   unsigned sign = (uf >> 31) & 0x1;
   unsigned e = (uf >> 23) & ((1 << 8) - 1);
   unsigned f = (uf & ((1 << 23) - 1));

   if (e == 0)
   {
      // denormalized number
      // E = 1 - bias
      // frac = f

      //! how to multiply a denormalized number? frac * 2!
      f = f * 2;
   }
   else if (e == 0xff)
   {
      // special number
      // if frac = 0, then value = inf
      if (f == 0)
      {
         // frac = 1 / 0;
         return uf;
      }
      else
      {
         // if frac != 0, value = NaN
         return uf;
      }
   }
   else
   {
      // normalized number
      // E = e - bias
      // value = 1 + f

      e += 1;
      if (e == ~0)
      {
         return uf;
      }
   }

   return (sign << 31) | (e << 23) | f;
}
/*
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf)
{
   // first get the sign, exp and mag bit of the number
   unsigned sign = (uf >> 31) & 0x1;
   unsigned e = (uf >> 23) & ((1 << 8) - 1);
   float f = (uf & ((1 << 23) - 1)) / (1 << 23);

   // then get the exact sign, E and value of the number
   int s = 0;
   if (sign == 0)
      s = 1;
   else
      s = -1;

   int E = 0;
   float frac = 0;
   int bias = 127;
   if (e == 0)
   {
      // denormalized number
      // E = 1 - bias
      E = 1 - bias;
      // frac = f
      frac = f;
   }
   else if (e == 0xff)
   {
      //! COMPARE WITH 0XFF INSTEAD OF ~0
      // special number
      // if frac = 0, then value = inf
      if (f == 0)
      {
         // frac = 1 / 0;
         return 0x80000000u;
      }
      else
      {
         // if frac != 0, value = NaN
         return 0x80000000u;
      }
   }
   else
   {
      // normalized number
      // E = e - bias
      E = e - bias;
      // value = 1 + f
      frac = 1 + f;
   }
   if (E < 0)
   {
      return 0;
   }
   else if (E > 31)
   {
      //! REMEMBER THE SITUATION THAT E > 31
      return 0x80000000u;
   }

   return s * frac * (1 << E);
}
/*
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 *
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatPower2(int x)
{
   //! REMEMEBER THAT FLOATING POINT ITSELF IS IN THE FORMAT (-1)^S * M * 2.0^E
   // fit x into E
   x = x + 127;
   //! MIND THE SITUATION THAT X IS TOO LARGE OR TOO SMALL
   if (x >= 0xff)
      x = 0xff;
   else if (x <= 0)
      x = 0;
   unsigned result = (x << 23);
   return result;
}
