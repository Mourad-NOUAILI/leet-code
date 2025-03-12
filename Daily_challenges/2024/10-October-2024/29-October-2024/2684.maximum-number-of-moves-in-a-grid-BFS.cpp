/*
 * @lc app=leetcode id=2684 lang=cpp
 *
 * [2684] Maximum Number of Moves in a Grid
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    BFS
    Time complexity: O(mn)
    Space compexity:O(mn)
*/
class Solution {
    public:
        int maxMoves(std::vector<std::vector<int>>& grid){
            int m=grid.size();
            int n=grid[0].size();

            std::vector<std::vector<bool>> visited(m,std::vector<bool>(n,false));

            std::queue<std::tuple<int,int,int>> q;

            for(int row=0;row<m;++row) {
                q.push({row,0,0});
                visited[row][0]=true;
            }

            int ans=0;
            while(!q.empty()){
                auto [row,col,cnt]=q.front();
                q.pop();

                ans=std::max(ans,cnt);

                if(row-1>=0 && col+1<n && !visited[row-1][col+1] && grid[row][col]<grid[row-1][col+1]){
                    visited[row-1][col+1]=true;
                    q.push({row-1,col+1,cnt+1});
                }
                
                if(col+1<n && !visited[row][col+1] && grid[row][col]<grid[row][col+1]){
                    visited[row][col+1]=true;
                    q.push({row,col+1,cnt+1});
                }
                
                if(row+1<m && col+1<n && !visited[row+1][col+1] && grid[row][col]<grid[row+1][col+1]){
                    visited[row+1][col+1]=true;
                    q.push({row+1,col+1,cnt+1});
                }
            }

            return ans;
        }
};
// @lc code=end

