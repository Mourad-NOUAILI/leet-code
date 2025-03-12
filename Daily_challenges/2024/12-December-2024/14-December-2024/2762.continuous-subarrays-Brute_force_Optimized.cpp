/*
 * @lc app=leetcode id=2762 lang=cpp
 *
 * [2762] Continuous Subarrays
 */

// @lc code=start


/*
    Brute force optimized
    Time complexity: O(n^2)
    Space complexity: O(1)
*/

class Solution {
    public:
        long long continuousSubarrays(std::vector<int>& nums){
            int n=nums.size();
            long long ans=0;
            for(int l=0;l<n;++l){
                int mi=nums[l];
                int mx=nums[l];
                for(int r=l;r<n;++r){
                    if(mi>nums[r]) mi=nums[r];
                    if(mx<nums[r]) mx=nums[r];
                    if(mx-mi<=2) ans++;
                }
            }
            return ans;
        }
};

// @lc code=end

