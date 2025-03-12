/*
 * @lc app=leetcode id=1028 lang=cpp
 *
 * [1028] Recover a Tree From Preorder Traversal
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
    Preorder: Without processing the traversal string
    Time compelxity: O(n)
    Space compelxity: O(n)
    n: #nodes
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

typedef std::vector<int> vi;
class Solution {
    public:
        TreeNode* recoverFromPreorder(std::string traversal){
            int m=traversal.size();
            int i=0;
            // Recusive function to recover array from values and depths array in prepder traversal
            auto recover_tree=[&](TreeNode*& cur_node, int cur_depth,auto& self)->void{
                if(i>=m) return ;
                
                // Extract the node depth
                int depth=0;
                while(i+depth<m && traversal[i+depth]=='-') depth++;
                
                // depth od the node!=cur_depth: The node does not belong to the current subtree rooted by cur_node.
                // This ensures that we only create nodes that belong to the expected depth.
                if(depth!=cur_depth) return;

                // Move index past the dashes
                i+=depth;

                // Extract the node value
                int value=0;
                while(i<m && traversal[i]!='-'){
                    value=value*10+(traversal[i]-'0');
                    i++;
                }

                
                cur_node=new TreeNode(value); // Create the current node

                
                // Start by creating the left subtree
                self(cur_node->left,cur_depth+1,self);
                
                // Otherwise, keep moving UP until finding the correct depth, and create the right subtree
                self(cur_node->right,cur_depth+1,self);
                
            };
            
            TreeNode* root=nullptr;
            recover_tree(root,0,recover_tree);
            return root;
        }
};
// @lc code=end

