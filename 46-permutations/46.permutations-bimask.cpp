/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
#include<bits/stdc++.h>

class Solution {
    public:
        vector<vector<int>> ans;

    public:
        void all_permutations(vector<int>& nums, int mask, vector<int>& tmp){
            int n=nums.size();
            if (tmp.size() == n){
                ans.push_back(tmp);
                return;
            }
            for(int i = 0 ; i < n ; ++i) {
                if (mask&(1<<i)) continue;
                tmp.push_back(nums[i]);
                all_permutations(nums,mask|(1<<i),tmp);
                tmp.pop_back();
            }
        }
        vector<vector<int>> permute(vector<int>& nums) {
            vector<int> tmp;
            all_permutations(nums,0,tmp);
            return ans;
        }
};
// @lc code=end

