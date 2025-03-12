/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
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
    Space compelxity: O(n)
*/
class Solution {
    public:
        int diameterOfBinaryTree(TreeNode* root) {
            
            auto dfs=[&](TreeNode* node,auto& self)->std::pair<int,int>{
                if(!node) return {0,0};
                int diameter=0;
                auto [left_diameter,max_depth_left]=self(node->left,self);
                auto [right_diameter,max_depth_right]=self(node->right,self);
                diameter=std::max({right_diameter,left_diameter,max_depth_right+max_depth_left});
                return {diameter,1+std::max(max_depth_right,max_depth_left)};
            };

            return dfs(root,dfs).first;
        }
};
// @lc code=end

