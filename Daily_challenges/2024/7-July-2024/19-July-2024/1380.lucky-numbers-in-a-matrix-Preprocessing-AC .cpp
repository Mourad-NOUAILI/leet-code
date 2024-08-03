/*
 * @lc app=leetcode id=1380 lang=cpp
 *
 * [1380] Lucky Numbers in a Matrix
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Time complexity=O(2*(m*n))
    Extra space complexity: O(m+n)
*/
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix){
        int m=matrix.size();
        int n=matrix[0].size();

        std::vector<int> min_in_row(m,INT_MAX);
        std::vector<int> max_in_col(n,INT_MIN);
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                min_in_row[i]=std::min(min_in_row[i],matrix[i][j]);
                max_in_col[j]=std::max(max_in_col[j],matrix[i][j]);
            }
        }

        std::vector<int> ans;

        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                int mi=min_in_row[i];
                int mx=max_in_col[j];
                if(mi==mx) ans.push_back(mi);

            }
        }
        return ans;
    }
};
// @lc code=end

