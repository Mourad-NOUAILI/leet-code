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
    BFS (level traversal)
    Time complexity: O(n)
    Space complexity: O(n)
*/
class Solution {
    public:
        vector<int> largestValues(TreeNode* root) {
            std::vector<int> ans;
            auto level_traversal=[&](TreeNode* root)->void{
                if (!root) return;
                std::queue<TreeNode*> q;
                q.push(root);
                        
                while(!q.empty()){
                    int cur_subtree_size=q.size();
                    int level_mx=INT_MIN;
                    while(cur_subtree_size--){
                        TreeNode* cur_node=q.front();
                        q.pop();

                        level_mx=std::max(level_mx,cur_node->val);
                        
                        if(cur_node->left) q.push(cur_node->left);
                        if(cur_node->right) q.push(cur_node->right);
                    }
                            
                    // At each level, determine the largest value
                    ans.push_back(level_mx);
                }
            };

            level_traversal(root);

            return ans;
        }
};
// @lc code=end

