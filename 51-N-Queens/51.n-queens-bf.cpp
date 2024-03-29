#include <bits/stdc++.h>
/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 */

// @lc code=start
class Solution {
    private:
        std::vector<std::vector<std::string>> ans;

    public:
        bool can_we_put_a_queen_in_column(int row, int col, int n,std::vector<std::vector<std::string>> board){
            // Check if a queen exists in same column
            for (int i = 0 ; i < n ; ++i)
                if (board[i][col] == "Q") return false;

            // Check if a queen exists in the diagonal of the given cell
            // No need to check the bottom side of the diagonal
            for(int i = row , j = col ; i >= 0 && j >= 0 ; --i,--j)
                if (board[i][j] == "Q") return false;

            // Chech if a queen exists in the anti-diagonal
            // No need to check the bottom side of the diagonal
            for(int i = row , j = col ; i >=0 && j < n ; --i,++j)
                if (board[i][j] == "Q") return false;
            
            return true;
        }

       void solve (std::vector<std::vector<std::string>> board, int row, int col, int n){
            if (row == n){
                std::vector<std::string> a;
                for (auto row: board){
                    std::string s = "";
                    for(auto e: row){
                        s += e;
                    }
                    a.push_back(s);
                }
                ans.push_back(a);
                return;
            }

            for (int cur_col = 0 ; cur_col < n ; ++cur_col){

                if (!can_we_put_a_queen_in_column(row,cur_col,n,board)) continue;       

                board[row][cur_col] = "Q";

                solve(board,row+1,cur_col,n);

                board[row][cur_col] = ".";
                
            }
            return;

        }

        std::vector<std::vector<std::string>> solveNQueens(int n) {
            std::vector<std::vector<std::string>> board(n, std::vector<std::string>(n, "."));
            solve(board,0, 0, n);
            return ans;
        }
};
// @lc code=end

