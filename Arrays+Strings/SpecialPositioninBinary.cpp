/*
Problem: Special Positions in a Binary Matrix
Platform: LeetCode  1582
Difficulty: Easy
Topic: Array, Matrix
Language: C++
Time Complexity: O(m * n)
Space Complexity: O(m + n)
*/
class Solution {
public:
 int numSpecial(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        vector<int> rowCount(m, 0);
        vector<int> colCount(n, 0);

        // Step 1: Count 1s in rows and columns
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 1) {
                    rowCount[i]++;
                    colCount[j]++;
                }
            }
        }

        int specialCount = 0;

        // Step 2: Check special positions
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 1 && 
                   rowCount[i] == 1 && 
                   colCount[j] == 1) {
                    specialCount++;
                }
            }
        }

        return specialCount;
    }
};