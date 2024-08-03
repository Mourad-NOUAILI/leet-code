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
    Traverse the SLL and get all positions of all maximas and minimas in an array.
    max_dist=position[m-1]-position[0], where m is the size of the array
    Perform the sliding window technique on the array to compute min_dist.

    Time complexity: O(n)
    Extra space complexity: O(n)
*/
class Solution {
public:
    std::vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(!head || !head->next || !head->next->next) return {-1,-1};

        ListNode* prev_ptr=head;
        ListNode* mid_ptr=head->next;
        ListNode* next_ptr=head->next->next;
        int index=2;
        std::vector<int> position;
        while(next_ptr){
            if( (mid_ptr->val>prev_ptr->val && mid_ptr->val>next_ptr->val) 
                    || 
                (mid_ptr->val<prev_ptr->val && mid_ptr->val<next_ptr->val)){
                    position.push_back(index);
            }

            prev_ptr=prev_ptr->next;
            mid_ptr=mid_ptr->next;
            next_ptr=next_ptr->next;

            index++;
        }
        
        int m=position.size();
        
        if(m<2) return {-1,-1};

        int max_dist=position[m-1]-position[0];

        int min_dist=std::numeric_limits<int>::max();
        int i=0,j=1; // Window of size 2
        // Updating the min_dist, while sliding the window to the left
        while(j<m){
            min_dist=std::min(min_dist,position[j]-position[i]);
            i++;
            j++;
        }

        return {min_dist,max_dist};
    }
};
// @lc code=end

