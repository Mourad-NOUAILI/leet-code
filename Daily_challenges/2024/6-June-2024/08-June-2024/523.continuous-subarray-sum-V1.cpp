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
        Time Complexity: O(n^3) =>  TLE
        EXtra space complexity: O(1)
    */
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=0;i<n-1;++i){
            for(int j=i+1;j<n;++j){
                int s=0;
                for(int r=i;r<=j;++r){
                    s+=nums[r];
                }
                if(s%k==0&& j-i+1>=2) return true;
            }
        }
        return false;
    }
};
// @lc code=end

