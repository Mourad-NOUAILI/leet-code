/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
#include<bits/stdc++.h>

class Solution {
public:
    // Time complexity: O(2^n * n)
    // Extra space complexity: O(n)
    std::vector<std::vector<int>> subsets(std::vector<int>& nums){
        auto solve=[&]()->std::vector<std::vector<int>>{
            std::vector<std::vector<int>> ans;
            int n=nums.size();
            int m=1<<n;
            for(int i=0;i<m;++i){
                std::vector<int> subset;
                for(int j=0;j<n;++j){
                    if((i&(1<<j))!=0) subset.push_back(nums[j]);
                }
                ans.push_back(subset);
            }
            return ans;
        };

        return solve();
    }
};
// @lc code=end

