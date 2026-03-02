/*
Problem: Find the Index of the First Occurrence in a String
Platform: LeetCode problem 28
Difficulty: Easy
Topic: String, Two Pointers
Language: C++
Time Complexity: O(n * m)
Space Complexity: O(1)
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int n = haystack.length();
        int m = needle.length();
        
        if (m > n) return -1;
        
        for (int i = 0; i <= n - m; i++) {
            
            int j = 0;
            
            while (j < m && haystack[i + j] == needle[j]) {
                j++;
            }
            
            if (j == m) {
                return i;   // full match found
            }
        }
        
        return -1;  // no match
    }
};