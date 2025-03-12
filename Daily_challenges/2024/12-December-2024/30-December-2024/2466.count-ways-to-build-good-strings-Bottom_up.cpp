/*
 * @lc app=leetcode id=2466 lang=cpp
 *
 * [2466] Count Ways To Build Good Strings
 */

// @lc code=start
/*
    Bottom up
    Time compelxity: O(2high)
    Space complexity: O(high)
*/
class Solution {
    public:
        int countGoodStrings(int low, int high, int zero, int one) {
            std::vector<int> dp(high+1,0);
            dp[0]=1;
            for(int h=1;h<=high;++h){
                if(h>=zero) dp[h]+=dp[h-zero];
                if(h>=one) dp[h]+=dp[h-one];
                dp[h]%=1000000007;
            }
            int ans=0;
            for(int h=low;h<=high;++h){
                ans+=dp[h];
                ans%=1000000007;
            }
            return ans;
        }
};
// @lc code=end

