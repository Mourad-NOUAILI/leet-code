/*
 * @lc app=leetcode id=1072 lang=cpp
 *
 * [1072] Flip Columns For Maximum Number of Equal Rows
 */

// @lc code=start
/*
    Hash map
    Time compelxity: O(m*n+m)
    Space complexity: O(n)
*/
class Solution {
public:
    int maxEqualRowsAfterFlips(std::vector<std::vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();

        std::unordered_map<std::string,int> count;
        
        for(auto& cur_row: matrix){
            std::string s="";
            for(int i=1;i<n;++i) s+=((cur_row[0]-'0')^(cur_row[i]-'0'))+'0';
            count[s]++;
        }
        int ans=0;
        for(auto& [s,cnt]: count) ans=std::max(ans,cnt);
        return ans;
    }
};
// @lc code=end

