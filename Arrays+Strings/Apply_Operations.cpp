/* 
Problem Description (LeetCode Problem 2460):
Given a 0-indexed array nums of non-negative integers, apply n - 1 operations where in the ith operation:
- If nums[i] == nums[i + 1], multiply nums[i] by 2 and set nums[i + 1] to 0. Otherwise, skip.
After all operations, shift all 0's to the end of the array. Return the resulting array.
*/

/*
Problem       : Apply Operations to an Array
Platform      : LeetCode
Difficulty    : Easy
Topic         : Arrays
Language      : C++
Time Complexity  : O(n)
Space Complexity : O(1)
*/
class Solution 
{
public:
    vector<int> applyOperations(vector<int>& nums) 
    {
        int n = nums.size();

        // Phase 1: apply operations
        for (int i = 0; i < n - 1; i++) 
        {
            if (nums[i] == nums[i + 1])
             {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }

        // Phase 2: move zeros to end
        int k = 0;
        for (int i = 0; i < n; i++)
         {
            if (nums[i] != 0) {             
                nums[k] = nums[i];        //shifting the non 0s in left
                k++;
            }
        }

        while (k < n)
         {
            nums[k] = 0;      //adding 0s in remaining array
            k++;
        }

        return nums;
    }
};
