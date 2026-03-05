/*
Problem: Minimum Changes To Make Alternating Binary String 
Platform: LeetCode 1758
Difficulty: Easy
Topic: String, Greedy
Language: C++
Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int minOperations(string s) 
    {
        
        int start0 = 0;   //if string starts with 0
        int start1 = 0;   //if the string starts with 1

        for(int i = 0; i < s.length(); i++)
        {
            if(i % 2 == 0)          //even index
            {
                if(s[i] != '0') start0++;
                if(s[i] != '1') start1++;
            }
            else                     //odd index
            {
                if(s[i] != '1') start0++;
                if(s[i] != '0') start1++;
            }
        }

        return min(start0, start1);   //return the minimum of the two counts
    }
};