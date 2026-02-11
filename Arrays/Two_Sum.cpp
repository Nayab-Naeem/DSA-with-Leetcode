/* 
Problem Description:
Given an array of integers nums and an integer target, return indices of the two numbers 
such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.
*/

/*
Problem       : Two Sum
Platform      : LeetCode
Difficulty    : Easy
Topic         : Arrays
Language      : C++
Time Complexity  : O(n)
Space Complexity : O(n)
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        //using hashing
        unordered_map<int, int> mp;  // value -> index

        for (int i = 0; i < nums.size(); i++)
         {
            int needed = target - nums[i];

            // Check if complement exists
            if (mp.find(needed) != mp.end())
             {
                return {mp[needed], i};
            }

            // Store current value and index
            mp[nums[i]] = i;
        }

        return {}; 
    }
};