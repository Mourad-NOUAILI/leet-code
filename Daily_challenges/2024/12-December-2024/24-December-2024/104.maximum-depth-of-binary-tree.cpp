/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
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
/*
    DFS
    Time complexity: O(n)
    Space complexity: O(n)
*/
class Solution {
    public:
        int maxDepth(TreeNode* root) {
            
            auto dfs=[&](TreeNode* node,auto& self)->int{
                if(!node) return 0;
                int max_left_depth=self(node->left,self);
                int max_right_depth=self(node->right,self);
                return 1+std::max(max_left_depth,max_right_depth);
            };

            return dfs(root,dfs);
        }
};
// @lc code=end

