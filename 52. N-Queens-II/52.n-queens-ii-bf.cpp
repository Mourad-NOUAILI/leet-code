#include <bits/stdc++.h>
/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
 */

// @lc code=start
class Solution {
    private:
        int ans = 0;

    public:
         bool we_can_put_a_queen_in_column(int row, int col, int n,std::vector<std::vector<std::string>> board){
                // Check if a queen exists in same column
                // No need to check below the row
                for (int i = 0 ; i < row ; ++i)
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
                    ans++;
                    return;
                }

                for (int cur_col = 0 ; cur_col < n ; ++cur_col){

                    if (!we_can_put_a_queen_in_column(row, cur_col, n, board)) continue;

                    board[row][cur_col] = "Q";

                    solve(board,row + 1, cur_col, n);

                    board[row][cur_col] = ".";
                }
                return;
            }

            int totalNQueens(int n) {
                std::vector<std::vector<std::string>> board(n, std::vector<std::string>(n, "."));
                solve(board,0,0,n);
                return ans;
            }
};
// @lc code=end

