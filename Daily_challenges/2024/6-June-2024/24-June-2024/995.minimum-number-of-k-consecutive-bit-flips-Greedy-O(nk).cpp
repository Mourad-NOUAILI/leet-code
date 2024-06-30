/*
 * @lc app=leetcode id=995 lang=cpp
 *
 * [995] Minimum Number of K Consecutive Bit Flips
 */

// @lc code=start
#include<bits/stdc++.h>

class Solution {
public:
    /*
        Greedy approach: TLE
        Time complexity: O(nk)
        Extra space complexity: O(1)
    */
    int minKBitFlips(std::vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;++i){
            if(nums[i]==0){
                if(i+k-1>=n) return -1;
                for(int j=i;j<i+k;++j) nums[j]=!nums[j];
                ans++;
            }
        }
        return ans;
    }
};
// @lc code=end

