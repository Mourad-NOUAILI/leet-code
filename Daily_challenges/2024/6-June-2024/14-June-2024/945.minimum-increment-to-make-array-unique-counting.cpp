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
        Time complexity: O(n+max)
        Extra space complexity: O(n+max)
    */
    int minIncrementForUnique(std::vector<int>& nums){
        int n=nums.size();
        int mx=*std::max_element(nums.begin(),nums.end());
        int m=mx+n+1;
        std::vector<int> count(m,0);
        for(auto& v: nums) count[v]++;
        int i=0,j=0;
        int ans=0;
        while(j<m){
            if(count[i]>=2&&count[j]==0&&j>=i){
                ans+=(j-i);
                count[i]--;
                count[j]=1;
            }
            if(count[i]<=1) i++;
            if(count[j]!=0||j<i) j++;
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