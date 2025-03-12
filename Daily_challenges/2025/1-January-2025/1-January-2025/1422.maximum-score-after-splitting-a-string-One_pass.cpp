/*
 * @lc app=leetcode id=1422 lang=cpp
 *
 * [1422] Maximum Score After Splitting a String
 */

// @lc code=start
/*
    One pass
    Time compelxity: O(n)
    Space complexity: O(1)
*/
class Solution {
public:
    int maxScore(std::string s){
        int n=s.size();
        int zeros_in_left=0,ones_in_left=0,ans=INT_MIN;
        for(int i=0;i<n-1;++i){
            if(s[i]=='0') zeros_in_left++;
            else ones_in_left++;
            ans=std::max(ans,zeros_in_left-ones_in_left);
        }
        return ans+ones_in_left+int(s[n-1]=='1');
    }
};
// @lc code=end

