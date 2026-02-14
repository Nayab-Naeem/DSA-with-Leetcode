/*
Problem       : Champagne Tower
Problem No    : 799
Platform      : LeetCode
Difficulty    : Medium
Topics        : Dynamic Programming, Simulation
Language      : C++

------------------------------------------------------------
Problem Statement:
Glasses are arranged in a pyramid form where:
Row i contains (i + 1) glasses.

Each glass can hold at most 1 cup of champagne.
When a glass overflows, the extra liquid is split equally
between the two glasses directly below it.

Given:
    poured        → total cups poured into top glass
    query_row     → target row (0-indexed)
    query_glass   → target glass in that row

Return how full that glass is (value between 0 and 1).
------------------------------------------------------------
Time Complexity  : O(100^2)  → Constant (bounded by constraints)
Space Complexity : O(100^2)
------------------------------------------------------------
*/
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) 
    {
        
        vector<vector<double>> dp(101, vector<double>(101, 0.0));
        
        // Pour all champagne into the top glass
        dp[0][0] = poured;

        for (int i = 0; i <= query_row; i++)   //row iteration
         {
            for (int j = 0; j <= i; j++)      //column iteration
            {

                // If current glass overflows
                if (dp[i][j] > 1.0) {
                    double overflow = (dp[i][j] - 1.0) / 2.0;

                    // Distribute overflow to next row
                    dp[i+1][j]     += overflow;    //left glass
                    dp[i+1][j+1]   += overflow;   //right glass

                    // Cap current glass at 1 (max capacity)
                    dp[i][j] = 1.0;
                }
            }
        }
        return min(1.0, dp[query_row][query_glass]);
    }
};
