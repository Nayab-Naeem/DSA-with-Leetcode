/*
Problem Description:
Given two integers left and right, return the count of numbers in the inclusive range [left, right]
having a prime number of set bits in their binary representation.
*/

// Metadata
// Problem: Prime Number of Set Bits in Binary Representation
// Platform: LeetCode problem 762
// Difficulty: Easy
// Topic: Bit Manipulation, Math
// Language: C++
// Time Complexity: O(N * logM) where N = right-left+1, M = maximum number value
// Space Complexity: O(1)

class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        // Set of primes up to 20 (max set bits possible for numbers <= 1e6)
        unordered_set<int> primes = {2, 3, 5, 7, 11, 13, 17, 19};
        
        int count = 0;
        for (int num = left; num <= right; num++) {
            int setBits = __builtin_popcount(num); // count 1s in binary
            if (primes.count(setBits)) {
                count++;
            }
        }
        return count;
    }
};