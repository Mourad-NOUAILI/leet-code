/*
 * @lc app=leetcode id=1382 lang=cpp
 *
 * [1382] Balance a Binary Search Tree
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

class Solution {
public:
    /*
        Time complexity: O(n+n)=O(n)
        Extra space complexity: O(n): recursion, O(n): inorder_array
    */
    TreeNode* balanceBST(TreeNode* root) {
        
        auto inorder=[&](TreeNode*& root,std::vector<int>& inorder_array,auto& self)->void{
            if(!root) return;
            self(root->left,inorder_array,self);
            inorder_array.push_back(root->val);
            self(root->right,inorder_array,self);
        };

        std::vector<int> inorder_array;
        inorder(root,inorder_array,inorder);

        auto balance_bst=[&](int left,int right,auto& self)->TreeNode*{
            if(left>right) return nullptr;
            int mid=(left+right)>>1;
            TreeNode* tree=new TreeNode(inorder_array[mid]);
            tree->left=self(left,mid-1,self);
            tree->right=self(mid+1,right,self);
            return tree;
        };

        int n=inorder_array.size();
        return balance_bst(0,n-1,balance_bst);
    }
};
// @lc code=end

