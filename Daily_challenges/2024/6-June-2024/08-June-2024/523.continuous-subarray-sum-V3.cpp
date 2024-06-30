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
        Time Complexity: O(n+n+n)=o(n)
        EXtra space complexity: O(n+k) ==> MLE
        
    */
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> prefix(n,0);
        prefix[0]=nums[0];
        for(int i=1;i<n;++i) prefix[i]=prefix[i-1]+nums[i];
        for(int i=0;i<n;++i) prefix[i]%=k;
        
        vector<int> mp(k,-1);
        for(int i=0;i<n;++i){
            if(mp[prefix[i]]!=-1){
                int prev_index=mp[prefix[i]];
                if(i-prev_index>=2) return true;
            }
            else mp[prefix[i]]=i;
        }
        return false;
    }
};
// @lc code=end

