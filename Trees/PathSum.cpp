/*
Problem: Path Sum
Platform: LeetCode problem 112
Difficulty: Easy
Topic: Binary Tree, Recursion
Language: C++
Time Complexity: O(n)
Space Complexity: O(h) where h is the height of the tree
*/
/** Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };*/

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL)
            return false;  

        // Check if leaf node
        if (root->left == NULL && root->right == NULL) {
            return targetSum == root->val; 
        }

        // Recurse on left and right child with updated target
        int remainingSum = targetSum - root->val;
        //backtracking
        if (root->left != NULL && hasPathSum(root->left, remainingSum))
            return true;

        if (root->right != NULL && hasPathSum(root->right, remainingSum))
            return true;

        return false;
    }
};