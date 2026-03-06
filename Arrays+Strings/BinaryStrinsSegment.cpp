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

/*
---------------------------------------------------------
Approach: Detect Second Segment of Ones
---------------------------------------------------------

Observation:
If a '1' appears again after a '0', then there are two
segments of ones.

Example:
s = "1001"

1st segment → "1"
Then '0' appears
Then another '1' appears → second segment → invalid

Algorithm:
1. Traverse the string from index 0 to n-2.
2. Check if pattern "01" appears.
3. If "01" exists → return false.
4. If traversal completes → return true.

Why It Works:
"01" means zeros ended and ones started again,
which indicates a second segment of ones.

Time Complexity:
O(n) → single traversal of string

Space Complexity:
O(1) → no extra space used
---------------------------------------------------------
*/

class Solution {
public:
    bool checkOnesSegment(string s) {

        for(int i = 0; i < s.length() - 1; i++)
        {
            if(s[i] == '0' && s[i+1] == '1')
                return false;
        }

        return true;
    }
};