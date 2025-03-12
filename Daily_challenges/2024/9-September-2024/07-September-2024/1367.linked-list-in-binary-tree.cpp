/*
 * @lc app=leetcode id=1367 lang=cpp
 *
 * [1367] Linked List in Binary Tree
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
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
/*
    DFS (inorder)
    Time complexity: O(nm)
    Space complexity: O(n)
    n: number of nodes in binary tree
    m: number of nodes in linked list
*/
class Solution {
    public:
        bool dfs(TreeNode*& root,ListNode* head,ListNode* cur){
            if(!cur) return true;
            if(!root) return false;
            
            if(root->val==cur->val) cur=cur->next;
            else if(root->val==head->val) head=head->next;
            else cur=head;

            return dfs(root->left,head,cur) || dfs(root->right,head,cur);
            
        }

        bool isSubPath(ListNode* head, TreeNode* root) {
            return dfs(root,head,head);
        }
};
// @lc code=end

