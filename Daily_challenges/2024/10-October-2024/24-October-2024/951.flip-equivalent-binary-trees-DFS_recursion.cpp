/*
 * @lc app=leetcode id=951 lang=cpp
 *
 * [951] Flip Equivalent Binary Trees
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
    DFS: Recursion
    Time complexity: O(n)
    Space complexity: O(n)
    n: number of nodes
*/
class Solution{
    public:
        bool flipEquiv(TreeNode* root1, TreeNode* root2){
            if(!root1 || !root2) return root1==root2;
            if(root1->val==root2->val)
                return flipEquiv(root1->left,root2->left) && flipEquiv(root1->right,root2->right) // No swaped children
                    || flipEquiv(root1->left,root2->right) && flipEquiv(root1->right,root2->left); // Swapped children
                    
            return false;
        }
};
// @lc code=end

