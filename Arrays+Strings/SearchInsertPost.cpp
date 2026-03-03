/*
Problem: Search Insert Position
Platform: LeetCode
Difficulty: Easy
Topic: Binary Search
Language: C++
Time Complexity: O(log n)
Space Complexity: O(1)
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        // Binary Search
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;  
            }
            else if (nums[mid] < target) {
                left = mid + 1;  
            }
            else {
                right = mid - 1;  
            }
        }

        // If target not found, left is the insertion position
        return left;
    }
};