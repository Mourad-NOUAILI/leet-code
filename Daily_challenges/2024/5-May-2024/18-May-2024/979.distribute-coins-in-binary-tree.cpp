/*
 * @lc app=leetcode id=979 lang=cpp
 *
 * [979] Distribute Coins in Binary Tree
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
        std::pair<int,int> dfs(TreeNode* node){
            if(!node) return {0,0};

            auto left=dfs(node->left);
            auto right=dfs(node->right);

            int prev_moves=left.first+right.first;
            int needed_moves=abs(left.second)+abs(right.second);

            int coins=left.second+right.second+node->val-1;

            return {prev_moves+needed_moves,coins};
        }

        int distributeCoins(TreeNode* root) {
            return dfs(root).first;
        }
};
// @lc code=end 

// [1,3,0,0,0,null,null,null,null,2,null]\n
// [0,0,0,null,null,0,5]\n