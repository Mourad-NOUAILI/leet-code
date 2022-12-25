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

        void solve (int row, int col, int diag, int anti_diag, int n){
            if (row == n){
                ans++;
                return;
            }

            for (int cur_col = 0 ; cur_col < n ; ++cur_col){
                int cur_diag = row-cur_col+n;
                int cur_anti_diag = row+cur_col;

                if ( (col & (1 << cur_col)) != 0  || (diag & (1 << cur_diag)) != 0 || (anti_diag & (1 << cur_anti_diag)) != 0 ) continue;

                col |= (1 << cur_col);
                diag |= (1 << cur_diag);
                anti_diag |= (1 << cur_anti_diag);

                solve(row + 1, col, diag, anti_diag, n);

               
                col ^= (1 << cur_col);
                diag ^= (1 << cur_diag);
                anti_diag ^= (1 << cur_anti_diag);
            }
            return;
        }
        int totalNQueens(int n) {
            solve(0,0,0,0,n);
            return ans;
        }
        
};
// @lc code=end

