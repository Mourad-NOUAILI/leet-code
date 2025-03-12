/*
 * @lc app=leetcode id=2807 lang=cpp
 *
 * [2807] Insert Greatest Common Divisors in Linked List
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
#include<bits/stdc++.h>

/*
    Two pointers
    Time complexity: O(n)
    Space complexity: O(1)
*/
class Solution {
    public:
        ListNode* insertGreatestCommonDivisors(ListNode* head) {
            ListNode* slow=head;
            ListNode* fast=head->next;
            while(fast){
                int gcd_val=std::gcd(slow->val,fast->val);
                ListNode* gcd_node=new ListNode(gcd_val,fast);
                slow->next=gcd_node;
                slow=fast;
                fast=fast->next;
            }
            return head;
        }
};
// @lc code=end

