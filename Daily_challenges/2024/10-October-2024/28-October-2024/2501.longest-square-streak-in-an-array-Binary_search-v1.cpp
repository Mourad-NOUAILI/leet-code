/*
 * @lc app=leetcode id=2501 lang=cpp
 *
 * [2501] Longest Square Streak in an Array
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Binary search without knowledge of processed elements
    Time complexity: O(nlogn)
    Space complexity: O(1)
*/
class Solution {
public:
    int longestSquareStreak(std::vector<int>& nums) {
        int n=nums.size();
        std::sort(nums.begin(),nums.end());
        int ans=0;
        for(auto& e: nums){
            int i=std::lower_bound(nums.begin(),nums.end(),e)-nums.begin();
            int cnt=0;
            long long x=e;
            while(i<n && x==nums[i]){
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

