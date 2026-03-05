/* Problem: Climbing Stairs
Platform: LeetCode 70
Difficulty: Easy
Topic: Dynamic Programming, Fibonacci
Language: C++
Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution {
public:
    int climbStairs(int n) {
        if (n<=2)
     { return n; }
     int prev2 =1;
     int prev1 =2;
     int current;
     for (int i =3;i<=n;i++)
     {
        current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
     }
     return prev1;
    }
};