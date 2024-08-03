/*
 * @lc app=leetcode id=1605 lang=cpp
 *
 * [1605] Find Valid Matrix Given Row and Column Sums
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Time complexity: O(n*m)
    Extra space complexity: O(1)
*/
class Solution {
public:
    std::vector<std::vector<int>> restoreMatrix(std::vector<int>& rowSum, std::vector<int>& colSum) {
        int n=rowSum.size();
        int m=colSum.size();

        std::vector<std::vector<int>> ans(n,std::vector<int>(m,0));

        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                ans[i][j]=std::min(rowSum[i],colSum[j]);
                rowSum[i]-=ans[i][j];
                colSum[j]-=ans[i][j];
            }
        }
        
        return ans;
    }
};
// @lc code=end

