/*
===========================================================
Problem Description
-----------------------------------------------------------
Remove all occurrences of a given value from an array
in-place and return the number of remaining elements.

Only the first k elements must contain the valid values.
===========================================================

Problem        : Remove Element
Platform       : LeetCode 27
Difficulty     : Easy
Topic          : Arrays, Two Pointers
Language       : C++
Time Complexity: O(n)
Space Complexity: O(1)
===========================================================
*/

class Solution {
public:

    /*
    ===========================================================
    Approach: Two Pointer (Overwrite Method)

    Observation:
    We only need to keep elements that are not equal to val.
    We can shift valid elements forward while scanning.

    Algorithm:
    1. Initialize k = 0.
    2. Traverse array from i = 0 to n-1.
    3. If nums[i] != val:
           nums[k] = nums[i]
           k++
    4. After traversal return k.

    Why It Works:
    - k tracks the index where the next valid element should go.
    - All non-val elements get compacted at the start of the array.
    - Extra elements after k are irrelevant.

    Time Complexity: O(n)
    Space Complexity: O(1)
    ===========================================================
    */

    int removeElement(vector<int>& nums, int val) {
        
        int k = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != val) {
                nums[k] = nums[i];
                k++;
            }
        }

        return k;
    }
};