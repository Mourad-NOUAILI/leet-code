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
    // Extra space complexity: O(n)+O(n)
    std::vector<std::vector<int>> subsets(std::vector<int>& nums){
        std::vector<std::vector<int>> ans;
        std::vector<int> subset;

        auto solve=[&](int index,auto& self)->void{
            if(subset.size()>ans.size()) return;
            ans.push_back(subset);
            for(int i=index;i<nums.size();++i){
                subset.push_back(nums[i]);
                self(i+1,self);
                subset.pop_back();
            }
        };

        solve(0,solve);
        return ans;
    }
};
// @lc code=end

