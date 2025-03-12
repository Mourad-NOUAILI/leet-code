/*
 * @lc app=leetcode id=1671 lang=cpp
 *
 * [1671] Minimum Number of Removals to Make Mountain Array
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    LIS,LDS using recursion+memoization
    Time complexity: O(n^2)
    Space complexity: O(n)
*/
class Solution {
    public:
        int minimumMountainRemovals(std::vector<int>& nums){
            int n=nums.size();

            // LIS using Recursion+DP (Memoization)
            // Determine LIS ending at index i
            std::vector<int> memo(n,-1);
            auto LIS=[&](int i,auto& self)->int{
                if(i==0) return 1;
                if(memo[i]!=-1) return memo[i];
                int mx=1;
                for(int j=0;j<i;++j){
                    if(nums[j]<nums[i]) mx=std::max(mx,1+self(j,self));
                }        
                return memo[i]=mx;
            };

            // lis stores LIS ending at index i
            std::vector<int> lis(n,1);
            for(int i=0;i<n;++i) {
                lis[i]=LIS(i,LIS);
            }

            // lds stores LDS starting at index i
            std::reverse(nums.begin(),nums.end());
            std::vector<int> lds(n,1);
            std::fill(memo.begin(),memo.end(),-1);
            for(int i=0;i<n;++i) {
                lds[i]=LIS(i,LIS);
            }
            std::reverse(lds.begin(),lds.end());

            // Minimize the number of removals
            int ans=INT_MAX;
            for(int i=0;i<n;++i){
                if(lis[i]==1 || lds[i]==1) continue;
                ans=std::min(ans,n-lds[i]-lis[i]+1);
            }

            return ans;
        }
};
// @lc code=end

