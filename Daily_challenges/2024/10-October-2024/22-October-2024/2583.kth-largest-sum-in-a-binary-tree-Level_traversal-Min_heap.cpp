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
    Level traversel+Min heap
    Time complexity: O(n+log n log k)
    Space complexity:O(n)
*/
class Solution{
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        std::priority_queue<long long,std::vector<long long>,std::greater<long long>> min_heap;

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
                min_heap.push(s);
                if(min_heap.size()>k) min_heap.pop();
            }
        };

        level_traversal(root);
        
        if(k>min_heap.size()) return -1;

        return min_heap.top();
    }
};
// @lc code=end

