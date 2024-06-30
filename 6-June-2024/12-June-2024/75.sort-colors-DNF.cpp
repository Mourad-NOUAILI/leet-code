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
        Dutch National Flag algorithm
        Time complexity: O(n)
        Extra space complexity: O(1)
    */
    void sortColors(vector<int>& nums) {
        int l=0,mid=0,r=nums.size()-1;
        while(mid<=r){
            if(nums[mid]==2) {
                swap(nums[mid],nums[r]);
                r--;
            }
            else if(nums[mid]==0){
                swap(nums[mid],nums[l]);
                l++;
                mid++;
            }
            else mid++;
        }
    }
};
// @lc code=end

