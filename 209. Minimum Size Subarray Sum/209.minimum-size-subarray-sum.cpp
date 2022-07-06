/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int INF = numeric_limits<int>::max();
        int ans = INF;
        int n = nums.size();
        vector<long long> PS(n + 1, 0);
        for (int i = 1; i < n + 1; ++i)
            PS[i] = PS[i - 1] + nums[i - 1];
        deque<int> DQ;
        for (int i = 0 ; i <= n ; ++i){
            while (!DQ.empty() && PS[i]-PS[DQ.front()] >= target){
                ans = min(ans, i - DQ.front());
                DQ.pop_front();
            }
            DQ.push_back(i);
        }
        return (ans != INF) ? ans : 0;
    }
};
// @lc code=end

