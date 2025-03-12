/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */

// @lc code=start

/*
    DP with 2D array: Include/Exclude technique
    Time complexity: O(n.m)
    Space complexity: O(n.m) 
*/
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int s=std::accumulate(nums.begin(),nums.end(),0);

        if(abs(target)>s) return 0;
        
        int m=2*s+1;
        std::vector<std::vector<int>> dp(n,std::vector<int>(m,0));

        dp[0][s+nums[0]]=1;
        dp[0][s-nums[0]]+=1;

        for(int i=1;i<n;++i){
            for(int cur_sum=-s;cur_sum<=s;++cur_sum){
                if(cur_sum-nums[i]<-s || cur_sum+nums[i]>s) continue;
                dp[i][cur_sum+nums[i]+s]+=dp[i-1][cur_sum+s];
                dp[i][cur_sum-nums[i]+s]+=dp[i-1][cur_sum+s];
            }
        }

        return dp[n-1][target+s];
    }
};
// @lc code=end

