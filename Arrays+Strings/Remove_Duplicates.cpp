/* 
Problem Description (LeetCode Problem 26):
Given a sorted integer array nums, remove the duplicates in-place such that each unique element appears only once. 
Return the number of unique elements k. The first k elements of nums should contain the unique numbers in order. 
The remaining elements beyond index k - 1 can be ignored.
*/

/*
Problem       : Remove Duplicates from Sorted Array
Platform      : LeetCode
Difficulty    : Easy
Topic         : Arrays / Two Pointers
Language      : C++
Time Complexity  : O(n)
Space Complexity : O(1)
*/
class Solution
{
    public:
int removeDuplicates(vector<int>& nums)
{
    if (nums.size() == 0)
     return 0;

    int k = 1;  // index for next unique element

    for (int i = 1; i < nums.size(); i++)           //i=1 means 2nd index
     {
        if (nums[i] != nums[i - 1])                //i-1 means previous index
         {
            nums[k] = nums[i];                     //addedd in the unique elements
            k++;
        }
    }

    return k;
}

};