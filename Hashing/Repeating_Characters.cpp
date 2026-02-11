/* 
Problem Description (LeetCode Problem 3):
Given a string s, find the length of the longest substring without duplicate characters.
*/

/*
Problem       : Longest Substring Without Repeating Characters
Platform      : LeetCode
Difficulty    : Medium
Topic         : Strings / Hashing / Sliding Window
Language      : C++
Time Complexity  : O(n)
Space Complexity : O(min(n, charset_size))
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {                                      //using hashing with sliding window concept
        unordered_set<char> st;
        int left = 0;
        int maxLen = 0;

        for (int right = 0; right < s.length(); right++) {
            // If duplicate found, shrink window from left
            while (st.find(s[right]) != st.end()) 
            {
                st.erase(s[left]);
                left++;
            }

            // Add current character
            st.insert(s[right]);

            // Update maximum length
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
