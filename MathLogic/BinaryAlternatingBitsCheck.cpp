/*
Problem       : 693. Binary Number with Alternating Bits
Platform      : LeetCode
Difficulty    : Easy
Topic         : Bit Manipulation
Language      : C++
Time Complexity  : O(log n)   // number of bits in n
Space Complexity : O(1)

Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits will always have different values.

 
*/

class Solution {
public:
    bool hasAlternatingBits(int n) {
        
        while (n > 0) {
            int bit = n & 1;   // get last bit
            
            n >>= 1;           // shift right
            
            if ((n & 1) == bit)   // compare with next bit
                return false;
        }
        
        return true;
    }
};
