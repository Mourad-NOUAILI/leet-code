/*
 * @lc app=leetcode id=515 lang=cpp
 *
 * [515] Find Largest Value in Each Tree Row
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
    Recursive DFS
    Time complexity: O(n)
    Space complexity: O(n)
*/
class Solution {
    public:
        vector<int> largestValues(TreeNode* root) {
            std::vector<int> ans;
            auto dfs=[&](TreeNode* node,int depth,auto& self)->void{
                if (!node) return;
                if(depth==ans.size()) ans.push_back(node->val);
                else ans[depth]=std::max(ans[depth],node->val);
                self(node->left,depth+1,self);
                self(node->right,depth+1,self);
            };

            dfs(root,0,dfs);

            return ans;
        }
};
// @lc code=end

