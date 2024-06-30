/*
 * @lc app=leetcode id=930 lang=cpp
 *
 * [930] Binary Subarrays With Sum
 */

// @lc code=start
#include<bits/stdc++.h>

class Solution {
public:
    /*
        Time complexity: O(n)
        Extra space complexity: O(1)
    */
    int numSubarraysWithSum(std::vector<int>& nums, int goal) {
        
        auto nb_subarrays_with_sum_at_least_k=[&](int k)->int{
            int n=nums.size();
            int i=0,j=0;
            int ans=0,s=0;
            while(j<n){
                s+=nums[j];
                while(i<=j&&s<k){
                    s-=nums[i];
                    i++;
                }
                ans+=j-i+1;
                j++;
            }
            return ans;
        };

        return nb_subarrays_with_sum_at_least_k(goal)-nb_subarrays_with_sum_at_least_k(goal-1);
    }
};
// @lc code=end

