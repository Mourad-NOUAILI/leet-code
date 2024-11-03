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
    Iterative DFS
    Time complexity: O(n)
    Space complexity: O(n)
    n: #nodes in the binary tree 
*/
typedef std::vector<int> vi;
class Solution {
    public:
        vi postorderTraversal(TreeNode* root) {
            if(!root) return {};
            vi ans;
            std::stack<TreeNode*> st;
            st.push(root);
            while(!st.empty()){
                auto cur_node=st.top();
                st.pop();
                ans.push_back(cur_node->val);
                if(cur_node->left) st.push(cur_node->left);
                if(cur_node->right) st.push(cur_node->right);
            }
            reverse(ans.begin(),ans.end());
            return ans;
        }
};
// @lc code=end

