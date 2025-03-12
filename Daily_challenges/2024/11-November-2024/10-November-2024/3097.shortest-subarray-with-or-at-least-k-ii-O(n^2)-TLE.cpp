/*
 * @lc app=leetcode id=3097 lang=cpp
 *
 * [3097] Shortest Subarray With OR at Least K II
 */

// @lc code=start

/*
    Naive approach-TLE
    Time complexity: O(n^2)
    Space complexity: O(1)
*/
typedef std::vector<int> vi;

class Solution {
    public:
        int minimumSubarrayLength(vi& nums, int k) {
            int n=nums.size();
            int ans=INT_MAX;
            for(int i=0;i<n;++i){
                for(int j=i;j<n;++j){
                    int s=0;
                    for(int k=i;k<=j;++k) s|=nums[k];
                    if(s>=k) ans=std::min(ans,j-i+1);
                }
            }
            return ans!=INT_MAX?ans:-1;
        }
};
// @lc code=end

