/*
 * @lc app=leetcode id=1380 lang=cpp
 *
 * [1380] Lucky Numbers in a Matrix
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Time complexity=O(m*n*(m+n))
    Extra space complexity: O(1)
*/
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix){
        int m=matrix.size();
        int n=matrix[0].size();

        std::vector<int> ans;

        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                int v=matrix[i][j];

                int mi=INT_MAX;
                for(int k=0;k<n;++k){
                    if(mi>matrix[i][k]) mi=matrix[i][k];
                }
                
                int mx=INT_MIN;
                for(int k=0;k<m;++k){
                    if(mx<matrix[k][j]) mx=matrix[k][j];
                }

                if(v==mi&&v==mx) ans.push_back(v);
            }
        }
        return ans;
    }
};
// @lc code=end

