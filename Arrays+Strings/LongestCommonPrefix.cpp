/* 
Problem Description:
Write a function to find the longest common prefix string 
amongst an array of strings.

If there is no common prefix, return an empty string "".
*/

/*
Problem       : 14. Longest Common Prefix
Platform      : LeetCode
Difficulty    : Easy
Topic         : String, Array
Language      : C++
Time Complexity  : O(n * m)
Space Complexity : O(1)
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        string prefix = strs[0];

        for (int i = 1; i < strs.size(); i++)
         {
            while (strs[i].find(prefix) != 0) 
            {
                prefix.pop_back();
                if (prefix.empty()) return "";
            }
        }

        return prefix;
    }
};