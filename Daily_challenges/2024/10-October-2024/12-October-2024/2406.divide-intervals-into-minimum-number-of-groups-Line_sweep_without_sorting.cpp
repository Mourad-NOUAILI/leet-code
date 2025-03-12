/*
 * @lc app=leetcode id=2406 lang=cpp
 *
 * [2406] Divide Intervals Into Minimum Number of Groups
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Line sweep without sorting (vector)
    Time complexity: O(n+(max_right-min_left+1))
    Space complexity: O(max_right+2)=O(max_right)
*/
class Solution {
    public:
        int minGroups(std::vector<std::vector<int>>& intervals){
            int min_left=INT_MAX;
            int max_right=INT_MIN;
            for(auto& interval: intervals){
                min_left=std::min(min_left,interval[0]);
                max_right=std::max(max_right,interval[1]);
            }

            std::vector<int> dp(max_right+2,0);
            
            for(auto& interval: intervals){
                int left=interval[0];
                int right=interval[1];
                dp[left]++;
                dp[right+1]--;
            }

            int ans=0;
            int tmp_ans=0;
            for(auto& v: dp) {
                tmp_ans+=v;
                ans=std::max(ans,tmp_ans);
            }

            return ans!=0?ans:1;
        }
};
// @lc code=end

