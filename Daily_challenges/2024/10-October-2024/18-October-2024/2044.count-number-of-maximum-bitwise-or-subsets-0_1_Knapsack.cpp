/*
 * @lc app=leetcode id=2044 lang=cpp
 *
 * [2044] Count Number of Maximum Bitwise-OR Subsets
 */

// @lc code=start
#include<bits/stdc++.h>

/*
    0/1 Knapsack
    Time complexity:O(n mx)
    Spave complexity: O(n mx)
*/
class Solution {
    public:
        int countMaxOrSubsets(vector<int>& nums) {
            int n=nums.size();
            int mx=0;
            for(int e: nums) mx|=e;

            std::vector<std::vector<int>> dp(n+1,std::vector<int>(mx+1,0));

            dp[0][0]=1;

            for(int i=1;i<=n;++i){
                for(int j=0;j<=mx;++j){
                    // Exclude nums[i-1]
                    dp[i][j]+=dp[i-1][j];

                    // Include nums[i-1]
                    int or_val=j|nums[i-1];
                    if(or_val<=mx) dp[i][or_val]+=dp[i-1][j];
                }
            }
            
            return dp[n][mx];
        }
};
// @lc code=end

