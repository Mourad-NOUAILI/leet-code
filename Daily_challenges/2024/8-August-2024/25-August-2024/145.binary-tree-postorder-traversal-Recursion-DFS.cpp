/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
 */

// @lc code=start
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
#include<bits/stdc++.h>

/*
    Recursion DFS
    Time complexity: O(n)
    Space complexity: O(n)
    n: #nodes in the binary tree 
*/
typedef std::vector<int> vi;
class Solution {
    public:
        vi ans={};
    public:
        vi postorderTraversal(TreeNode* root) {
            if(!root) return ans;
            postorderTraversal(root->left);
            postorderTraversal(root->right);
            ans.push_back(root->val);
            return ans;
        }
};
// @lc code=end

