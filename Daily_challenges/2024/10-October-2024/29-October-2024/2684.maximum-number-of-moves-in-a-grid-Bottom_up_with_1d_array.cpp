/*
 * @lc app=leetcode id=2684 lang=cpp
 *
 * [2684] Maximum Number of Moves in a Grid
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Bottom up with 1D array
    Time complexity: O(mn)
    Space compexity:O(m)
*/
class Solution {
    public:
        int maxMoves(std::vector<std::vector<int>>& grid){
            int m=grid.size();
            int n=grid[0].size();

            std::vector<int> prev_col(m,1);
            
            int ans=0;

            for(int col=1;col<n;++col){
                std::vector<int> cur_col(m,0);
                for(int row=0;row<m;++row){
                    if(row-1>=0 && grid[row][col]>grid[row-1][col-1] && prev_col[row-1]>0)
                        cur_col[row]=std::max(cur_col[row],prev_col[row-1]+1);
                    if(grid[row][col]>grid[row][col-1] && prev_col[row]>0)
                        cur_col[row]=std::max(cur_col[row],prev_col[row]+1);
                    if(row+1<m && grid[row][col]>grid[row+1][col-1] && prev_col[row+1]>0)
                        cur_col[row]=std::max(cur_col[row],prev_col[row+1]+1);

                    ans=std::max(ans,cur_col[row]-1);
                }

                prev_col=cur_col;
                
            }

            return ans;
        }
};
// @lc code=end

