/*
 * @lc app=leetcode id=1568 lang=cpp
 *
 * [1568] Minimum Number of Days to Disconnect Island
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Brute force approach
    Time complexity: O( (nm)^2)
    Space complexity: O((nm)^2)
*/
class Solution {
    public:
        int n;
        int m;
        pair<int,int> moves[4] = {
            {-1,0},
            {1,0},
            {0,-1},
            {0,1}
        };
    public:
         bool is_in_grid(int x,int y){
            return x>=0 && x<=m-1 && y>=0 && y<=n-1;
        }

        void DFS(vector<vector<int>>& grid,std::vector<vector<bool>>& visited,int x,int y){
            if(visited[x][y]) return;
            visited[x][y]=true;
            for(int i=0;i<4;++i){
                int move_x=x+moves[i].first;
                int move_y=y+moves[i].second;
                if(!is_in_grid(move_x,move_y)) continue;
                if(grid[move_x][move_y]==0) continue;
                DFS(grid,visited,move_x,move_y);
            }
        }

        int count_islands(vector<vector<int>>& grid) {
            std::vector<vector<bool>> visited(m,std::vector<bool>(n,false));
            int cnt=0;
            for(int i=0;i<m;++i){
                for(int j=0;j<n;++j){
                    if(grid[i][j]==0 || visited[i][j]) continue;
                    cnt++;
                    DFS(grid,visited,i,j);
                }
            }
            return cnt;
        }

        int minDays(vector<vector<int>>& grid) {
            m=grid.size();
            n=grid[0].size();

            int nb_inslands=count_islands(grid);
            if(nb_inslands!=1) return 0;

            
            for(int i=0;i<m;++i){
                for(int j=0;j<n;++j){
                    if(grid[i][j]==1) {
                        grid[i][j]=0;
                        nb_inslands=count_islands(grid);
                        if(nb_inslands!=1) return 1;
                        grid[i][j]=1;
                    }
                }
            }
            return 2;
        }
};
// @lc code=end

