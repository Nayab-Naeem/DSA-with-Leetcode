/*
Problem       : 6. Zigzag Conversion
Platform      : LeetCode
Difficulty    : Medium
Topic         : Strings / Simulation
Language      : C++

Problem Summary:
- Write the string in zigzag pattern across numRows.
- Then read row by row to form the final string.

Approach:
- If numRows == 1, return original string.
- Use a vector<string> of size numRows.
- Traverse the string and simulate zigzag movement:
    - Move downward until last row.
    - Then move upward until first row.
- Append each character to its respective row.
- Finally, concatenate all rows.

Time Complexity  : O(n)
Space Complexity : O(n)
*/

class Solution {
public:
    string convert(string s, int numRows)
     {
        
    
        if (numRows == 1 || numRows >= s.size())
            return s;
        
        vector<string> rows(numRows);
        
        int currentRow = 0;
        bool goingDown = false;
        
        for (char c : s) {
            rows[currentRow] += c;
            
            // Change direction at top or bottom
            if (currentRow == 0 || currentRow == numRows - 1)
                goingDown = !goingDown;
            
            currentRow += goingDown ? 1 : -1;
        }
        
        // Combine all rows
        string result;
        for (string row : rows)
            result += row;
        
        return result;
    }
};
