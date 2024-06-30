/*
 * @lc app=leetcode id=1038 lang=cpp
 *
 * [1038] Binary Search Tree to Greater Sum Tree
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
            Morris traversal
            Time complexity: O(n)
            Extra space complexity: O(1)
        */
        TreeNode* get_post_extreme_left_node(TreeNode* node){
            TreeNode* post=node->right;
            while(post->left&&post->left!=node) post=post->left;
            return post;
        }
        TreeNode* bstToGst(TreeNode* root){
            TreeNode* node=root;
            int s=0;
            while(node){
                if(!node->right){
                    s+=node->val;
                    node->val=s;
                    node=node->left;
                }
                else{
                    TreeNode* post_extreme_left_node=get_post_extreme_left_node(node);
                    if(!post_extreme_left_node->left){
                      post_extreme_left_node->left=node;
                      node=node->right;
                    }
                    else{
                        post_extreme_left_node->left=nullptr;
                        s+=node->val;
                        node->val=s;
                        node=node->left;
                    }
                }
            }
            return root;
        }
};
// @lc code=end

