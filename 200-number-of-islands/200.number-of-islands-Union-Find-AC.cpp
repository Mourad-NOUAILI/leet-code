/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start

/*
* AC
* Time complexity: Amortized O(m*n)
* Space complexity: 3*O(m*n) + 4*O(m*n)
*/

typedef pair<int,int> Node;
class Solution {
    private:
        map<Node, int> components_size;
        map<Node,Node> parents;

    public:
        Node find(Node p){
            Node root = p;
            while(root != parents[root])
                root = parents[root];
                
            while (p != root){
                Node next = parents[p];
                parents[p] = root;
                p = next;
            }

            return root;
        }

        bool unify(Node p,Node q){
            Node root1 = find(p);
            Node root2 = find(q);

            if (root1 == root2) return false;

            if (components_size[root1] < components_size[root2]){
                components_size[root2] += components_size[root1];
                components_size[root1] = 1;
                parents[root1] = root2;
            }
            else{
                components_size[root1] += components_size[root2];
                components_size[root2] = 1;
                parents[root2] = root1;
            }
            return true;
        }

        bool is_in_the_grid(int row, int col, int m, int n){
            return (row >=0 && row < m && col >= 0 && col < n);
        }

        int numIslands(vector<vector<char>>& grid) {
            int m = grid.size();
            int n = grid[0].size();

            for (int i = 0 ; i < m ; ++i){
                for(int j = 0 ; j < n ; ++j){
                    if (grid[i][j] == '1'){
                        components_size[{i,j}] = 1;
                        parents[{i,j}] = {i,j};
                    }
                }
            }

            for (int i = 0 ; i < m ; ++i){
                for(int j = 0 ; j < n ; ++j){
                    if (grid[i][j] == '1'){
                        if (is_in_the_grid(i+1,j,m,n) && grid[i+1][j] == '1') unify({i,j},{i+1,j});
                        if (is_in_the_grid(i,j+1,m,n) && grid[i][j+1] == '1') unify({i,j},{i,j+1});
                        if (is_in_the_grid(i-1,j,m,n) && grid[i-1][j] == '1') unify({i,j},{i-1,j});
                        if (is_in_the_grid(i,j-1,m,n) && grid[i][j-1] == '1') unify({i,j},{i,j-1});
                    }
                }
            }

            int ans = 0;
            int cs = components_size.size();
            int nb = 0;
            for(auto c: components_size){
                if (c.second == cs) return 1;
                if (c.second != 1) {
                    ans++;
                    nb += c.second;
                }
            }



            return ans+cs-nb;

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