/*
Problem       : Container With Most Water
Problem No    : 11
Platform      : LeetCode
Difficulty    : Medium
Topics        : Two Pointers, Greedy
Language      : C++

------------------------------------------------------------
Problem Statement:
Given an integer array height of length n, where each element 
represents a vertical line drawn at index i with height[i].

Find two lines that together with the x-axis form a container 
such that the container stores the maximum amount of water.
Return the maximum area.
Time Complexity  : O(n)
Space Complexity : O(1)

------------------------------------------------------------
*/
class Solution {
public:
    int maxArea(vector<int>& height)
     {
        int left = 0;                  //pointers
        int right = height.size() - 1;
        int maxWater = 0;

        while (left < right) 
        {
            int width = right - left;            //use indexes
            int h = min(height[left], height[right]);      // for height use values
            int area = width * h;

            maxWater = max(maxWater, area);

            if (height[left] < height[right])
                left++;
            else
                right--;
        }

        return maxWater;
    }
};

