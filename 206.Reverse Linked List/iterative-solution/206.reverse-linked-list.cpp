/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
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
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head != nullptr){
            bool is_head = true;

            if(head->next == nullptr)
                return head;

            ListNode* t1 = head->next;
            ListNode* t2 = nullptr;
            
            if (t1->next != nullptr)
                t2 = t1->next;
            while (head != t1) {
                if (is_head) {
                    head->next = nullptr;
                    is_head = false;
                }

                t1->next = head;
                head = t1;
                if (t2 != nullptr) {
                    t1 = t2;
                    if (t2->next != nullptr)
                        t2 = t2->next;
                }
            }
            t1 = t2 = nullptr;
            delete t1;
            delete t2;
        }

        return head;
        
    }
};
// @lc code=end

