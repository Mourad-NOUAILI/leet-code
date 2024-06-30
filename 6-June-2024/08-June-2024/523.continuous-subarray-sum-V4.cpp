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
        Time Complexity: O(n+n+nlogn)=O(nlogn)
        EXtra space complexity: O(n+n)
    */
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> prefix(n,0);
        prefix[0]=nums[0];
        for(int i=1;i<n;++i) prefix[i]=prefix[i-1]+nums[i];
        for(int i=0;i<n;++i) prefix[i]%=k;
        map<int,int> mp;
        mp[0]=-1;
        for(int i=0;i<n;++i){
            if(mp.find(prefix[i])!=mp.end()){
                int id_prev=mp[prefix[i]];
                if(i-id_prev>=2) return true;
            }
            else mp[prefix[i]]=i;
        }
        return false;
    }
};
// @lc code=end

