/* 
 * CS2011 Lab1
 * 
 * <Please put your name (First and Last) here>
 * Daniel Vennemeyer
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
  //Each side returns the half of the unique bits, and then I or them together to get the full xor
  return (~x & y) | (x & ~y);
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  //tmin should always be one with all zeroes under a twos complement system
  return 1 << 31;

}
//2
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  //I set up a bit mask called all odds, where all of the odd bits are 1
  //I then used the and operator to determine whether all the odd bits matched my mask
  //I checked this by xoring the result back with the mask again which will return 0 if they are equal
  //I then took the logical not of that to return 1 if the two are equal instead
  int all_odds = (0xAA<<24) + (0xAA<<16) + (0xAA<<8) + 0xAA;
  return !((x&all_odds) ^ all_odds);
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  //I used the definition of an additive inverse in a two's complement system, as we learned in class
  return (~x) + 1;
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
  //copied the code I came up with for isLessOrEqual and then replaced y with the max values, 39
  //then I did the same thing to determine whether is was greater than or equal to 30, except I took the not of it and I had to lower the value to 2f because this does the greater than operator not the greter than equal to operator
  return !((0x39 + ((~x) + 1) >> 31) & 1) & ((0x2f + ((~x) + 1) >> 31) & 1);
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  //uses ! to determine whether x = 0, then finds the additive inverse of the result
  //This will result in 0 being all zeroes still and anything else being all ones 
  //I take the not of that so when I and it with the y value either the y value will remain perfectly or it will be 0
  //I do this same thing to the z value and then or them which is fine because one of those values must be equal to 0
  return (~(~(!x)+1) & y) | ((~(!x)+1) & z);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  //Subtracts the two numbers (by adding x's additive inverse) 
  //Then returns whether the result is positive or negative by extracting the most significant bit using the shift and and operators
  //But in case of overflow, it also looks at the sign of the two numbers and returns 1 if x is negative and y us not
  int sign = !(x >> 31) ^ !(y >> 31);
  return (sign & (x >> 31)) | (!sign  & !(y+(~x+1) >> 31));
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
  //Determines whether x is equal to its additive inverse (only is true for 0) but I have to to the inverses of those because of overflow errors
  //in this case the xor operator acts as an equals sign that returns 0 if the two numbers are equal
  //by shifting and anding we get only whether or not the most significant bit is a 1, which it will be for every case except 1
  //this means that you get 1 for every number except zero which you get 0 for
  //I then just toggle that least significant bit with the final xor
  return (((~x) & (~(~x + 1))) >> 31) & 1;
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
  //goes through and checks every single set of bits and checks whether they are necessary
  // if they are, they are added to the total bits count

  int total_bits = 1;
  int s = x >> 31;
	x = x^s;
	int bit_check = !!(x >> 16) <<4;
  total_bits += bit_check;

	x = x >> bit_check;
	bit_check = !!(x >> 8) <<3;
  total_bits += bit_check;

	x = x >> bit_check;
	bit_check = !!(x >> 4) <<2;
  total_bits += bit_check;

	x = x >> bit_check;
	bit_check = !!(x >> 2) << 1;
  total_bits += bit_check;

	x = x >> bit_check;
	bit_check = !!(x >> 1);
  total_bits += bit_check;

	x = x >> bit_check;
	bit_check = x;
  total_bits += bit_check;

  return bit_check;
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
  // follows the example from the slides in class, more or less
  // slide 35
  int s = (1<<31);
  if ((uf &(~s)) >= (0xFF <<23))
  {
    return uf;
  } 
  else if ((uf & (0xFF << 23)) == 0)
  {
    return (uf & ~(0x1FF << 23)) << 1 | (uf & s);
  }
  else
  {
    return uf + (1<< 23);
  }
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
  //Followed the the slides from class again
  // slide 9, 12, 14
  int s = uf >> 31 << 31;
  int exp = (uf >> 23) & 0xFF;
  int frac = ((uf << 8) >> 8) | (1 << 31);
  int v;

  if(exp < 127) 
  {
    return 0;
  }
  else if(exp >= 158)
  {
    return 1 << 31;
  } 
  else
  {
    v = frac >> (150 - exp);
    if(s)
    {
      v = ~v+1;
    } 
    return v;
  }
}
