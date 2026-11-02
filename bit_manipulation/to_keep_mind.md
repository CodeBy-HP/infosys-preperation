Computer store negative number using a system called two's compliment

to make a number neg -x

it does two things 
it flips very single bit ~x
adds 1 to the result


  10011  (~x)
+ 00001  (add 1)
-------
  10100  (This is now -x)



x & (-x)

gives us the first set bit with all the bits as unset

    x:  01100
   -x:  10100
-----------
    &:  00100

    
In binary, subtracting 1 from a number flips the rightmost 1 to a 0, and turns all the 0s to its right into 1s.
Example: 1010 - 1 = 1001

* special case
when we do 0 - 1

Modern computers use a system called Two's Complement to represent negative numbers. In this system, -1 is represented by turning every single bit on.

If we look at this in a simple 8-bit example:

0 in binary is 00000000

If you subtract 1, the computer tries to borrow from the next bit over. Since there are no 1s to borrow from, it wraps around (underflows), turning all bits to 1.

0 - 1 becomes 11111111 (which represents -1).

x & filter (filter will unset all the bits of x that are not set in it) 

xor of two numbers is addition without carry

AND find the carry

we can represent any number in powers of 2.

This is a mathematical guarantee in combinatorics: If a bit is turned on (1) in AT LEAST one number in your array, it will be turned on in exactly half of all possible subsets.

to check if all the bits are differnt btw two numbers just do & , if (a& b == 0) that means all the bits of these numbers are different
