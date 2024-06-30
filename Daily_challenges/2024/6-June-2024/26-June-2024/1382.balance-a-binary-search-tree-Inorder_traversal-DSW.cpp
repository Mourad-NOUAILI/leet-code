/*
 * @lc app=leetcode id=1382 lang=cpp
 *
 * [1382] Balance a Binary Search Tree
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

/*struct TreeNode{
  
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode() : val(0), left(nullptr), right(nullptr){}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){}
};*/

class Solution {
    public:
     
        /*
            Overall Time complexity: O(n) 
            Extra space complexity: O(1)
        */

        /*
            Function that perform a left rotation on a particular node of the BST

            @param TreeNode* parent: parent of the node
            @param  TreeNode node: the rotation wil be based on this node

            Time complexity: O(1)
            Space complexity: O(1)
        */
        void left_rotation(TreeNode* parent,TreeNode* node){
            TreeNode* tmp=node->right;
            node->right=tmp->left;
            tmp->left=node;
            parent->right=tmp;
        }

        /*
           Function that perform a right rotation on a particular node of the BST

           @param TreeNode* parent: parent of the node
           @param  TreeNode node: the rotation wil be based on this node

           Time complexity: O(1)
           Space complexity: O(1)
       */
        void right_rotation(TreeNode* parent,TreeNode* node){
            TreeNode* tmp=node->left;
            node->left=tmp->right;
            tmp->right=node;
            parent->right=tmp;
        }

        /*
           Function to count the number of nodes on the backbone

           @param TreeNode* root: root of the backone
           @return int: the number of node on the backbone

           Time complexity: O(n)
           Space complexity: O(1)
       */
        int count_nodes(TreeNode* root){
            int n=0;
            TreeNode* current=root->right;
            while(current){
                n++;
                current=current->right;
            }
            return n;
        }

        /*
           Function that perform a given number of left rotations on the backbone

           @param TreeNode* head: the root pf the backbone
           @param  int n: the number of the desired left rotations 

           Time complexity: O(n)
           Space complexity: O(1)
       */
        void make_rotations(TreeNode* head,int n){
            TreeNode* current=head;
            for(int i=1;i<=n;++i){
                left_rotation(current,current->right);
                current=current->right;
            }
        }

        /*
           Function to make a right-heavy backbone of a BST.
           It performs right rotations

           @param TreeNode* root: the root of the BST

           Time complexity: O(n)
           Space complexity: O(1)
       */
        TreeNode* make_backbone(TreeNode* root){
            TreeNode* head=new TreeNode(0);
            head->right=root;
            TreeNode* current=head;
            while(current){
                if(current->right&&current->right->left) right_rotation(current,current->right);
                else current=current->right;
            }
            return head;
        }

        /*
           Function to convert a right-heavy backbone to most closest BBST
       
           @param TreeNode* backbone: the root of the backbone

           Time complexity: O(n+log h+ log n+ log m)=O(n)
           Space complexity: O(1)
       */
        void backbone2BBST(TreeNode* backbone){
            int n=count_nodes(backbone);
            int h=floor(log2(n+1));
            int m=pow(2,h)-1;
            TreeNode* head=backbone;
            make_rotations(head,n-m);
            while(m>1){
                m/=2;
                make_rotations(head,m);
            }
            head=nullptr;
            delete head;
        }

        TreeNode* balanceBST(TreeNode* root) {
            root=make_backbone(root);
            backbone2BBST(root);
            return root->right;
        }

        void inorder(TreeNode* root){
            if(!root) return;
            inorder(root->left);
            std::cout<<root->val<<' ';
            inorder(root->right);
        }
};
// @lc code=end




/*int main(){
    TreeNode* one=new TreeNode(1);
    TreeNode* two=new TreeNode(2);
    TreeNode* three=new TreeNode(3);
    TreeNode* four=new TreeNode(4);
    
    one->left=nullptr;
    one->right=two;

    two->left=nullptr;
    two->right=three;

    three->left=nullptr;
    three->right=four;

    four->left=nullptr;
    four->right=nullptr;

    TreeNode* root=one;

    Solution s=Solution();
    s.balanceBST(root);
    
    s.inorder(root);
    std::cout<<'\n';

    one=nullptr;
    delete one;
     
    two=nullptr;
    delete two;

    three = nullptr;
    delete three;

    four = nullptr;
    delete four;

    root = nullptr;
    delete root;

    return 0;
}*/