/*
 * @lc app=leetcode id=1863 lang=cpp
 *
 * [1863] Sum of All Subset XOR Totals
 */

// @lc code=start
#include<bits/stdc++.h>

class Solution {
public:
    // Time complexity: O(2^n n)
    // Extra space complexity: O(1) 
    int subsetXORSum(std::vector<int>& nums){
        auto solve=[&]()->int{
            int n=nums.size();
            int m=1<<n;
            int ans=0;
            for(int i=0;i<m;++i){
                int x=0;
                for(int j=0;j<n;++j){
                    if( (i&(1<<j))!=0 ) x^=nums[j];
                }
                ans+=x;
            }
            return ans;
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