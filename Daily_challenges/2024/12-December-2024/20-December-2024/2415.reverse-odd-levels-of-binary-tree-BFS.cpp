/*
 * @lc app=leetcode id=2415 lang=cpp
 *
 * [2415] Reverse Odd Levels of Binary Tree
 */

// @lc code=start

/*
    BFS traversal(level traversal)
    Time complexity: O(n)
    Space complexity: O(n)
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
            
            int level=0;
            auto level_traversal=[&](TreeNode* root)->void{
                if (!root) return;
                std::queue<TreeNode*> q;
                q.push(root);
                
                while(!q.empty()){
                    int cur_subtree_size=q.size();
                    std::vector<TreeNode*> level_nodes;
                    while(cur_subtree_size--){
                        TreeNode* cur_node=q.front();
                        q.pop();

                        level_nodes.push_back(cur_node);
                
                        if(cur_node->left) q.push(cur_node->left);
                        if(cur_node->right) q.push(cur_node->right);
                    }
                    
                    if(level%2){
                        int i=0,j=level_nodes.size()-1;
                        while(i<j){
                            std::swap(level_nodes[i]->val,level_nodes[j]->val);
                            i++;
                            j--;
                        }
                    }
                    level++;
                }
            };

            level_traversal(root);

            return root;
        }
};
// @lc code=end

