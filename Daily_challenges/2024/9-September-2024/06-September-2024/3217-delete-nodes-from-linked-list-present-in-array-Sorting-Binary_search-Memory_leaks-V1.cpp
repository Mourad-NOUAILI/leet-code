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
    Sorting+Binary search (Memory leaks)
    if head... else...
    
    Time complexity: O(nlogn)
    Space complexity: O(logn)
*/
typedef std::vector<int> vi;

class Solution {
    public:
        ListNode* modifiedList(vi& nums, ListNode* head){
            std::sort(nums.begin(),nums.end());

            ListNode* fast=head;
            ListNode* slow=head;
            while(fast){
                if(std::binary_search(nums.begin(),nums.end(),fast->val)){
                    if(fast==head) {
                        head=head->next;
                        fast=slow=head;
                    }
                    else{
                        slow->next=fast->next;
                        fast=fast->next;
                    }
                }
                else{
                    slow=fast;
                    fast=fast->next;
                }
            }
            return head;
        }
};