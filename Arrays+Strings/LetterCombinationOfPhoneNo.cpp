/*
============================================================
Problem Description:
Given a string containing digits from 2-9 inclusive,
return all possible letter combinations that the number 
could represent. Return the answer in any order.

Problem: Letter Combinations of a Phone Number
Platform: LeetCode
Difficulty: Medium
Topic: Backtracking, Recursion, String
Language: C++
Time Complexity: O(4^n)
Space Complexity: O(n)
============================================================
*/
class Solution {
public:
    
    vector<string> letterCombinations(string digits) {
        
        // If empty input → return empty list
        if (digits == "") return {};
        
        // Phone mapping
        vector<string> map = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        
        vector<string> result;
        
        // Start recursion
        generate(digits, 0, "", result, map);
        
        return result;
    }
    
    void generate(string digits, int index, string current,
                  vector<string>& result,
                  vector<string>& map) {
        
        // If we built full word → save it
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }
        
        // Get letters for current digit
        string letters = map[digits[index] - '0'];
        
        // Try each letter
        for (int i = 0; i < letters.length(); i++) {
            
            // Add letter and go to next digit
            generate(digits, index + 1,
                     current + letters[i],
                     result, map);
        }
    }
};