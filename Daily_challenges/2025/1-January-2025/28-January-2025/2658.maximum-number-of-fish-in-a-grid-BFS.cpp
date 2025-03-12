/*
 * @lc app=leetcode id=2658 lang=cpp
 *
 * [2658] Maximum Number of Fish in a Grid
 */

// @lc code=start
/*
    BFS
    Time complexity: O(mn)
    Space complexity: O(mn)
*/
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef std::pair<int,int> ii;
class Solution {
    public:
        int findMaxFish(vvi& grid){
            int m=grid.size();
            int n=grid[0].size();

            vvi directions={{0,1},{0,-1},{-1,0},{1,0}};
            vvi visited(m,vi(n,0));

            auto bfs=[&](int row,int col)->int{
                int fishes=0;
                std::queue<ii> q;
                q.push({row,col});
                visited[row][col]=1;
                while(!q.empty()){
                    auto [cur_row,cur_col]=q.front();
                    q.pop();
                    fishes+=grid[cur_row][cur_col];
                    for(auto& dir: directions){
                        int r=cur_row+dir[0];
                        int c=cur_col+dir[1];
                        if(r<0 || c<0 || r>m-1 || c>n-1) continue;
                        if(grid[r][c]==0) continue;
                        if(visited[r][c]) continue;
                        visited[r][c]=1;
                        q.push({r,c});
                    }
                }
                return fishes;
            };

            int ans=0;
            for(int i=0;i<m;++i){
                for(int j=0;j<n;++j){
                    if(grid[i][j]==0 || visited[i][j]) continue;
                    ans=std::max(ans,bfs(i,j));
                }
            }

            return ans;
        }
};

// @lc code=end

