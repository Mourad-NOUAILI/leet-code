/*
 * @lc app=leetcode id=2415 lang=cpp
 *
 * [2415] Reverse Odd Levels of Binary Tree
 */

// @lc code=start

/*
    DFS traversal
    Time complexity: O(n)
    Space complexity: O(logn)
*/
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
        TreeNode* reverseOddLevels(TreeNode* root) {
            
        
            auto dfs=[&](int level,TreeNode* left_node,TreeNode* right_node,auto& self)->void{
                if(!left_node || !right_node) return;
                if(level%2==1) std::swap(left_node->val,right_node->val);
                self(level+1,left_node->left,right_node->right,self);
                self(level+1,left_node->right,right_node->left,self);
            };
            
            dfs(1,root->left,root->right,dfs);

            return root;
        }
};
// @lc code=end

