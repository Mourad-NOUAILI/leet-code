/*
 * @lc app=leetcode id=1509 lang=cpp
 *
 * [1509] Minimum Difference Between Largest and Smallest Value in Three Moves
 */

// @lc code=start
#include<bits/stdc++.h>

/*
    Brute force: sorting+sliding window
    Time complexity: O(nlogn)
    Extra space complexity: O(log n)
*/
class Solution {
public:
    int minDifference(std::vector<int>& nums) {
        int n=nums.size();
        if(n<=4) return 0;

        std::sort(nums.begin(),nums.end());

        // Window of size n-3
        int i=0;
        int j=n-4;

        int ans=std::numeric_limits<int>::max();
        while(j<n){
            ans=std::min(ans,nums[j]-nums[i]);
            i++;
            j++;
        }

        return ans;  
    }
};
// @lc code=end

