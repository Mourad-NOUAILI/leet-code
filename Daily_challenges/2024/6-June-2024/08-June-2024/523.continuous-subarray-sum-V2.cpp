/*
 * @lc app=leetcode id=523 lang=cpp
 *
 * [523] Continuous Subarray Sum
 */

// @lc code=start
#include<bits/stdc++.h>

class Solution {
public:
     /*
        Time Complexity: O(n^2) => TLE
        EXtra space complexity: O(n)
    */
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();

        std::vector<int> prefix(n+1,0);
        for(int i=1;i<=n;++i) prefix[i]=prefix[i-1]+nums[i-1];

        for(int i=0;i<n-1;++i){
            for(int j=i+1;j<n;++j){
                int s=prefix[j+1]-prefix[i];
                if(s%k==0&& j-i+1>=2) return true;
            }
        }
        return false;
    }
};
// @lc code=end

