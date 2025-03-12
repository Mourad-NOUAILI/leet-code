/*
 * @lc app=leetcode id=2583 lang=cpp
 *
 * [2583] Kth Largest Sum in a Binary Tree
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
    Level traversel+array sorting
    Time complexity: Ω(n+h log h), O(n+nlogn)
    Space complexity: O(n+n)=O(n)
    n: total number of nodes in the tree
    h: height of the binary tree=log_2(n)
*/
class Solution{
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        std::vector<long long> levels_sums;
        int level=0;
        auto level_traversal=[&](TreeNode* root)->void{
            if (!root) return;
            std::queue<TreeNode*> q;
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
                level++;
            }
        };

        level_traversal(root);
        
        if(k>level) return -1;

        sort(levels_sums.begin(),levels_sums.end(),std::greater<long long>());

        return levels_sums[k-1];
    }
};
// @lc code=end

