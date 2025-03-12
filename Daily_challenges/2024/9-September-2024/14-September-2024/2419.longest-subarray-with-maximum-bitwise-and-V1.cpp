/*
 * @lc app=leetcode id=2419 lang=cpp
 *
 * [2419] Longest Subarray With Maximum Bitwise AND
 */

// @lc code=start
#include<bits/stdc++.h>

/*
    Modified Kadane's algorithm-version 1
    Time complexity: O(n+n)=O(n)
    Space complexity: O(1)
*/
class Solution {
    public:
        int longestSubarray(std::vector<int>& nums) {
            int n=nums.size();
            int mx=*std::max_element(nums.begin(),nums.end());
            int tmp_ans=0,ans=0;
            for(auto& e: nums){
                if(e==mx) tmp_ans++;
                else tmp_ans=0;
                ans=std::max(ans,tmp_ans);
            }
            return ans;
        }
};

// @lc code=end

