/* 
Problem Description:
Given an integer num, convert it to a Roman numeral.
Roman numerals consist of the symbols I, V, X, L, C, D, M.
Use subtractive notation for 4, 9, 40, 90, 400, 900 (IV, IX, XL, XC, CD, CM).
1 <= num <= 3999
*/

/*
Problem       : Integer to Roman problem no. 12
Platform      : LeetCode
Difficulty    : Medium
Topic         : Simulation / Greedy / Strings
Language      : C++
Time Complexity  : O(1) // max 13 symbols in worst case (num <= 3999)
Space Complexity : O(1) // result string
*/

class Solution {
public:
    string intToRoman(int num) {
        // Symbols and their corresponding values
        vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> symbols = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        
        string result = "";
        
        for (int i = 0; i < values.size(); i++) {
            while (num >= values[i]) {
                num -= values[i];
                result += symbols[i];
            }
        }
        
        return result;
    }
};
