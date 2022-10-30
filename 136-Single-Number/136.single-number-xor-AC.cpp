/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */

// @lc code=start
// Time complexity: O(n)
// Space complexity: O(1)
    class Solution {
    public:
        int singleNumber(vector<int>& nums) {
            int ans = 0;
            for(auto x: nums){
                ans ^= x;
            }
            return ans;
        }
    };
// @lc code=end

