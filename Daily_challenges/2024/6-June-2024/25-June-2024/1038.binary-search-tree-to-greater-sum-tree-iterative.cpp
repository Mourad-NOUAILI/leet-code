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
            In order traversal
            Time complexity: O(n)
            Extra space complexity: O(n) for the recursive stack calls
        */
        TreeNode* bstToGst(TreeNode* root){
            int s=0;
            TreeNode* node=root;
            std::stack<TreeNode*> st;
            while(node||!st.empty()){
                // Go to right subtree
                while(node){
                    st.push(node);
                    node=node->right;
                }

                // Current node
                node=st.top();
                st.pop();

                s+=node->val;
                node->val=s;

                // Go to left subtree
                node=node->left;
            }

            return root;
        }
};
// @lc code=end

