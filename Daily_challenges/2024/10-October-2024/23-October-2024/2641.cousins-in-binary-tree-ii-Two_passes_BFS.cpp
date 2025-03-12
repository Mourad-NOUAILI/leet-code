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
    Two passes BFS (level order traversal)
    Time complexity: Ω(n),O(n)
    Space complexity: Ω(n+h),O(n+n)
    n: total number of nodes in the tree
    h: height of the binary tree=log_2(n)
*/
class Solution{
    public:
        TreeNode* replaceValueInTree(TreeNode* root){
            if(!root) return root;
            
            std::queue<TreeNode*> q;
            std::vector<long long> levels_sums;

            q.push(root);
            while(!q.empty()){
                int cur_subtree_size=q.size();
                long long s=0;
                while(cur_subtree_size>0){
                    TreeNode* cur_node=q.front();
                    q.pop();

                    cur_subtree_size--;

                    s+=cur_node->val;                  

                    if(cur_node->left) q.push(cur_node->left);                   
                    if(cur_node->right) q.push(cur_node->right);
                }
                
                levels_sums.push_back(s);
            }

            q.push(root);
            int level=1; // start by level 1
            root->val=0; // root node have no cousins, its value become 0
            while(!q.empty()){
                int cur_subtree_size=q.size();
                while(cur_subtree_size>0){
                    TreeNode* cur_node=q.front();
                    q.pop();

                    cur_subtree_size--;

                    // Compute the sum for both the brothers
                    int brothers_sum=0;
                    if(cur_node->left) brothers_sum=cur_node->left->val;
                    if(cur_node->right) brothers_sum+=cur_node->right->val;               
                    
                    if(cur_node->left) cur_node->left->val=levels_sums[level]-brothers_sum,q.push(cur_node->left);                   
                    if(cur_node->right) cur_node->right->val=levels_sums[level]-brothers_sum,q.push(cur_node->right);
                }
                
                level++;
            }

           
            return root;
        }
};
// @lc code=end

