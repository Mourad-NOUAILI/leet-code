/*
 * @lc app=leetcode id=827 lang=cpp
 *
 * [827] Making A Large Island
 */

// @lc code=start
/*
    Preprocess all islands+DFS
    Time complexity: O(n^2)
    Space complexity: O(n^2+k)
    n: #size of the grid
    k: #number of islands
*/
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
class Solution {
    private:
        vvi directions={{0,1},{0,-1},{-1,0},{1,0}};

    public:
        void get_islands_size(vvi& grid,vi& islands_size){
            int n=grid.size();
            islands_size.resize(2,0);
            
            
            auto dfs=[&](int cur_row,int cur_col,int color,auto& self)->int{
                int visited=cur_row<0 || cur_col<0 || cur_row>n-1 || cur_col>n-1?0:grid[cur_row][cur_col];
                if(visited!=1) return 0;
    
                grid[cur_row][cur_col]=color;

                int size=1;
                for(auto& dir: directions){
                    int row=cur_row+dir[0];
                    int col=cur_col+dir[1];
                    if(row<0 || col<0 || row>n-1 || col>n-1) continue;
                    if(grid[row][col]==0) continue;
                    size+=self(row,col,color,self);
                }
                return size;
               
            };

            for(int row=0;row<n;++row){
                for(int col=0;col<n;++col){
                    if(grid[row][col]!=1) continue;
                    islands_size.push_back(dfs(row,col,islands_size.size(),dfs));
                }
            }
        }

        int largestIsland(vvi& grid) {
            int n=grid.size();

            // Phase#1:
            //Iterate over every cell in the grid to identify and mark islands using a Depth - First Search(DFS) approach.
            // During this process, each cell is visited at most once, ensuring that the DFS traversal 
            // contributes O(n^2) to the time complexity.vi islands_size;
            get_islands_size(grid,islands_size);
       
            // Phase#2: O(n^2).
            int ans=0;
            int m=islands_size.size();

            // Iterate over every cell again to explore the possibility of converting each 0 to 1 and calculating the potential island size.
            for(int row=0;row<n;++row){
                for(int col=0;col<n;++col){
                    // For each 0, we check its four neighboring cells, which is a constant-time operation.
                    if(grid[row][col]!=0) continue;

                    // The use of an unordered set ensures that neighboring islands are counted uniquely.
                    std::unordered_set<int> ne;
                    for(auto& dir: directions){
                        int r=row+dir[0];
                        int c=col+dir[1];

                        if(r<0 || c<0 || r>n-1 || c>n-1) continue;

                        ne.insert(grid[r][c]);
                    }

                    int new_size=1;
                    for(auto& v: ne){
                        new_size+=islands_size[v];
                    }

                    ans=std::max(ans,new_size);
                }
            }
            // If we have an answer (ans!=0), return it
            // Otherwise, means all the grid cells values are != 0, return the whole number of cell
            return ans?ans:n*n;
        }
};
// @lc code=end

