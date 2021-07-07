/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>: Jie
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
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  // return ~(~x&~y)&~(x&y);
  return ~(~(x&~y)&~(~x&y)); // both solution works. 
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {

  return 1<<31;

}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
  // return !(x ^ (0x7fffffff)); // don't comply with DLC
  return !((x+1)+(x+1)) & !!(x+1);
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  const int odd_t = 0xAA;
  int b = odd_t << 8; // b = 0xAA00
  int c = b + odd_t; // c = 0xAAAA
  int e = (c << 16) + c; // e = 0xAAAAAAAA
  return !((x & e) ^ e);

  // return !((x & odd_t) ^ odd_t) & !((x>>4 & odd_t) ^ odd_t) & !((x>>8 & odd_t) ^ odd_t) & !((x>>12 & odd_t) ^ odd_t) & !((x>>16 & odd_t) ^ odd_t) & !((x>>20 & odd_t) ^ odd_t) & !((x>>24 & odd_t) ^ odd_t) & !((x>>28 & odd_t) ^ odd_t); // correct but too many operatos (38 operators exceeds max of 12)
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return ~x+1;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  int a = !((x>>4) ^ (0x03)); // a = 1 if x is 0x3_
  int b = x & 0xF; // b = x的后4位
  int c = ~0xA + 1; // c = -A
  int d = !!((b + c) & (1 << 31)); // d = (b - A) & (0x8000_0000_0000_0000): check if the 31st bit of (b - 0xA) = 1
  return a & d;
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  int a = !!(x); // x = 0 -> a = 0; x!=0 -> a = 1;
  int c = ~a + 1; // x = 0 -> c = 0; x!=0 -> c = 0xFFFFFFFF
  return (y & c) | (z & ~c);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  int sign_x = x >> 31;
  int sign_y = y >> 31;
  int sign_same = !(sign_x ^ sign_y); // = 1 if sign_x = sign_y; = 0 if sign_x != sign_y
  int case_not_same = (!sign_same)&(~sign_y); // x为负数，y为正数
  
  int a = ~y; // a = -y - 1
  int diff = x + a; // diff = x - y - 1
  int sign_diff = diff >> 31;
  int case_same = (sign_same)&(sign_diff); // x,y同号; x-y-1为负数
  return case_not_same | case_same;
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
  return ((x | (~x+1)) >> 31) + 1;
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
int howManyBits(int x) {
  int b16,b8,b4,b2,b1,b0;
  int MSB = x >> 31; // MSB=0...0 if x>=0; MSB=1...1 if x<0
  x = (~x & MSB) | (x & ~MSB); 
  b16 = !!(x>>16) << 4; // 如果高16位不为0，则b16=16, 然后右移16位关注高16位；如果高16位为0，则b16=0
  x >>= b16;
  b8 = !!(x>>8) << 3; // 如果高16+8位不为0，则b8=8, 然后右移8位关注高24位；如果高24位为0，则b8=0
  x >>= b8;
  b4 = !!(x>>4) << 2;
  x >>= b4;
  b2 = !!(x>>2) << 1;
  x >>= b2;
  b1 = !!(x>>1);
  x >>= b1;
  b0 = x;
  return b0 + b1 + b2 + b4 + b8 + b16 + 1;
}
//float
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
unsigned floatScale2(unsigned uf) {
  int s = (uf & 0x80000000) >> 31;
  int exp = (uf & 0x7f800000) >> 23;
  int frac = (uf & 0x7fffff);
  unsigned res;

  if (exp == 0xFF) { // when argument is NaN / infinity, return argument
    return uf; 
  } else if (exp == 0) { // denormalized: frac << 1
    frac <<= 1;
    res = s << 31 | exp << 23 | frac;
  } else { // normalized: exp++
    exp++;
    res = s << 31 | exp << 23 | frac;
  }
  return res;
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
int floatFloat2Int(unsigned uf) {
  int s = (uf & 0x80000000) >> 31;
  int exp = (uf & 0x7f800000) >> 23;
  int frac = (uf & 0x7fffff);
  int res;
  int E = exp - ((1<<7) - 1); // Bias = 2^7 - 1 = 127
  
  if (exp == 0xFF) { // exception
    return 0x80000000;
  } else if (exp == 0) { // denormalized: < 1
    return 0; // rounding towards zero?
  } else if (E > 30) { // overflow
    return 0x80000000;
  } else if (E >= 23) {
    unsigned M = 1 << 23 | frac;
    res = M << (E-23);
  } else if (E >= 0) { // 0 <= E <= 22
    unsigned M = 1 << 23 | frac;
    res = M >> (23 - E);
  } else { // E < 0
    res = 0;
  }

  if (s == 1) { // 负数
    res = -res;
  } else {
    res = res;
  }

  return res;
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
unsigned floatPower2(int x) {
  unsigned res;
  int exp, frac;
  // unsigned s = 0; // 符号位一定是0，都是正数
  if (x > 127) { // +INF
    res = 0x7f800000;
  } else if (x >= -126) { // -126 <= x <= 127: normalized
    exp = x + 127; // Bias = 127
    res = exp << 23; // frac = 0
  } else if (x >= -149) { // -149 <= x <= -127: denormalized
    exp = 0;
    frac = 1 << (x + 149);
    res = frac;
  } else {
    res = 0;
  }
  return res;
}
