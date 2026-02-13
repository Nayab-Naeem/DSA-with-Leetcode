/* 
Problem Description (LeetCode Problem 3714):
Given a string s consisting only of characters 'a', 'b', and 'c'.
A substring is called balanced if all distinct characters in it 
appear the same number of times.

Return the length of the longest balanced substring.
*/

/*
Problem       : Longest Balanced Substring II
Platform      : LeetCode
Difficulty    : Medium
Topic         : Strings / Hashing / Prefix Difference
Language      : C++
Time Complexity  : O(n)
Space Complexity : O(n)
*/
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for (char ch : s) {
            
            // If opening bracket → push
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            }
            else {
                // If stack empty → invalid
                if (st.empty()) return false;
                
                char top = st.top();
                st.pop();
                
                // Check matching
                if ((ch == ')' && top != '(') ||
                    (ch == '}' && top != '{') ||
                    (ch == ']' && top != '[')) {
                    return false;
                }
            }
        }
        
        // Stack must be empty at end
        return st.empty();
    }
};
