/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
#include<bits/stdc++.h>

class Solution {
public:
    // Time complexity: O(2^n)
    // Extra space complexity: O(n)+O(n)
    std::vector<std::vector<int>> subsets(std::vector<int>& nums){
        std::vector<std::vector<int>> ans;
        int n=nums.size();
        
        auto solve=[&](int index,std::vector<int> subset,auto& self)->void{
            if(index>=n) {
                ans.push_back(subset);
                return;
            }
            subset.push_back(nums[index]);
            self(index+1,subset,self);
            subset.pop_back();
            self(index+1,subset,self);
        };

        std::vector<int> subset;
        solve(0,subset,solve);
        return ans;
    }
};
// @lc code=end

