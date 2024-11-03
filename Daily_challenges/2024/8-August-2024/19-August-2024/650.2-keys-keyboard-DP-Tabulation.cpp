/*
 * @lc app=leetcode id=650 lang=cpp
 *
 * [650] 2 Keys Keyboard
 */

#include<bits/stdc++.h>

/*
    DP: Tabulation (bottom-up)
    Time complexity: O(n sqrt(n))
    Space complexity: O(n)
*/

typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

class Solution {
public:
    int minSteps(int n) {
        vi dp(n+1,INT_MAX);
        dp[1] = 0;
        
        for (int i=2;i<=n;++i){
            for (int j=1;j*j<=i;++j){
                if (i%j==0) {
                    dp[i] = std::min(dp[i],dp[j]+i/j);
                    if (j!=i/j) dp[i] = std::min(dp[i],dp[i/j]+j);        
                }
            }
        }
        
        return dp[n];
    }
};
// @lc code=end

