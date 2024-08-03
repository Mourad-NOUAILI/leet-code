/*
 * @lc app=leetcode id=1380 lang=cpp
 *
 * [1380] Lucky Numbers in a Matrix
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Time complexity=O(m*(n+m)))
    Extra space complexity: O(1)
*/
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix){
        int m=matrix.size();
        int n=matrix[0].size();

        for(int i=0;i<m;++i){
            int mi=INT_MAX,col_min_index=-1;
            for(int j=0;j<n;++j){
                if(mi>matrix[i][j]){
                    mi=matrix[i][j];
                    col_min_index=j;
                }
            }

            int mx=INT_MIN,row_max_index=-1;
            for(int j=0;j<m;++j){
                if(mx<matrix[j][col_min_index]){
                    mx=matrix[j][col_min_index];
                    row_max_index=j;
                }
            }

            if(i==row_max_index) return {matrix[i][col_min_index]};
        }

        return {};
    }
};
// @lc code=end

