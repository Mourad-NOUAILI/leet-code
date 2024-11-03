/*
 * @lc app=leetcode id=1140 lang=cpp
 *
 * [1140] Stone Game II
 */

// @lc code=start
#include<bits/stdc++.h>

/*
    DP: Tabulation
    Time complexity: O(n*M^2)
    Space complexity: O(n^2)

*/
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef std::vector<vvi> vvvi;
class Solution {
    public:
        int stoneGameII(std::vector<int>& piles) {
        int n = piles.size();
        vvi dp(n+1,vi(n+1,0));
        
        vi suffix_sum(n+1,0);

        for (int i=n-1;i>=0;--i) {
            suffix_sum[i]=suffix_sum[i+1]+piles[i];
        }
        
        for (int i=n-1;i>=0;--i) {
            for (int M=1;M<=n;++M) {
                for (int X=1;X<=std::min(2*M,n-i);++X) {
                    dp[i][M] =std::max(dp[i][M],suffix_sum[i]-dp[i+X][std::max(M,X)]);
                }
            }
        }

        return dp[0][1];
        }
};
// @lc code=end

