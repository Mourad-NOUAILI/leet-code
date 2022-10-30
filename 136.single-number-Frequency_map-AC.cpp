/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */

// @lc code=start
// Time complexity: O(n)
// Auxiliary space complexity: O(n)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> f;
        for(auto x: nums){
            f[x]++;
        }
        for (auto x: f){
            if (x.second == 1) return x.first;
        }
        return -1;
    }
};
// @lc code=end

