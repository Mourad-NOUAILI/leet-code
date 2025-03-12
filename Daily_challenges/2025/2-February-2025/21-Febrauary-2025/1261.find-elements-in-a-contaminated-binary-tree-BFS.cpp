/*
 * @lc app=leetcode id=1261 lang=cpp
 *
 * [1261] Find Elements in a Contaminated Binary Tree
 */

// @lc code=start

/*
    BFS
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
class FindElements {
    private:
        std::unordered_set<int> values;
    public:
        // Time complexity: O(n)
        // Space complexity: O(3n)
        FindElements(TreeNode* root) {
            
            auto bfs=[&](TreeNode* node)->void{
                std::queue<std::pair<TreeNode*,int>> q;
                q.push({root,0});
                while(!q.empty()){
                    auto [node,node_val]=q.front();
                    q.pop();

                    node->val=node_val;

                    values.insert(node_val);

                    if(node->left) q.push({node->left,2*node_val+1});
                    
                    if(node->right) q.push({node->right,2*node_val+2});
                    
                }
            };

            bfs(root);

        }

        // Time complexity: Ω(1),O(n)
        // Space complexity: O(1)
        bool find(int target) {
            return values.find(target)!=values.end();
        }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
// @lc code=end

