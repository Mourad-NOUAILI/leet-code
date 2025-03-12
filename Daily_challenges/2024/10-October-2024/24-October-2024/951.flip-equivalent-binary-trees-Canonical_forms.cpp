/*
 * @lc app=leetcode id=951 lang=cpp
 *
 * [951] Flip Equivalent Binary Trees
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
    Canonical forms
    Time complexity: O(n)
    Space complexity: O(n)
    n: number of nodes
*/
class Solution {
    public:
        void canonical_form(TreeNode*& root){
            if(!root) return;

            // DFS preorder
            canonical_form(root->left);
            canonical_form(root->right);

            // If no right child, back to parent
            if(!root->right) return;

            // If no left child
            if(!root->left){
                root->left=root->right; // right child become left child
                root->right=nullptr; // No right child
                return;
            }

            // If both of left and right child exist
            TreeNode* left=root->left;
            TreeNode* right=root->right;

            // If left child's value is greater than right child's value
            if(left->val<right->val){
                root->left=right; // parent's left child points to the parent's right child
                root->right=left; // parent's right child points to the parent's left child
            }
        }

        bool flipEquiv(TreeNode* root1, TreeNode* root2){
            canonical_form(root1);
            canonical_form(root2);
        
            if(!root1 || !root2) return root1==root2;
            if(root1->val==root2->val) 
                return flipEquiv(root1->left,root2->left) && flipEquiv(root1->right,root2->right);
            return false;
        }
};
// @lc code=end

