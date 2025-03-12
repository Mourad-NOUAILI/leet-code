/*
 * @lc app=leetcode id=1277 lang=cpp
 *
 * [1277] Count Square Submatrices with All Ones
 */

// @lc code=start

#include<bits/stdc++.h>
/*
    Recursion+Memoization
    Time compelxity: O(m.n)
    Space compelxity: O(m.n)
*/
class Solution {
    public:
        int countSquares(std::vector<std::vector<int>>& matrix) {
            int m=matrix.size();
            int n=matrix[0].size();
            std::vector<std::vector<int>> memo(m,std::vector<int>(n,-1));
            auto solve=[&](int row,int col,auto& self)->int{
                if(row==m || col==n || matrix[row][col]==0) return 0;
                if(memo[row][col]!=-1) return memo[row][col];
                return memo[row][col]=1+std::min
                                                ({
                                                    self(row+1,col,self),
                                                    self(row,col+1,self),
                                                    self(row+1,col+1,self),
                                                });
            };

            int ans=0;
            for(int i=0;i<m;++i){
                for(int j=0;j<n;++j){
                    ans+=solve(i,j,solve);
                }
            }
            return ans;
        }
};
// @lc code=end

