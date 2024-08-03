/*
 * @lc app=leetcode id=2181 lang=cpp
 *
 * [2181] Merge Nodes in Between Zeros
 */

// @lc code=start

#include<bits/stdc++.h>

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

/*
    Creating a new simple linked list while traversing the input list
    n=#nodes in the input list
    Time complexity: O(n)
    EXtra space complexity: O(n)
*/
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
         ListNode* trav=head;

        ListNode* head1=nullptr;
        ListNode* tmp=head1;

        while(trav!=nullptr){
            int s=0;
            while(trav!=nullptr&&trav->val!=0) {
                s+=trav->val;
                trav=trav->next;
            }
            
            if(s!=0){
                if(head1==nullptr){
                    head1=new ListNode(s);
                    tmp=head1;
                }
                else {
                    ListNode* new_node=new ListNode(s);
                    tmp->next=new_node;
                    tmp=new_node;

                    new_node=nullptr;
                    delete new_node;
                }
                s=0;
            }
            trav=trav->next;
        }

        return head1;
    }
};
// @lc code=end

