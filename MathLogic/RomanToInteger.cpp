/* 
Problem Description (LeetCode Problem 13):
Given a Roman numeral string s, convert it to an integer. 
Roman numerals are represented by the symbols I, V, X, L, C, D, and M, 
including specific subtraction cases such as IV (4), IX (9), XL (40), XC (90), CD (400), and CM (900).
*/

/*
Problem       : Roman to Integer
Platform      : LeetCode
Difficulty    : Easy
Topic         : Strings / Hashing
Language      : C++
Time Complexity  : O(n)
Space Complexity : O(1)
*/
class Solution {
public:
    int romanToInt(string s) {
        //hashing 
        unordered_map<char, int> mp = 
        {
            {'I', 1},            //assigning value to char key
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int sum = 0;

        for (int i = 0; i < s.length(); i++) 
        {
            // If current value is less than next value then subtract
            if (i + 1 < s.length() && mp[s[i]] < mp[s[i + 1]])
             {
                sum -= mp[s[i]];
            } 
            else
             {
                sum += mp[s[i]];      //if greater then add
            }
        }

        return sum;
    }
};
