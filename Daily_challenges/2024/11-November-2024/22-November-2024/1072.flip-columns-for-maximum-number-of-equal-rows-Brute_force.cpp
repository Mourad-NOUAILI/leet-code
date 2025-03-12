/*
 * @lc app=leetcode id=1072 lang=cpp
 *
 * [1072] Flip Columns For Maximum Number of Equal Rows
 */

// @lc code=start
/*
    Brute Force
    Time compelxity: O(m*(n+m))=O(m.n+m^2)
    Space complexity: O(n)
*/
class Solution {
public:
    int maxEqualRowsAfterFlips(std::vector<std::vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
      
        int ans=0;
        for(auto& cur_row: matrix){
            std::vector<int> flipped_row(n);
            for(int i=0;i<n;++i) flipped_row[i]=1-cur_row[i];
            int count_identical_rows=0;
            for(auto& compare_row: matrix){
                if(cur_row==compare_row || flipped_row==compare_row) count_identical_rows++;
            }
            ans=std::max(ans,count_identical_rows);
        }
        return ans;
    }
};
// @lc code=end

