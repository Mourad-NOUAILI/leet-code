/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
    // o(n log n)
    vector<int> twoSum(vector<int>& nums, int target) {
        map<long, long> m;
        vector<int> ans;
        for (int i = 0 ; i < nums.size() ; ++i) {
            long r = target - nums[i];
            if (m.size() == 0) {
                m.insert({r, i});
            }
            else {
                if ( m.find(nums[i]) != m.end() ) {
                    ans.push_back(m[nums[i]]);
                    ans.push_back(i);
                    return ans;
                }
                else {
                    m.insert({r, i});
                }
            }
        }
        return ans;
        
    }
};
// @lc code=end

