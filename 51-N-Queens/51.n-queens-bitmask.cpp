/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 */

// @lc code=start
class Solution {
    private:
            vector<vector<string>> ans;

    public:
        void solve (vector<vector<string>> board,int row, int col, int diag, int anti_diag, int n){
            if (row == n){
                vector<string> a;
                for (auto row: board){
                    string s = "";
                    for(auto e: row){
                        s += e;
                    }
                    a.push_back(s);
                }
                ans.push_back(a);
                return;
            }

            for (int cur_col = 0 ; cur_col < n ; ++cur_col){
                int cur_diag = row-cur_col+n;
                int cur_anti_diag = row+cur_col;

                // Can we put a queen at cell (row,col)
                if ( (col & (1 << cur_col)) != 0  || (diag & (1 << cur_diag)) != 0 || (anti_diag & (1 << cur_anti_diag)) != 0 ) continue;

                board[row][cur_col] = "Q";
                col |= (1 << cur_col);
                diag |= (1 << cur_diag);
                anti_diag |= (1 << cur_anti_diag);

                solve(board,row + 1, col, diag, anti_diag, n);

                board[row][cur_col] = ".";
                col ^= (1 << cur_col);
                diag ^= (1 << cur_diag);
                anti_diag ^= (1 << cur_anti_diag);
            }
            return;
        }

        vector<vector<string>> solveNQueens(int n) {
            vector<vector<string>> board(n, std::vector<std::string>(n, "."));
            solve(board,0, 0, 0, 0, n);
            return ans;
        }
};
// @lc code=end

