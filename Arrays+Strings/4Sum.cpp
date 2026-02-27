/*
============================================================
Problem Description:
Given an array nums of n integers, return all unique
quadruplets such that their sum equals target.

Problem: 4Sum (number 18)
Platform: LeetCode
Difficulty: Medium
Topic: Sorting, Two Pointers
Language: C++
Time Complexity: O(n^3)
Space Complexity: O(1) (excluding result)
============================================================
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>> result;
        int n = nums.size();
        
        sort(nums.begin(), nums.end()); 
     //sorting for using two pointers and skipping duplicates
        
        for(int i = 0; i < n - 3; i++) {
            
            // Skip duplicate for first number
            if(i > 0 && nums[i] == nums[i-1]) continue;
            
            for(int j = i + 1; j < n - 2; j++) {
                
                // Skip duplicate for second number
                if(j > i + 1 && nums[j] == nums[j-1]) continue;
                
                int left = j + 1;
                int right = n - 1;
                
                while(left < right) {
                    
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                    
                    if(sum == target) {
                        result.push_back( {nums[i], nums[j], nums[left], nums[right]} );
                        
                        // Skip duplicates
                        while(left < right && nums[left] == nums[left+1]) left++;
                        while(left < right && nums[right] == nums[right-1]) right--;
                        
                        left++;
                        right--;
                    }
                    else if(sum < target) {  //If sum too small → move left ,If sum too big   → move right ←
                        left++;
                    }
                    else {
                        right--;
                    }
                }
            }
        }
        
        return result;
    }
};
//Structure of the array after sorting:
// i   j    left →        ← right
// |   |      |              |
// -2  -1     0    0    1    2