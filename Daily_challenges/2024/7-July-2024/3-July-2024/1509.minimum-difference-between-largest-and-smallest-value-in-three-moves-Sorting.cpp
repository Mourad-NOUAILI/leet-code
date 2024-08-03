/*
 * @lc app=leetcode id=1509 lang=cpp
 *
 * [1509] Minimum Difference Between Largest and Smallest Value in Three Moves
 */

// @lc code=start
#include<bits/stdc++.h>

/*
    Sorting
    Time complexity: O(nlogn)
    Extra space complexity: O(log n)
*/
class Solution {
public:
    int minDifference(std::vector<int>& nums) {
        int n=nums.size();
        if(n<=4) return 0;

        std::sort(nums.begin(),nums.end());

        return std::min({nums[n-1]-nums[3],
                            nums[n-2]-nums[2],
                            nums[n-3]-nums[1],
                            nums[n-4]-nums[0]
                        });  
    }
};
// @lc code=end

