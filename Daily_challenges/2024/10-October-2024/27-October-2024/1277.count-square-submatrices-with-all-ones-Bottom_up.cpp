/*
 * @lc app=leetcode id=1277 lang=cpp
 *
 * [1277] Count Square Submatrices with All Ones
 */

// @lc code=start

#include<bits/stdc++.h>
/*
    Bottom up with 2D array
    Time compelxity: O(m.n)
    Space compelxity: O(m.n)
*/
class Solution {
    public:
        int countSquares(std::vector<std::vector<int>>& matrix) {
            int m=matrix.size();
            int n=matrix[0].size();
            std::vector<std::vector<int>> dp(m+1,std::vector<int>(n+1,0));
            int ans=0;
            for(int row=1;row<=m;++row){
                for(int col=1;col<=n;++col){
                    if(matrix[row-1][col-1]){
                        dp[row][col]=1+std::min
                                                ({
                                                    dp[row-1][col],
                                                    dp[row][col-1],
                                                    dp[row-1][col-1]
                                                });
                        ans+=dp[row][col];
                    }
                }
            }

            return ans;
        }
};
// @lc code=end

