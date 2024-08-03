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
    We reduce the space complexity, by computing the positions and the min_dist 
    while traversing the SLL.

    Time complexity: O(n)
    Extra space complexity: O(1)
*/
class Solution {
public:
    std::vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(!head || !head->next || !head->next->next) return {-1,-1};

        // Using three pointers, to be bale to check if we have a maxima or a minima
        ListNode* prev_ptr=head;
        ListNode* mid_ptr=head->next;
        ListNode* next_ptr=head->next->next;

        // Staring index
        int index=2;

        /*
            Determine the first position and the last position, to be able
            to compute the maximum distance

            The current position and the previous position help us to update
            the minimum distance
        */
        int first_pos=0,last_pos=0,cur_pos=0,prev_pos=0;

        int min_dist=std::numeric_limits<int>::max();

        int cnt=0; // To know if we have more than one position.

        // While we have a next node
        while(next_ptr){
            // If we have a maxima or a minima
            if( (mid_ptr->val>prev_ptr->val && mid_ptr->val>next_ptr->val) 
                    || 
                (mid_ptr->val<prev_ptr->val && mid_ptr->val<next_ptr->val)){
                    cnt++; // Increment the number of positions by 1
                    
                    // If we still don't have a first position
                    if(first_pos==0) first_pos=index;

                    // update the positions
                    prev_pos=cur_pos;
                    cur_pos=index;
                    last_pos=index;

                    // If we have a current position and a previous position, thrn update the minimum distance
                    if(cur_pos!=0 && prev_pos!=0) min_dist=std::min(min_dist,cur_pos-prev_pos);
            }

            // Slide all pointers to the left by one position
            prev_ptr=prev_ptr->next;
            mid_ptr=mid_ptr->next;
            next_ptr=next_ptr->next;

            index++;
        }

        if(cnt<2) return {-1,-1};

        return {min_dist,last_pos-first_pos};
    }
};
// @lc code=end

