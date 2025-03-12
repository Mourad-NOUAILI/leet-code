/*
 * @lc app=leetcode id=962 lang=cpp
 *
 * [962] Maximum Width Ramp
 */

// @lc code=start
#include<bits/stdc++.h>

/*
    Two pointers
    Time complexity: O(n)
    Space complexity: O(n)
*/
class Solution {
    public:
        int maxWidthRamp(std::vector<int>& nums){
            int n=nums.size();
            std::vector<int> max_suff(n);
            max_suff[n-1]=nums[n-1];
            for(int i=n-2;i>=0;--i) max_suff[i]=std::max(max_suff[i+1],nums[i]);
            
            int ans=0,i=0,j=0;
            while(i<n){
                while(j<n && nums[i]<=max_suff[j]) j++;
                ans=std::max(ans,j-i-1);
                i++;
            }
            return ans;
        }
};
// @lc code=end

