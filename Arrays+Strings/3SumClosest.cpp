/*
Problem        : 3Sum Closest
Platform       : LeetCode (#16)
Difficulty     : Medium
Topic          : Two Pointers, Sorting
Language       : C++

Approach:
- Sort the array to apply the two-pointer technique.
- Fix one element at index i.
- Use two pointers:
    - left = i + 1
    - right = n - 1
- Calculate currentSum = nums[i] + nums[left] + nums[right].
- Track the closest sum by comparing absolute difference with target.
- If currentSum < target → move left pointer forward.
- If currentSum > target → move right pointer backward.
- If currentSum == target → return target immediately (exact match).
- Continue until all possibilities are checked.

Time Complexity  : O(n^2)
Space Complexity : O(1)
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        int closestSum = nums[0] + nums[1] + nums[2];
        
        for (int i = 0; i < n - 2; i++) {
            int left = i + 1;
            int right = n - 1;
            
            while (left < right) {
                int currentSum = nums[i] + nums[left] + nums[right];
                
                // Update closest sum
                if (abs(currentSum - target) < abs(closestSum - target)) {
                    closestSum = currentSum;
                }
                
                if (currentSum < target) {
                    left++;
                }
                else if (currentSum > target) {
                    right--;
                }
                else {
                    return target; // exact match
                }
            }
        }
        
        return closestSum;
    }
};