/*
 * @lc app=leetcode id=1422 lang=cpp
 *
 * [1422] Maximum Score After Splitting a String
 */

// @lc code=start
/*
    Space optimization
    Time compelxity: O(2n)
    Space complexity: O(1)
*/
class Solution {
public:
    int maxScore(std::string s){
        int n=s.size();

        int ones_in_right=0;
        for(auto& c: s){
            if(c=='1') ones_in_right++;
        }

        int zeros_in_left=0,ans=0;
        for(int i=0;i<n-1;++i){
            if(s[i]=='0') zeros_in_left++;
            else ones_in_right--;
            ans=std::max(ans,zeros_in_left+ones_in_right);
        }
        return ans;
    }
};
// @lc code=end

