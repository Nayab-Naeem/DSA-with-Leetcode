/* 
Problem Description (LeetCode Problem 15):
Given an integer array nums, return all unique triplets [nums[i], nums[j], nums[k]] such that 
i != j, i != k, j != k, and nums[i] + nums[j] + nums[k] == 0. 
The solution set must not contain duplicate triplets.
*/

/*
Problem       : 3Sum
Platform      : LeetCode
Difficulty    : Medium
Topic         : Arrays / Two Pointers / Hashing
Language      : C++
Time Complexity  : O(n^2)
Space Complexity : O(n)
*/
class Solution
 {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
     {
        vector<vector<int>> res;           // To store the triplets
        sort(nums.begin(), nums.end());    // Step 1: sort the array
        int n = nums.size();

        for(int i = 0; i < n - 2; i++) {
            // Skip duplicate numbers for the first element
            if(i > 0 && nums[i] == nums[i - 1]) 
            continue;

            int left = i + 1;
            int right = n - 1;

            while(left < right)
             {
                int sum = nums[i] + nums[left] + nums[right];

                if(sum == 0) {
                    res.push_back({nums[i], nums[left], nums[right]});

                    // Skip duplicates for the second element
                    while(left < right && nums[left] == nums[left + 1]) left++;
                    // Skip duplicates for the third element
                    while(left < right && nums[right] == nums[right - 1]) right--;

                    left++;
                    right--;
                }
                else if(sum < 0) {
                    left++;     // Need a larger number
                } else {
                    right--;    // Need a smaller number
                }
            }
        }

        return res;
    }
};
