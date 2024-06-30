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
        Time complexity: O(n log n)
        Extra space complexity: O(n)
    */
    int numSubarraysWithSum(std::vector<int>& nums, int goal) {
        std::map<int,int> freq;
        freq[0]=1;
        int ans=0;
        int pre=0;
        for(auto& e: nums){
                pre+=e;
                ans+=freq[pre-goal];
                freq[pre]++;
        }

        return ans;
    }
};
// @lc code=end

