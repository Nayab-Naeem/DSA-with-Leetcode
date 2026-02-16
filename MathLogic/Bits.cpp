/*
Problem        : Reverse Bits
Platform       : LeetCode (#190)
Difficulty     : Easy
Topic          : Bit Manipulation
Language       : C++

Approach:
- Iterate through all 32 bits of the integer.
- Extract the least significant bit (LSB) using (n & 1).
- Shift result left to make space.
- Append extracted bit to result.
- Right shift original number to process next bit.
- Use unsigned int to avoid sign-extension issues.

Time Complexity  : O(32) -> O(1)
Space Complexity : O(1)
*/

class Solution {
public:
    int reverseBits(int n) {
        unsigned int num = n;   // Prevent sign-extension during right shift
        unsigned int result = 0;

        for(int i = 0; i < 32; i++) {
            result <<= 1;           // Make space for next bit
            result |= (num & 1);    // Extract and append LSB
            num >>= 1;             // Shift input to process next bit
        }

        return result;
    }
};
