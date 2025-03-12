/*
 * @lc app=leetcode id=1277 lang=cpp
 *
 * [1277] Count Square Submatrices with All Ones
 */

// @lc code=start

#include<bits/stdc++.h>
/*
    Bottom up with 2x1D array
    Time compelxity: O(m.n)
    Space compelxity: O(n)
*/
class Solution {
    public:
        int countSquares(std::vector<std::vector<int>>& matrix) {
            int m=matrix.size();
            int n=matrix[0].size();
            std::vector<int> prev_row(n+1,0);
            int ans=0;
            for(int row=1;row<=m;++row){
                std::vector<int> cur_row(n+1,0);
                for(int col=1;col<=n;++col){
                    if(matrix[row-1][col-1]==1){
                        cur_row[col]=1+std::min
                                    ({
                                        prev_row[col],
                                        prev_row[col-1],
                                        cur_row[col-1]
                                    });
                        ans+=cur_row[col];
                    }
                }
                prev_row=cur_row;
            }

            return ans;
        }
};
// @lc code=end

