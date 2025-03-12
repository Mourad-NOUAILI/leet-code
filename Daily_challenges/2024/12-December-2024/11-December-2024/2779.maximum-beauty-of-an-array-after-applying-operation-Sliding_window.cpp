/*
 * @lc app=leetcode id=2779 lang=cpp
 *
 * [2779] Maximum Beauty of an Array After Applying Operation
 */

// @lc code=start
/*
    Sliding window
    Time complexity: O(n log n+n)
    Space complexity: O(logn)
*/
class Solution {
public:
    int maximumBeauty(std::vector<int>& nums, int k) {
        int n=nums.size();
        std::sort(nums.begin(),nums.end());
        int ans=0;
        int l=0;
        for(int r=0;r<n;++r){
            while(nums[r]-nums[l]>2*k) l++;
            ans=std::max(ans,r-l+1);
        }
        return ans;
    }
};
// @lc code=end

