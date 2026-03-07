/*
---------------------------------------------------------
Problem Description
---------------------------------------------------------
Given a binary string s without leading zeros, return true
if the string contains at most one contiguous segment of
ones. Otherwise return false.

---------------------------------------------------------
Metadata
---------------------------------------------------------
Problem: Check if Binary String Has at Most One Segment of Ones
Platform: LeetCode
Difficulty: Easy
Topic: String
Language: C++
Time Complexity: O(n)
Space Complexity: O(1)
---------------------------------------------------------
*/


class Solution {
public:
    bool checkOnesSegment(string s) {
        for(int i = 0; i < s.length() - 1; i++)
        {
            if(s[i] == '0' && s[i+1] == '1')  //comparison of current and next character
                return false;
        }
        return true;
    }
};