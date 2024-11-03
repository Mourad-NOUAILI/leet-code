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
    Morris: adapted to post traversal
    Time complexity: O(n)
    Space complexity: O(1)
    n: #nodes in the binary tree 
*/

typedef std::vector<int> vi;
class Solution {
    public:
        vi postorderTraversal(TreeNode* root) {
           vi ans;
            TreeNode* cur=root;
            while (cur) {
                TreeNode* ptr = cur->right;
                if (!ptr) {
                    ans.push_back(cur->val);
                    cur=cur->left;
                }
                else {
                    while (ptr->left && ptr->left!=cur) ptr=ptr->left;
                    
                    if (!ptr->left) {
                        ans.push_back(cur->val);
                        ptr->left = cur;
                        cur=cur->right;
                    }
                    else {
                        ptr->left = NULL;
                        cur=cur->left;
                    }
                }
            }

            reverse(ans.begin(), ans.end());
            return ans;
        }
};
// @lc code=end

