/* 
Problem Description (LeetCode Problem 7):
Given a signed 32-bit integer x, return x with its digits reversed. 
If reversing x causes the value to go outside the signed 32-bit integer range [-2^31, 2^31 - 1], return 0.

Assume the environment does not allow storing 64-bit integers (signed or unsigned).
*/

/*
Problem       : Reverse Integer
Platform      : LeetCode
Difficulty    : Medium
Topic         : Math
Language      : C++
Time Complexity  : O(log n)
Space Complexity : O(1)
*/
class Solution 
{
public:
    int reverse(int x) 
    {
        int rev = 0;

        while (x != 0)

         {
            int digit = x % 10;           // Extract last digit
            x = x / 10;                  // Remove last digit for next

            // Check for overflow before placing digit
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && digit > 7)) //intmax and intmin are constants 
            return 0;

            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && digit < -8)) 
            return 0;

            rev = rev * 10 + digit;  // Append digit safely

        }

        return rev;
    }
};
