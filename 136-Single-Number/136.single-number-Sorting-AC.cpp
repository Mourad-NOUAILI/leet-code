/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */

// @lc code=start
// Time complexity: O(n log n) + O(n)
// Auxiliary space complexity: O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int i = 0;
        while (i < n-1 && nums[i] == nums[i+1]) i += 2;
        if (i <= n-1) return nums[i];
        return -1;
    }
};
// @lc code=end

