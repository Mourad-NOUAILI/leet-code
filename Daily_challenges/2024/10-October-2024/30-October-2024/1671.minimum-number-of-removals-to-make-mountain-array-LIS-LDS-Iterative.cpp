/*
 * @lc app=leetcode id=1671 lang=cpp
 *
 * [1671] Minimum Number of Removals to Make Mountain Array
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    LIS,LDS using iterative
    Time complexity: O(n^2)
    Space complexity: O(n)
*/
class Solution {
    public:
        int minimumMountainRemovals(std::vector<int>& nums){
            // LIS using DP
            // Determine LIS ending at index i
            auto LIS=[&](std::vector<int>& A)->std::vector<int>{
                int n=A.size();
                std::vector<int> lis(n,1);
                for(int i=0;i<n;++i) {
                    for(int j=0;j<i;++j){
                        if(A[j]<A[i]) lis[i]=std::max(lis[i],1+lis[j]);
                    }
                }
                return lis;
            };

            int n=nums.size();

            // lis stores LIS ending at index i
            std::vector<int> lis=LIS(nums);

            // lds stores LDS starting at index i
            std::reverse(nums.begin(),nums.end());
            std::vector<int> lds=LIS(nums);
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

