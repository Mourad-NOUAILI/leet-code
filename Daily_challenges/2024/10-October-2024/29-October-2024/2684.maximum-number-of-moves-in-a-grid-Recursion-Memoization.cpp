/*
 * @lc app=leetcode id=2684 lang=cpp
 *
 * [2684] Maximum Number of Moves in a Grid
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Recursion+memoization
    Time complexity: O(mn)
    Space compexity:O(mn)
*/
class Solution {
    public:
        int maxMoves(std::vector<std::vector<int>>& grid){
            int m=grid.size();
            int n=grid[0].size();

            std::vector<std::vector<int>> memo(m,std::vector<int>(n,-1));
            auto solve=[&](int row,int col,auto& self)->int{
                if(row>=m || col>=n) return 0;
                if(memo[row][col]!=-1) return memo[row][col];
                int up=0,down=0,right=0;
                if(row-1>=0 && col+1<n && grid[row][col]<grid[row-1][col+1]){
                    up=self(row-1,col+1,self);
                }
                if(col+1<n && grid[row][col]<grid[row][col+1]){
                    right=self(row,col+1,self);
                }
                if(row+1<m && col+1<n && grid[row][col]<grid[row+1][col+1]){
                    down=self(row+1,col+1,self);
                }
                return memo[row][col]=1+std::max({up,right,down});
            
            };

            int ans=0;
            for(int row=0;row<m;++row){
                ans=std::max(ans,solve(row,0,solve));
            }

            return ans-1;
        }
};
// @lc code=end

