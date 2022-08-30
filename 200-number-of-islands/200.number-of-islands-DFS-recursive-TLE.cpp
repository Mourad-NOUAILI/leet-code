/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start

/*
* TLE
* Time complexity: O(2^(m+n) * m*n)
* Space complexity: O(m*n)
*/

typedef pair<int,int> Node;
class Solution {
    private:
        map<Node, bool> visited;
        vector<Node> neighbors{{1,0},{-1,0},{0,1},{0,-1}};

    public:
        bool is_in_the_grid(int row, int col, int m, int n){
            return (row >=0 && row < m && col >= 0 && col < n);
        }

        void dfs(Node node, vector<vector<char>> grid, int m, int n){
            visited[node] = true;
            for(auto neighbor: neighbors){
                int i = node.first + neighbor.first;
                int j = node.second + neighbor.second;
                if (is_in_the_grid(i,j,m,n) && !visited[{i,j}] && grid[i][j] == '1') dfs({i,j},grid,m,n);
            } 
        }

        int numIslands(vector<vector<char>>& grid) {
            int m = grid.size();
            int n = grid[0].size();
            int ans = 0;
            for (int i = 0 ; i < m ; ++i){
                for(int j = 0 ; j < n ; ++j){
                    if (grid[i][j] == '1' && !visited[{i,j}]){
                        ans++;
                        dfs({i,j},grid,m,n);
                    }
                }
            }
            return ans;
        }
};
// @lc code=end

/*
[["1","1","0","0","0"],["1","1","0","0","0"],["0","0","1","0","0"],["0","0","0","1","1"]]\n
[["0","0","0","0","0"],["0","0","0","0","0"],["0","0","0","0","0"],["0","0","0","0","0"]]\n
[["0","1","0","0","0"],["0","1","0","0","0"],["0","1","0","0","0"],["0","1","0","0","0"]]\n
[["1","0","0","0","0"],["0","1","0","0","0"],["0","0","1","0","0"],["0","0","0","1","0"],["0","0","0","0","1"]]\n

[["1","0","1","1","1"],["1","0","1","0","1"],["1","1","1","0","1"]]\n

[["1","1","1","1","1","0","1","1","1","1"],["1","0","1","0","1","1","1","1","1","1"],["0","1","1","1","0","1","1","1","1","1"],["1","1","0","1","1","0","0","0","0","1"],["1","0","1","0","1","0","0","1","0","1"],["1","0","0","1","1","1","0","1","0","0"],["0","0","1","0","0","1","1","1","1","0"],["1","0","1","1","1","0","0","1","1","1"],["1","1","1","1","1","1","1","1","0","1"],["1","0","1","1","1","1","1","1","1","0"]]\n

*/