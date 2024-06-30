/*
 * @lc app=leetcode id=1863 lang=cpp
 *
 * [1863] Sum of All Subset XOR Totals
 */

// @lc code=start
#include<bits/stdc++.h>

class Solution {
public:
    // Time complexity: O(n)
    // Extra space complexity: O(1) 
    int subsetXORSum(std::vector<int>& nums) {
        auto solve=[&]()->int{
            int n=nums.size();
            int s=0;
            for(auto& val: nums) s|=val;
            return s<<(n-1);
        };
        return solve();
    }
};
// @lc code=end

// [5,1,6]\n
// ==> 28

// [3,4,5,6,7,8]\n
// ==> 480


// [1,2,3,4,5,6,8,9,10,12,15,16]\n
// ==> 63488