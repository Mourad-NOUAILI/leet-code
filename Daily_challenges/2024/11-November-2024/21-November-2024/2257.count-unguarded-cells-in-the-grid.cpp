/*
 * @lc app=leetcode id=2257 lang=cpp
 *
 * [2257] Count Unguarded Cells in the Grid
 */

// @lc code=start

/*
    Straight forward Simualation
    Time compelxity: O(g+w+min(g(m+n),4.m.n)+m.n)
    Space complexity: O(m.n)
*/
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
class Solution {
    public:
        int countUnguarded(int m, int n, vvi& guards, vvi& walls){
            vvi grid(m,vi(n,0));

            // Fill the grid as describe in guards and walls
            for(auto& g: guards){
                grid[g[0]][g[1]]=1;
            }

            for(auto& w: walls){
                grid[w[0]][w[1]]=-1;
            }

            // For each guard
            for(auto& g: guards){
                int i=g[0];
                int j=g[1];

                // see west
                int k=j-1;
                while(k>=0 && grid[i][k]!=1 && grid[i][k]!=-1) grid[i][k]=2,k--;

                // see east
                k=j+1;
                while(k<n && grid[i][k]!=1 && grid[i][k]!=-1) grid[i][k]=3,k++;

                // see north
                k=i-1;
                while(k>=0 && grid[k][j]!=1 && grid[k][j]!=-1) grid[k][j]=4,k--;

                // see south
                k=i+1;
                while(k<m && grid[k][j]!=1 && grid[k][j]!=-1) grid[k][j]=5,k++;
                    
            }

            // Count not guarded cells (with value equal to 0)
            int ans=0;
            for(int i=0;i<m;++i){
                for(int j=0;j<n;++j){
                    ans+=int(grid[i][j]==0);
                }
            }

            return ans;
        }
};
// @lc code=end

