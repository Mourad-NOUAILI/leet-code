/*
 * @lc app=leetcode id=2684 lang=cpp
 *
 * [2684] Maximum Number of Moves in a Grid
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Bottom up with 2D array
    Time complexity: O(mn)
    Space compexity:O(mn)
*/
class Solution {
    public:
        int maxMoves(std::vector<std::vector<int>>& grid){
            int m=grid.size();
            int n=grid[0].size();

            std::vector<std::vector<int>> dp(m,std::vector<int>(n,0));

            for(int row=0;row<m;++row) dp[row][0]=1;

            int ans=0;

            for(int col=1;col<n;++col){
                for(int row=0;row<m;++row){
                    if(row-1>=0 && grid[row][col]>grid[row-1][col-1] && dp[row-1][col-1]>0)
                        dp[row][col]=std::max(dp[row][col],dp[row-1][col-1]+1);
                    if(grid[row][col]>grid[row][col-1] && dp[row][col-1]>0)
                        dp[row][col]=std::max(dp[row][col],dp[row][col-1]+1);
                    if(row+1<m && grid[row][col]>grid[row+1][col-1] && dp[row+1][col-1]>0)
                        dp[row][col]=std::max(dp[row][col],dp[row+1][col-1]+1);

                    ans=std::max(ans,dp[row][col]-1);
                }
            }

            return ans;
        }
};
// @lc code=end

