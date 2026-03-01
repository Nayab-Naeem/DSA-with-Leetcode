/*
Problem: Length of Last Word
Platform: LeetCode problem 58
Difficulty: Easy
Topic: String Manipulation
Language: C++
Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        int i = s.size() - 1;
        
        // Step 1: Skip trailing spaces from the end
        while (i >= 0 && s[i] == ' ') {
            i--;
        }
        
        // Step 2: Count characters until we hit a space or start of string
        while (i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }
        
        return length;
    }
};