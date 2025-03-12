/*
 * @lc app=leetcode id=1143 lang=cpp
 *
 * [1143] Longest Common Subsequence
 */

// @lc code=start
/*
    Bottom Up
    Time complexity: O(nm)
    Space compelxity:O(nm)
*/
class Solution {
public:
    int longestCommonSubsequence(std::string text1, std::string text2) {
        int n=text1.size(),m=text2.size();
        std::vector<std::vector<int>> dp(n+1,std::vector<int>(m+1,-1));
        auto lcs=[&]()->int{
          for(int i=0;i<=n;++i) dp[i][m]=0;
          for(int j=0;j<=m;++j) dp[n][j]=0;
          for(int i=n-1;i>=0;--i){
            for(int j=m-1;j>=0;--j){
                if(text1[i]==text2[j]) dp[i][j]=1+dp[i+1][j+1];
                else dp[i][j]=std::max(dp[i+1][j],dp[i][j+1]);
            }
          }
          return dp[0][0];
        };
        return lcs();
    }
};
// @lc code=end

