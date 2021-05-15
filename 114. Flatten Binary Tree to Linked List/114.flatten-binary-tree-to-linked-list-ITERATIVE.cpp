/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
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
class Solution {
public:
    void flatten(TreeNode* root) {
        stack<TreeNode*> s ;
        s.push(root);
        while (root != nullptr && !s.empty()){
            TreeNode *current = s.top();
            s.pop();
            if (current->right != nullptr){
                s.push(current->right);
            }
            if (current->left != nullptr){
                s.push(current->left);
            }
            if (!s.empty()) current->right = s.top();
            current->left = nullptr;
        }
        
    }
};
// @lc code=end

