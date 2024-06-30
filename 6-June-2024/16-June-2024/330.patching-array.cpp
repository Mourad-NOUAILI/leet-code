/*
 * @lc app=leetcode id=330 lang=cpp
 *
 * [330] Patching Array
 */

// @lc code=start
#include<bits/stdc++.h>

class Solution {
public:
    /*
        Time complexity: O(logn + m)
        Extra space complexity: O(1)
    */
    int minPatches(vector<int>& nums, int n) {
        long long ans=0;
        long long m=nums.size();
        long long max_sum=0;
        long long i=0;
        while(max_sum<n){
            if(i<m&&max_sum+1>=nums[i]){
                max_sum+=nums[i];
                i++;
            }
            else{
                ans++;
                max_sum=2*max_sum+1;
            }
        }
        return ans;
    }
};
// @lc code=end

