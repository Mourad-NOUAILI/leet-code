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
    DFS: Iterative
    Time complexity: O(n)
    Space complexity: O(n)
    n: number of nodes
*/
class Solution{
    public:
        bool check(TreeNode* node1,TreeNode* node2){
            if(!node1 || !node2) return node1==node2;
            return node1->val == node2->val;
        }
        
        bool flipEquiv(TreeNode* root1, TreeNode* root2){
            std::stack<std::pair<TreeNode*,TreeNode*>> st;
            st.push({root1,root2});

            while(!st.empty()){                             
                auto[node1,node2]=st.top();
                st.pop();

                // If both nodes are null, go the next level
                if(!node1 && !node2) continue;

                // If one of the nodes is null and the other is not null
                // means the current subtrees have not same structure
                // so the trees are not the same
                if(!node1 || !node2) return false;

                // If both nodes are not null, check their values
                // This done in the function `check(TreeNode*,TreeNode*)`
                // return `false`, if the have node the same values
                if(!check(node1,node2)) return false;
                
                // Check if the left and right children are the same, il we leave
                // the them as they are (no swap) 
                else if(check(node1->left,node2->left) && check(node1->right,node2->right)){
                    st.push({node1->left,node2->left});
                    st.push({node1->right,node2->right});
                }
                // Check if the left and right children are the same, il we swap them
                else if(check(node1->left,node2->right) && check(node1->right,node2->left)) {
                    st.push({node1->left,node2->right});
                    st.push({node1->right,node2->left});
                }
                // If they are the same in return false
                else return false;         
            }

            // If no false is returned, means:
            // Both given binary trees are equivalent, either with swap ot not
            return true;
        }
};
// @lc code=end

