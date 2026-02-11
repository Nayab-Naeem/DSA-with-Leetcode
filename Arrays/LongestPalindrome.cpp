/* 
Problem Description (LeetCode Problem 5):
Given a string s, return the longest palindromic substring in s.
*/

/*
Problem       : Longest Palindromic Substring
Platform      : LeetCode
Difficulty    : Medium
Topic         : Strings / Dynamic Programming / Expand Around Center
Language      : C++
Time Complexity  : O(n^2)
Space Complexity : O(1)  // or O(n^2) if using DP
*/
class Solution {
public:
    string longestPalindrome(string s) {
        
        int n = s.length();
        if (n < 2) return s;

        int start = 0;
        int maxLen = 1;

        for (int i = 0; i < n; i++) {

            // ----- Odd length palindrome -----
            int left = i;
            int right = i;
                //comparing the centre index charatcer with the same one at first iteration then its left with its right and so on 
            while (left >= 0 && right < n && s[left] == s[right])
             {
                if (right - left + 1 > maxLen)
                 {
                    start = left;
                    maxLen = right - left + 1;
                }
                left--;
                right++;
            }

            // ----- Even length palindrome -----
            left = i;
            right = i + 1;

            while (left >= 0 && right < n && s[left] == s[right])
             {
                if (right - left + 1 > maxLen) {
                    start = left;
                    maxLen = right - left + 1;
                }
                left--;
                right++;
            }
        }

        return s.substr(start, maxLen);
    }
};
