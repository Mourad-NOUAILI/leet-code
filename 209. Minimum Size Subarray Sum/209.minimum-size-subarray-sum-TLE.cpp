/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
       int n = nums.size();
        int INF = numeric_limits<int>::max();
        int ans = INF;
        for (int i = 0 ; i < n ; ++i){
            int s = 0;
            for(int j = i ; j < n ; ++j){
                s += nums[j];
                if (s >= target) ans = min(ans,abs(j-i)+1);
            }
        }
        return (ans != INF) ? ans : 0;
    }
};
// @lc code=end

