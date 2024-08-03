/*
 * @lc app=leetcode id=2058 lang=cpp
 *
 * [2058] Find the Minimum and Maximum Number of Nodes Between Critical Points
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
    We reduce the space complexity, by computing the positions and the min_dist, max_dist 
    while traversing the SLL.

    Time complexity: O(n)
    Extra space complexity: O(1)
*/
class Solution {
public:
    std::vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        std::vector<int> ans={INT_MAX,INT_MIN};
        ListNode* cur=head;
        int prev_pos=0,first_pos=0,prev_node=cur->val,index=1,cnt=0;
        
        cur=cur->next; // Start from the next node of the head
        
        while(cur->next){ // Check if we have a next node
            int cur_node=cur->val;
            int next_node=cur->next->val;
            if(cur_node>prev_node && cur_node>next_node || cur_node<prev_node && cur_node<next_node){
                cnt++;
                if(first_pos==0){
                    first_pos=index;
                }
                else{
                    ans[0]=std::min(ans[0],index-prev_pos);
                    ans[1]=std::max(ans[1],index-first_pos);
                }
                prev_pos=index;
            }
            prev_node=cur_node;
            index++;

            cur=cur->next;
        }

        if(cnt<2) return {-1,-1};
        
        return ans;
    }
};
// @lc code=end

