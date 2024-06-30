/*
 * @lc app=leetcode id=1438 lang=cpp
 *
 * [1438] Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit
 */

// @lc code=start
#include<bits/stdc++.h>

class Solution {
public:
    /*
        --Brute Force: TLE (See code below)
        Time complexity: O(n^3)
        Extra space complexity: O(1)

        we can preprocess the computation of max and min
        using:

        --DP, matrix min,max for all ranges:
        Time complexity: O(n^2) + O(n^2)
        Extra space complexity: O(2*n^2))

        --square root decomposition:
        Time complexity: O(n^2 * sqrt(n)) + O(n)
        Extra space complexity: O(2*sqrt(n))

        --sparse table:
        Time complexity: O(n^2) + O(n log n)
        Extra space complexity: O(n)+O(n)

        -- using min heap,max heap:
        Time complexity: O(n^2) + O(n log n)
        Extra space complexity: O(n)+O(n)

    */
    int longestSubarray(std::vector<int>& nums, int limit) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;++i){
            for(int j=i;j<n;++j){
                int mx=-1;
                int mi=std::numeric_limits<int>::max();
                for(int k=i;k<=j;++k){
                    mx=std::max(mx,nums[k]);
                    mi=std::min(mi,nums[k]);
                }
                if(mx-mi<=limit) ans=std::max(ans,j-i+1);
            }
        }
        return ans;
    }
};
// @lc code=end

/*
    [10,1,2,4,7,2]\n5\n

    [4,2,2,2,4,4,2,2]\n0\n

    [1,2,5]\n10\n

*/