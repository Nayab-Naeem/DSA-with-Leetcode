/* 
Problem Description (LeetCode Problem 94):
Given the root of a binary tree, return the inorder traversal of its nodes' values.
*/

/*
Problem       : Binary Tree Inorder Traversal
Platform      : LeetCode
Difficulty    : Easy
Topic         : Binary Tree / DFS / Recursion / Stack
Language      : C++
Time Complexity  : O(n)
Space Complexity : O(n)  // due to recursion stack or explicit stack
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> result;
        helper(root, result);
        return result;
    }

   //we r using helping function  
private:
    void helper(TreeNode* node, vector<int>& result)
     {
        if (node == nullptr) return;
        
        helper(node->left, result);      // Left
        result.push_back(node->val);     // Root
        helper(node->right, result);     // Right
    }
};
