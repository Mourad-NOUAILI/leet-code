/*
 * @lc app=leetcode id=827 lang=cpp
 *
 * [827] Making A Large Island
 */

// @lc code=start
/*
    Brute force
    Time complexity: O(n^2*n^2)=O(n^4) => TLE
    Space complexity: O(n^2+n^4) => MLE
    n: #size of the grid
*/
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
class Solution {
    public:
        int largestIsland(vvi& grid) {
            int n=grid.size();
            vvi directions={{0,1},{0,-1},{-1,0},{1,0}};

            // DFS to compute the size of the island starting from the current cell
            auto dfs=[&](int cur_row,int cur_col,vvi& visited,auto& self)->int{
                if(visited[cur_row][cur_col]) return 0;
                visited[cur_row][cur_col]=1;
                int size=1;
                for(auto& dir: directions){
                    int row=cur_row+dir[0];
                    int col=cur_col+dir[1];
                    if(row<0 || col<0 || row>n-1 || col>n-1) continue;
                    if(grid[row][col]==0) continue;
                    size+=self(row,col,visited,self);
                }
                return size;
            };

            // For each cell:
            int ans=0;
            for(int row=0;row<n;++row){
                for(int col=0;col<n;++col){

                    // Save its original value
                    int it_was=grid[row][col];

                    // Make it an insland
                    grid[row][col]=1;

                    // Explore the grid using DFS
                    vvi visited(n,vi(n,0));
                    ans=std::max(ans,dfs(row,col,visited,dfs));

                    // Restore its original value
                    grid[row][col]=it_was;
                    
                }
            }
            return ans;
        }
};
// @lc code=end

