/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int s = 0 , i = 0 , j = 0;
        int n = nums.size();
        int INF = numeric_limits<int>::max();
        int ans = INF;
        while (j < n){
            s += nums[j];
            if (s >= target){
                while (s >= target){
                    ans = min(ans,j-i+1);
                    s -= nums[i++];
                }
            }
            j++;
        }
        return (ans != INF)?ans:0;*
    }
};
// @lc code=end

