/*
Problem Description:
Given a binary string s, return the number of non-empty substrings 
that have equal number of 0's and 1's, and where all 0's and all 1's 
in the substring are grouped consecutively.
Substrings that occur multiple times should be counted multiple times.
*/

/*
Problem       : 696. Count Binary Substrings
Platform      : LeetCode
Difficulty    : Easy
Topic         : Strings, Consecutive Group Counting
Language      : C++
Time Complexity  : O(n)
Space Complexity : O(1)
*/
class Solution {
public:
    int countBinarySubstrings(string s)
     {
        int prevGroup = 0;
        int currGroup = 1;
        int result = 0;

        for (int i = 1; i < s.size(); i++) 
        
    {
            if (s[i] == s[i - 1])      //if consecutive values are same
            {
                currGroup++;           // inc count of groups
            } 
            else 
            {
                result += min(prevGroup, currGroup); 
                // add the min length bet prev and curr group in result
                prevGroup = currGroup;
                currGroup = 1;
            }
        }

        // Add last pair
        result += min(prevGroup, currGroup);

        return result;
    }
};
