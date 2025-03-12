/*
 * @lc app=leetcode id=1277 lang=cpp
 *
 * [1277] Count Square Submatrices with All Ones
 */

// @lc code=start

#include<bits/stdc++.h>
/*
    Bottom up without extra space
    Time compelxity: O(m.n)
    Space compelxity: O(1)
*/
class Solution {
    public:
        int countSquares(std::vector<std::vector<int>>& matrix) {
            int m=matrix.size();
            int n=matrix[0].size();

            int ans=std::count(matrix[0].begin(),matrix[0].end(),1);
            for(int row=1;row<m;++row) ans+=matrix[row][0];
            
            for(int row=1;row<m;++row){
                for(int col=1;col<n;++col){
                    if(matrix[row][col]==1){
                        matrix[row][col]=1+std::min
                                    ({
                                        matrix[row-1][col],
                                        matrix[row-1][col-1],
                                        matrix[row][col-1]
                                    });
                        ans+=matrix[row][col];
                    }
                }
            }

            return ans;
        }
};
// @lc code=end

