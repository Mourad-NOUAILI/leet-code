/*
 * @lc app=leetcode id=930 lang=cpp
 *
 * [930] Binary Subarrays With Sum
 */

// @lc code=start
/*
    Prefix sum+two pointers (at least(goal)-at least(goal+1))
    Time complexity: O(n)
    Space complexity: O(1)
*/
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();

        auto at_least=[&](int k)->int{
            int ans=0;
            int l=0,prefix_sum=0;
            for(int r=0;r<n;++r){
                prefix_sum+=nums[r];
                while(l<=r && prefix_sum>=k){
                    // Compute the number of subarrays with sum at least k
                    ans+=n-r;
                    prefix_sum-=nums[l];
                    l++;
                }
            }
            return ans;
        };

        return at_least(goal)-at_least(goal+1);
    }
};
// @lc code=end

