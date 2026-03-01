/*
Problem: Plus One
Platform: LeetCode problem 66
Difficulty: Easy
Topic: Array, Math
Language: C++
Time Complexity: O(n)
Space Complexity: O(1) (ignoring the space for the output if carry increases length)
*/

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        // Start from the least significant digit
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i] += 1;
                return digits; // No carry needed, return result
            }
            digits[i] = 0; // Set current digit to 0 and carry over
        }
        
        // If all digits were 9, we need an extra digit at the front
        digits.insert(digits.begin(), 1);
        return digits;
    }
};