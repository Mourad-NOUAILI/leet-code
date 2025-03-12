/*
 * @lc app=leetcode id=2641 lang=cpp
 *
 * [2641] Cousins in Binary Tree II
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
    One passe BFS (level order traversal)
    Time complexity: Ω(n),O(n)
    Space complexity: Ω(n),O(n)
    n: total number of nodes in the tree
*/
class Solution{
    public:
        TreeNode* replaceValueInTree(TreeNode* root){
            if(!root) return root;
            
            std::queue<TreeNode*> q;
            q.push(root);
            int prev_level_sum=root->val;
            while(!q.empty()){
                int cur_subtree_size=q.size();
                long long cur_level_sum=0;
                while(cur_subtree_size>0){
                    TreeNode* cur_node=q.front();
                    q.pop();

                    cur_subtree_size--;

                    // Update node value to cousin sum.
                    cur_node->val=prev_level_sum-cur_node->val;

                    // Compute the sum for both the brothers
                    int brothers_sum=0;
                    if(cur_node->left) brothers_sum=cur_node->left->val;
                    if(cur_node->right) brothers_sum+=cur_node->right->val;   
                

                    if(cur_node->left){
                        cur_level_sum += cur_node->left->val; // Accumulate current level sum.
                        cur_node->left->val=brothers_sum; // Update left child's value.
                        q.push(cur_node->left);  // Add to queue for next level.
                    }

                    if(cur_node->right){
                        cur_level_sum += cur_node->right->val; // Accumulate current level sum.
                        cur_node->right->val=brothers_sum; // Update left child's value.
                        q.push(cur_node->right);  // Add to queue for next level.
                    }                        
             
                }
                
                prev_level_sum=cur_level_sum; // Update previous level for next iteration
            }

           
            return root;
        }
};
// @lc code=end

