/* 
Problem Description (LeetCode Problem 9):
Given an integer x, return true if x is a palindrome, and false otherwise.
*/

/*
Problem       : Palindrome Number
Platform      : LeetCode
Difficulty    : Easy
Topic         : Math / Arrays
Language      : C++
Time Complexity  : O(log n)
Space Complexity : O(1)
*/
class Solution {
public:
    bool isPalindrome(int x) 
    {
        // Negative numbers or numbers ending with 0 (except 0) are not palindromes
        if (x < 0 || (x % 10 == 0 && x != 0))
         {
            return false;
        }

        int reverse = 0;

        while (x > reverse) 
        {
            reverse = reverse * 10 + x % 10;
//we are taking mod of numeber and stor it in reverse, next time we will multiply that num with 10 and then tak the mod and store it in reverse

            x = x / 10;   //for taking the next digit
        }

        // Check for even or odd length numbers
        return (x == reverse || x == reverse / 10);
    }
};