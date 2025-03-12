/*
 * @lc app=leetcode id=1261 lang=cpp
 *
 * [1261] Find Elements in a Contaminated Binary Tree
 */

// @lc code=start

/*
    DFS
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
        // Space complexity: O(2n)
        FindElements(TreeNode* root) {
            
            auto dfs=[&](TreeNode* node,int val,auto& self)->void{
                if(!node) return;
                node->val=val;
                values.insert(val);
                self(node->left,2*node->val+1,self);
                self(node->right,2*node->val+2,self);
            };

            dfs(root,0,dfs);

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

