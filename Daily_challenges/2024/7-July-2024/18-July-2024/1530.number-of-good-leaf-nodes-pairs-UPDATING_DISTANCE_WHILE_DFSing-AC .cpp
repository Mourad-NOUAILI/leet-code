/*
 * @lc app=leetcode id=1530 lang=cpp
 *
 * [1530] Number of Good Leaf Nodes Pairs
 */

// @lc code=start
#include<bits/stdc++.h>

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
    Updating distances while DFSing
    Time complexity: O(n*(256^2))
    Extra space complexity: O(n)
*/
class Solution {
    public:
        int ans;
    public:
        std::vector<int> dfs(TreeNode* node,int& dist){
            if(!node) return {};
            if(!node->left&&!node->right) return {1};

            std::vector<int> left=dfs(node->left,dist);
            std::vector<int> right=dfs(node->right,dist);

            for(auto& l: left){
                for(auto& r: right){
                    if(l+r<=dist) ans++;
                }
            }

            std::vector<int> parent;

            for(auto& l: left){
                if(l+1<=dist) parent.push_back(l+1); 
            }

            for(auto& r: right){
                if(r+1<=dist) parent.push_back(r+1); 
            }

            return parent;
        }

        std::unordered_map<int,int> dfs1(TreeNode* node,int& dist){
            if(!node) return {};

            std::unordered_map<int,int> m;m[1]=1;
            if(!node->left&&!node->right) return m;

            std::unordered_map<int,int> left=dfs(node->left,dist);
            std::unordered_map<int,int> right=dfs(node->right,dist);

            for(auto& [l,lf]: left){
                for(auto& [r,rf]: right){
                    if(l+r<=dist) ans+=(lf*rf);
                }
            }

            std::unordered_map<int,int> parent;

            for(auto& [l,f]: left){
                if(l+1<=dist) parent[l+1]+=f;; 
            }

            for(auto& [r,f]: right){
                if(r+1<=dist) parent[r+1]+=f; 
            }

            return parent;
        }

        int countPairs(TreeNode* root, int distance) {
            ans=0;
            dfs(root,distance);
            return ans;
        }
};
// @lc code=end

