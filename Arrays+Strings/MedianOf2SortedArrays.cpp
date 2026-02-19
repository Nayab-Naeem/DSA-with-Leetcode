/* 
Problem Description (LeetCode Problem 4):
Given two sorted arrays nums1 and nums2 of size m and n respectively,
return the median of the two sorted arrays.
The overall runtime complexity must be O(log (m + n)).

Problem       : Median of Two Sorted Arrays
Platform      : LeetCode
Difficulty    : Hard
Topic         : Binary Search / Divide and Conquer
Language      : C++
Time Complexity  : O(log(min(m, n)))
Space Complexity : O(1)
*/
/* We use the binary search on partition approach instead of merging arrays
 because merging would require touching every element (O(m+n)), which is slow
 for large arrays. The optimized method finds the correct partition of both arrays
 such that the left half contains the smaller elements and the right half the larger ones.
 Once the partition is correct, the median can be determined using only the boundary elements,
 achieving O(log(min(m,n))) time without scanning all elements. */


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        // Ensure nums1 is the smaller array
        if(nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);
        
        int m = nums1.size();
        int n = nums2.size();
        
        int left = 0, right = m;
        
        while(left <= right) {
            
            int partition1 = (left + right) / 2;
            int partition2 = (m + n + 1) / 2 - partition1;
            
            int maxLeft1  = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];
            int minRight1 = (partition1 == m) ? INT_MAX : nums1[partition1];
            
            int maxLeft2  = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];
            int minRight2 = (partition2 == n) ? INT_MAX : nums2[partition2];
            
            // Correct partition found
            if(maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                
                // If total length is even
                if((m + n) % 2 == 0)
                    return (max(maxLeft1, maxLeft2) + 
                            min(minRight1, minRight2)) / 2.0;
                
                // If total length is odd
                else
                    return max(maxLeft1, maxLeft2);
            }
            
            // Move left in nums1
            else if(maxLeft1 > minRight2)
                right = partition1 - 1;
            
            // Move right in nums1
            else
                left = partition1 + 1;
        }
        
        return 0.0; // Should never reach here
    }
};
