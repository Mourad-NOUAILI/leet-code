/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
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
    Morris: adapted to post traversal
    Time complexity: O(n)
    Space complexity: O(1)
    n: #nodes in the binary tree 
*/

typedef std::vector<int> vi;
class Solution {
    public:
        vi postorderTraversal(TreeNode* root) {
            vector<int>ans;
            TreeNode* dummy = new TreeNode();
            dummy->left=root;

            TreeNode* cur=dummy;
            
            while(cur){
                TreeNode* ptr=cur->left;
                if(ptr){
                    while(ptr->right && ptr->right!=cur) ptr = ptr->right;

                    if(!ptr->right){
                        ptr->right=cur;
                        cur=cur->left;
                    }
                    else{
                        ptr->right=nullptr;
                        ptr=cur->left;
                        
                        int m=ans.size();

                        while(ptr){
                            ans.push_back(ptr->val);
                            ptr=ptr->right;
                        }

                        reverse(ans.begin()+m, ans.end());

                        cur=cur->right;
                    }
                }
                else cur = cur->right;
            }

            delete dummy;
            dummy = nullptr;
            
            return ans;
        }
};
// @lc code=end

