/*
---------------------------------------------------------
Problem Description
---------------------------------------------------------
Given a binary string s. Two operations are allowed:

Type-1: Move the first character to the end (rotation)
Type-2: Flip any character (0 -> 1 or 1 -> 0)

Return the minimum number of flips required to make the
string alternating.

---------------------------------------------------------
Metadata
---------------------------------------------------------
Problem: Minimum Number of Flips to Make Binary String Alternating
Platform: LeetCode
Difficulty: Medium
Topic: Sliding Window, String
Language: C++
Time Complexity: O(n)
Space Complexity: O(n)
---------------------------------------------------------
*/

/*
---------------------------------------------------------
Approach: Sliding Window + Rotation Trick
---------------------------------------------------------

Observation:
Two valid alternating patterns exist:
1) 010101...
2) 101010...

Because rotation is allowed, we duplicate the string:

ss = s + s

Now every rotation of length n appears as a window in ss.

Algorithm:
1. Let n = length of s
2. Create ss = s + s
3. Build two alternating patterns of length 2n:
      alt1 → 010101...
      alt2 → 101010...
4. Slide a window of size n across ss
5. Count mismatches with alt1 and alt2
6. Keep minimum mismatch

Why It Works:
Rotation becomes equivalent to checking every
substring of length n in s+s.

Time Complexity:
O(n)

Space Complexity:
O(n)
---------------------------------------------------------
*/

class Solution {
public:
    int minFlips(string s) {

        int n = s.length();
        string ss = s + s;

        string alt1 = "", alt2 = "";

        for(int i = 0; i < 2*n; i++)
        {
            alt1 += (i % 2 ? '1' : '0');
            alt2 += (i % 2 ? '0' : '1');
        }

        int diff1 = 0, diff2 = 0;
        int ans = INT_MAX;

        int left = 0;

        for(int right = 0; right < 2*n; right++)
        {
            if(ss[right] != alt1[right]) diff1++;
            if(ss[right] != alt2[right]) diff2++;

            if(right - left + 1 > n)
            {
                if(ss[left] != alt1[left]) diff1--;
                if(ss[left] != alt2[left]) diff2--;
                left++;
            }

            if(right - left + 1 == n)
            {
                ans = min(ans, min(diff1, diff2));
            }
        }

        return ans;
    }
};