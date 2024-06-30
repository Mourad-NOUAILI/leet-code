/*
 * @lc app=leetcode id=1863 lang=cpp
 *
 * [1863] Sum of All Subset XOR Totals
 */

// @lc code=start
#include<bits/stdc++.h>

class Solution {
public:
    // Time complexity: O(2^n)
    // Extra space complexity: O(n)
    int subsetXORSum(std::vector<int>& nums) {
        int n=nums.size();

        auto solve=[&](int index,int ans,auto& self)->int{
            if(index>=n) return ans;
            return self(index+1,(nums[index]^ans),self) + self(index+1,ans,self);
        };
        
        return solve(0,0,solve);
    }
};
// @lc code=end

// [5,1,6]\n
// ==> 28

// [3,4,5,6,7,8]\n
// ==> 480


// [1,2,3,4,5,6,8,9,10,12,15,16]\n
// ==> 63488