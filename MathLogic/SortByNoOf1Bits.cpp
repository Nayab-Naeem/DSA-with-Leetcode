/*
===============================================
Problem Description:
Given an integer array arr, sort the integers 
in ascending order by the number of 1's in their 
binary representation. 

If two integers have the same number of 1 bits,
then sort them in ascending numerical order.

Return the sorted array.

===============================================
Problem: 1356. Sort Integers by The Number of 1 Bits
Platform: LeetCode
Difficulty: Easy
Topic: Sorting, Bit Manipulation
Language: C++
Time Complexity: O(n log n)
Space Complexity: O(1)  (ignoring sorting space)
===============================================
*/

   class Solution {
public:
    static bool compare(int a, int b) {
        int countA = __builtin_popcount(a);   
        //its a built in function to give number of 1s in bit representation
        int countB = __builtin_popcount(b);
        
        if (countA == countB)                      //if both numbers have same count of 1s
            return a < b;      // Secondary sort
        
        return countA < countB; // Primary sort
    }
    
    vector<int> sortByBits(vector<int>& arr) {
        
        sort(arr.begin(), arr.end(), compare);
        return arr;
    }
};