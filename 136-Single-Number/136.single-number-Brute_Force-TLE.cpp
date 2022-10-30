/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */

// @lc code=start
// Time complexity: O(n²)
// Auxiliary space complexity: O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0 ; i < n ; ++i){
            int j = i+1;
            while (j < n && nums[i] != nums[j]) j++;
            int k = i-1;
            while (k >= 0 && nums[i] != nums[k]) k--;

            if (j == n && k == -1) return nums[i];
        }

        return -1;
    }
};
// @lc code=end

