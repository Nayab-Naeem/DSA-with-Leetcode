/*
Problem        : Binary Gap
Platform       : LeetCode (#868)
Difficulty     : Easy
Topic          : Bit Manipulation
Language       : C++

Approach:
- Traverse the binary representation of n using bitwise operations.
- Track the position (index) of each bit while shifting.
- When a '1' is found:
    - If this is not the first '1', compute distance from previous '1'.
    - Update maximum distance if needed.
- Right shift n to examine next bit.
- Continue until n becomes 0.

Time Complexity  : O(log n)
Space Complexity : O(1)
*/
class Solution {
public:
    int binaryGap(int n) {
        int lastPosition = -1;   // stores index of previous '1'
        int maxDistance = 0;
        int position = 0;       // current bit index
        
        while (n > 0) {
            if (n & 1) {  // if current bit is 1
                if (lastPosition != -1) {
                    maxDistance = max(maxDistance, position - lastPosition);
                }
                lastPosition = position;
            }
            n >>= 1;      // shift right
            position++;
        }
        
        return maxDistance;
    }
};