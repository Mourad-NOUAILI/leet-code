/*
 * @lc app=leetcode id=1975 lang=cpp
 *
 * [1975] Maximum Matrix Sum
 */

// @lc code=start
/*
    Pattern recognition
    Time compelxity: O(n^2)
    Space complexity: O(1)
*/
class Solution {
public:
    long long maxMatrixSum(std::vector<std::vector<int>>& matrix){
        int n=matrix.size();

        long long ans=0;
        int count_neg=0; // Count negative numbers
        int min_abs_val=INT_MAX; // Determine the min absolute value
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                int e=matrix[i][j];
                count_neg+=int(e<0);
                ans+=std::abs(e);
                min_abs_val=std::min(min_abs_val,abs(e));
            }
        } 
        return count_neg%2?ans-2*min_abs_val:ans;
    }
};
// @lc code=end

