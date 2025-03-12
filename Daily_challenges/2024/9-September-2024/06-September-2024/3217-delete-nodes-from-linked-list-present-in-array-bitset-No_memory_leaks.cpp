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
    bitset (No memeory leaks)
    Use dummy node to make a unified pattern to all nodes

    Time complexity: O(n)
    Space complexity: O(10^5)
*/
typedef std::vector<int> vi;
class Solution {
    public:
        ListNode* modifiedList(vi& nums, ListNode* head){
            std::bitset<100001> to_delete=0;
            for(auto& e: nums) to_delete[e]=1;

            ListNode* dummy=new ListNode(0,head);
            ListNode* fast=head;
            ListNode* slow=dummy;
            ListNode* to_delete_ptr=nullptr;

            while(fast){
                if(to_delete[fast->val]){
                   slow->next=fast->next;
                   to_delete_ptr=fast;
                }
                else slow=fast;
                
                fast=fast->next;
                delete to_delete_ptr;
                to_delete_ptr=nullptr;
            }

            head=fast=slow=to_delete_ptr=nullptr;

            return dummy->next;
        }
};