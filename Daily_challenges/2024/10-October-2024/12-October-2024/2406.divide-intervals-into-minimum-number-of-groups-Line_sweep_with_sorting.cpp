/*
 * @lc app=leetcode id=2406 lang=cpp
 *
 * [2406] Divide Intervals Into Minimum Number of Groups
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Line sweep with sorting (map)
    Time complexity: O(nlogn)
    Space complexity: O(n)
*/
class Solution {
    public:
        int minGroups(std::vector<std::vector<int>>& intervals){
            std::map<int,int> dp;
            for(auto& interval: intervals){
                int left=interval[0];
                int right=interval[1];
                dp[left]++;
                dp[right+1]--;
            }

            int ans=0;
            int prefix_sum=0;
            for(auto& [k,v]: dp) {
                prefix_sum+=v;
                ans=std::max(ans,prefix_sum);
            }

            return ans;
        }
};
// @lc code=end

