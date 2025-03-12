/*
 * @lc app=leetcode id=1590 lang=cpp
 *
 * [1590] Make Sum Divisible by P
 */

// @lc code=start
#include<bits/stdc++.h>

/*
    Brute force
    Time complexity: O(n+n^2) = O(n^2)
    Space complexity: O(1)
*/
class Solution{
    public:
        int minSubarray(vector<int>& nums, int p){
            int n=nums.size();
            int r=0;
            for(auto& e: nums) r=(r+e)%p;

            if(r==0) return 0;

            int ans=INT_MAX;
            for(int i=0;i<n;++i){
                long long sum=0;
                for(int j=i;j<n;++j){
                    sum+=nums[j];
                    if((sum-r)%p==0) ans=std::min(ans,j-i+1);
                }
            }
            if(ans==n) return -1;
            return ans==INT_MAX?-1:ans;
        }
};
// @lc code=end

