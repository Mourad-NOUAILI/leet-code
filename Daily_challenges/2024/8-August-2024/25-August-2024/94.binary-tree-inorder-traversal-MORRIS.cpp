/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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
    Morris
    Time complexity: O(n)
    Space complexity: O(1)
    n: #nodes in the binary tree
*/

typedef std::vector<int> vi;

class Solution {
    public:
        vi inorderTraversal(TreeNode* root) {
            vi ans;
            TreeNode* cur=root;
            while(cur){
                TreeNode* ptr=cur->left;
                if(!ptr){
                    ans.push_back(cur->val);
                    cur=cur->right;
                }
                else{
                    while(ptr->right) ptr=ptr->right;
                    ptr->right=cur;
                    TreeNode* temp=cur;
                    cur=cur->left;
                    temp->left=nullptr;
                }
            }
            return ans;
        }
};
// @lc code=end

