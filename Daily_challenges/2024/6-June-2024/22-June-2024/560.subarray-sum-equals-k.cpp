/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 */

// @lc code=start
#include<bits/stdc++.h>

class Solution {
public:
    /*
        Time complexity: O(n log n)
        Extra space complexity: O(n)
    */
    int subarraySum(std::vector<int>& nums, int k){
        std::map<int,int> freq;
        freq[0]=1; // Because prefix start with 0
        int pre=0,ans=0;
        for(auto& e: nums){
            pre+=e; // prefix[j+1]
            ans+=freq[pre-k]; // for each prefix[j+1], check if prefix[i] is already computed
            freq[pre]++; // Update the frequency of the current prefix
        }
        return ans;
    }
};
// @lc code=end

// [1,1,1]\n2\n --> 2 passed
// [1,2,3]\n3\n --> 2 passed
//[1]\n0\n      -->0 passed

/*

[5,6,0,1,3,4,1]\n4\n
==>3

*/