/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
#include<bits/stdc++.h>

class Solution {
public:
     /*
        Time complexity: O(3n)=O(n)
        Extra space complexity: O(1)
    */
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        std::vector<int> count(3,0);
        for(auto&v: nums) count[v]++;
        int k=0;
        for(int i=0;i<3;++i){
            for(int j=1;j<=count[i];++j){
                nums[k++]=i;
            }
        }
    }
};
// @lc code=end

