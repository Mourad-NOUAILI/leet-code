/*
 * @lc app=leetcode id=2501 lang=cpp
 *
 * [2501] Longest Square Streak in an Array
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Binary search with knowledge of processed elements
    Time complexity: O(nlogn)
    Space complexity: O(n)
*/
class Solution {
public:
    int longestSquareStreak(std::vector<int>& nums) {
        int n=nums.size();
        std::sort(nums.begin(),nums.end());
        int ans=0;
        std::vector<bool> processed(100001,false);
        for(auto& e: nums){
            if(processed[e]) continue; 
            int i=std::lower_bound(nums.begin(),nums.end(),e)-nums.begin();
            int cnt=0;
            long long x=e;
            while(i<n && !processed[x] && x==nums[i]){
                processed[x]=true;
                x*=x;
                i=std::lower_bound(nums.begin(),nums.end(),x)-nums.begin();
                cnt++;
            }
            ans=std::max(ans,cnt);
        }
        return ans>1?ans:-1;
    }
};
// @lc code=end

