/*
Problem: Concatenation of Consecutive Binary Numbers
Platform: LeetCode
Difficulty: Medium
Topic: Bit Manipulation, Math
Language: C++
Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution {
public:
    int concatenatedBinary(int n) {
        
        const int MOD = 1e9 + 7;
        long long res = 0;
        int bit_length = 0;
        
        for (int i = 1; i <= n; i++) {
            
            // Check if i is power of 2
            if ((i & (i - 1)) == 0) {
                bit_length++;
            }
            
            // Shift and append
            res = ((res << bit_length) | i) % MOD;
        }
        
        return (int)res;
    }
};
