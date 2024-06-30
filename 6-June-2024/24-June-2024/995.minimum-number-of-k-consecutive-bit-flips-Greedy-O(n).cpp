/*
 * @lc app=leetcode id=995 lang=cpp
 *
 * [995] Minimum Number of K Consecutive Bit Flips
 */

// @lc code=start
#include<bits/stdc++.h>

class Solution {
public:
    /*
        Greedy approach: AC
        Time complexity: O(n)
        Extra space complexity: O(n)
    */
    int minKBitFlips(std::vector<int>& nums, int k) {
        int n=nums.size();
        std::vector<int> is_flipped(n,0);
        int ans=0,cnt_flips=0;
        for(int i=0;i<n;++i){
            if(i>=k) cnt_flips-=is_flipped[i-k];
            if(nums[i]^(cnt_flips%2)==0){
                if(i+k-1>=n) return -1;
                ans++;
                cnt_flips++;
                is_flipped[i]=1;
            }
        }
        return ans;
    }
};
// @lc code=end

