/* 
Problem Description:
Given two binary strings a and b, return their sum as a binary string.
Each string consists only of '0' or '1' characters and does not contain leading zeros except for the zero itself.
You must simulate the binary addition and return the resulting binary string.
*/

/*
Problem       : Add Binary problem no. 67
Platform      : LeetCode
Difficulty    : Easy
Topic         : Strings / Simulation / Binary Addition
Language      : C++
Time Complexity  : O(max(n, m)) // n = length of a, m = length of b
Space Complexity : O(max(n, m)) // for storing result
*/

class Solution {
public:
    string addBinary(string a, string b) 
    {
        int i = a.length() - 1;  // pointer for a
        int j = b.length() - 1;  // pointer for b
        int carry = 0;         
        string result = "";     

        // loop until both strings and carry are done
        while (i >= 0 || j >= 0 || carry)
         {
            int sum = carry;  

            if (i >= 0) 
            {
                sum += a[i] - '0';  // convert char to int
                i--;
            }

            if (j >= 0) {
                sum += b[j] - '0';
                j--;
            }

            result += (sum % 2) + '0';  // result bit
            carry = sum / 2;            // update carry
        }

        reverse(result.begin(), result.end());  // reverse to get correct order
        return result;
    }
};
