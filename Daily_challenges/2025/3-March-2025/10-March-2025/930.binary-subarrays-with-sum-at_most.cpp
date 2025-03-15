/*
 * @lc app=leetcode id=930 lang=cpp
 *
 * [930] Binary Subarrays With Sum
 */

// @lc code=start
/*
    Prefix sum+two pointers (at most(goal)-at most(goal-1))
    Time complexity: O(n)
    Space complexity: O(1)
*/
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();

        auto at_most=[&](int k)->int{
            int ans=0;
            int l=0,prefix_sum=0;
            // Expand the window from the right 
            for(int r=0;r<n;++r){
                prefix_sum+=nums[r];
                // Shrink the window while sum is greater than k
                while(l<=r && prefix_sum>k){
                    prefix_sum-=nums[l]; // Update the sum
                    l++; // Shrink the window from the left
                }

                // Compute the number of subarrays with sum at most k
                ans+=r-l+1;
            }

            return ans;
        };

        return at_most(goal)-at_most(goal-1);
    }
};
// @lc code=end

