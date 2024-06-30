/*
 * @lc app=leetcode id=945 lang=cpp
 *
 * [945] Minimum Increment to Make Array Unique
 */

// @lc code=start
#include<bits/stdc++.h>

class Solution {
public:
    /*
        Time complexity: O(nlogn)
        Extra space complexity: O(logn)
    */
    int minIncrementForUnique(std::vector<int>& nums){
        int n=nums.size();
        std::sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=1;i<n;++i){
            if(nums[i-1]>=nums[i]){
                ans+=1+nums[i-1]-nums[i];
                nums[i]=nums[i-1]+1;
            }
        }
        return ans;
    }
};
// @lc code=end

int main(){
    std::vector<int> nums={1,2,2};
    Solution s=Solution();
    std::cout<<s.minIncrementForUnique(nums)<<'\n';
}