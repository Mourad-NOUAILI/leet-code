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
    Inplace
    n=#nodes in the input list
    Time complexity: O(n)
    EXtra space complexity: O(1)
*/
class Solution {
public:
    ListNode* mergeNodes(ListNode* head){
        ListNode* modify=head->next; 
        ListNode* sum=modify;

        while (sum != nullptr) {
            int s=0;
            while (sum->val != 0){
                s+=sum->val;
                sum=sum->next;
            }

            modify->val=s;
            modify->next=sum->next;
            modify=sum->next;

            sum=sum->next;
        }
        return head->next;
    }
};
// @lc code=end

