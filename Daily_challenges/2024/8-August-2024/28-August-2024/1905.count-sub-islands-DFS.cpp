/*
 * @lc app=leetcode id=1905 lang=cpp
 *
 * [1905] Count Sub Islands
 */

// @lc code=start
#include<bits/stdc++.h>

/*
    DFS
    Time complexity:
        nested for loops: O(mn)
        DFS: O(V+E)=O(mn+V)
        Overall: O(mn*(mn+V))
        If all cells are 1:
        nested for loops: O(1)
        DFS: O(V+E)=O(mn+V)
        Overall: O(mn+V)=O(mn)
    Space complexity: 
        Recurion stack calls: O(mn)
*/
typedef std::pair<int,int> ii;
typedef std::vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
class Solution {
    public:
        vii moves={
            {-1,0}, // Up
            {1,0}, // Down
            {0,1}, // Right
            {0,-1} // Left
        };
        
        int m; // Number of rows
        int n; // Number of columns
     
    public:
        bool is_in_grid(int x,int y){
            return x>=0 && x<=m-1 && y>=0 && y<=n-1;
        }

        bool dfs(int i, int j,vvi& grid1, vvi& grid2){
            if(!is_in_grid(i,j) || grid2[i][j]==0) return true;
          
            grid2[i][j]=0; // Mark cell as visited

            bool is_sub_island=grid1[i][j]==1;
            
            for(auto& move: moves){
                int x=i+move.first;
                int y=j+move.second;
                is_sub_island = dfs(x,y,grid1,grid2) && is_sub_island ;
            }
            return is_sub_island;
        }

        int countSubIslands(vvi& grid1, vvi& grid2) {
            m=grid1.size();
            n=grid1[0].size();

            int ans=0;
            for(int i=0;i<m;++i){
                for(int j=0;j<n;++j){
                    if(grid1[i][j]==0 || grid2[i][j]==0) continue;
                    ans+=dfs(i,j,grid1,grid2);
                }
            }
            return ans;
        }
};
// @lc code=end

