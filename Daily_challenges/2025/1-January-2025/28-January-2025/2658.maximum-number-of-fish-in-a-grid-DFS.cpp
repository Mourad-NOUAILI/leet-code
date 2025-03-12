/*
 * @lc app=leetcode id=2658 lang=cpp
 *
 * [2658] Maximum Number of Fish in a Grid
 */

// @lc code=start
/*
    DFS
    Time complexity: O(mn)
    Space complexity: O(mn)
*/
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
class Solution {
    public:
        int findMaxFish(vvi& grid){
            int m=grid.size();
            int n=grid[0].size();

            vvi directions={{0,1},{0,-1},{-1,0},{1,0}};
            vvi visited(m,vi(n,0));

            auto dfs=[&](int row,int col,auto& self)->int{
                if(row<0 || col<0 || row>m-1 || col>n-1) return 0;
                if(visited[row][col]) return 0;
                if(grid[row][col]==0) return 0;

                visited[row][col]=1;
            
                return grid[row][col]
                    +self(row,col+1,self)
                    +self(row,col-1,self)
                    +self(row-1,col,self)
                    +self(row+1,col,self);
            };

            int ans=0;
            for(int i=0;i<m;++i){
                for(int j=0;j<n;++j){
                    if(grid[i][j]==0 || visited[i][j]) continue;
                    ans=std::max(ans,dfs(i,j,dfs));
                }
            }

            return ans;
        }
};
// @lc code=end

