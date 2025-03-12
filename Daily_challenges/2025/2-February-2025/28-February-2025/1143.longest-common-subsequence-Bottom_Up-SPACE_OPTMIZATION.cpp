/*
 * @lc app=leetcode id=1143 lang=cpp
 *
 * [1143] Longest Common Subsequence
 */

// @lc code=start
/*
    Bottom Up: Space optimization
    Time complexity: O(nm)
    Space compelxity:O(2*min(n,m))
*/
class Solution {
public:
    int longestCommonSubsequence(std::string text1, std::string text2) {
        int n=text1.size(),m=text2.size();
        if(n<m){
            std::swap(n,m);
            std::swap(text1,text2);
        }
        std::vector<std::vector<int>> dp(2,std::vector<int>(m+1,0));
        auto lcs=[&]()->int{
            for(int i=n-1;i>=0;--i){
                for(int j=m-1;j>=0;--j){
                    if(text1[i]==text2[j]) dp[0][j]=1+dp[1][j+1];
                    else dp[0][j]=std::max(dp[1][j],dp[0][j+1]);
                }
                dp[1]=dp[0];
            }
          
            return dp[0][0];
        };

        return lcs();
    }
};
// @lc code=end

