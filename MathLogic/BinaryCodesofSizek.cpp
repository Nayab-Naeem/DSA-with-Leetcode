/*
Problem: Check If a String Contains All Binary Codes of Size K
Platform: LeetCode
Difficulty: Medium
Topic: Bit Manipulation, Hashing, Sliding Window
Language: C++
Time Complexity: O(n)
Space Complexity: O(2^k)
*/
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (k > s.size()) return false;

        unordered_set<int> seen;
        int hash = 0;
        int allOnes = (1 << k) - 1;  // mask to keep last k bits

        for (int i = 0; i < s.size(); i++) {
            hash = ((hash << 1) & allOnes) | (s[i] - '0');
            if (i >= k - 1) {
                seen.insert(hash);
            }
        }

        return seen.size() == (1 << k);
    }
};