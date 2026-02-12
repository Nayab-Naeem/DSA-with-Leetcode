/* 
Problem Description (LeetCode Problem 3713):
Given a string s consisting of lowercase English letters, 
a substring is called balanced if all distinct characters in it appear the same number of times.
Return the length of the longest balanced substring of s.
*/

/*
Problem       : Longest Balanced Substring I
Platform      : LeetCode
Difficulty    : Medium
Topic         : Strings / Hashing / Enumeration
Language      : C++
Time Complexity  : O(n^2)
Space Complexity : O(1)  // fixed alphabet size (26 letters)
*/
class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();
        int maxLen = 0;

        for (int i = 0; i < n; i++)
         {
            vector<int> freq(26, 0); //integer array of size 26,all no. initializes from 0.

            int distinct = 0;
            int maxFreq = 0;

            for (int j = i; j < n; j++)
             {
                int index = s[j] - 'a';  //converts the character s[j] into index

                if (freq[index] == 0)
                    distinct++;

                freq[index]++;
                maxFreq = max(maxFreq, freq[index]);

                int length = j - i + 1;

                if (length == distinct * maxFreq)   
                    maxLen = max(maxLen, length);
            }
        }

        return maxLen;
    }
};
