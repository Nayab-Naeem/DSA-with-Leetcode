/*
Problem Description:
Implement the function myAtoi(string s) which converts a string into a 32-bit signed integer.
Rules:
1) Ignore leading whitespaces.
2) Check for optional '+' or '-' sign.
3) Read digits until a non-digit character appears.
4) If no digits are found, return 0.
5) If the number exceeds 32-bit signed integer range [-2^31, 2^31 - 1],
   clamp it to INT_MIN (-2147483648) or INT_MAX (2147483647).

Problem       : 8. String to Integer (atoi)
Platform      : LeetCode
Difficulty    : Medium
Topic         : Strings, Simulation
Language      : C++
Time Complexity  : O(n)
Space Complexity : O(1)
*/


class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.size();
        int sign = 1;
        long num = 0;   // use to detect overflow

        // For space ignoring
        while (i < n && s[i] == ' ') i++;

        // Check sign
        if (i < n && (s[i] == '+' || s[i] == '-')) 
        {
            if (s[i] == '-') sign = -1;
            i++;
        }

        // Convert digits
        while (i < n && isdigit(s[i])) 
        {
            int digit = s[i] - '0';

            //  Check overflow
            if (num > INT_MAX / 10 || 
               (num == INT_MAX / 10 && digit > 7)) 
               {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            num = num * 10 + digit;
            i++;
        }

        return sign * num;
    }
};
