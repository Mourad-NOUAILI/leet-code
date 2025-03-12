/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Binary search
    Time complexity: O(n log n)
    Space complexity: O(n)
*/
class Solution {
    public:
        int lengthOfLIS(vector<int>& nums) {
            int n = nums.size();
            std::vector<int> tmp;
            tmp.push_back(nums[0]);
            for(int i=1;i<n;++i){
                if(nums[i]>tmp.back()) tmp.push_back(nums[i]);
                else{
                    int j=std::lower_bound(tmp.begin(),tmp.end(),nums[i])-tmp.begin();
                    tmp[j]=nums[i];
                }
            }
            return tmp.size();
        }
};
// @lc code=end

