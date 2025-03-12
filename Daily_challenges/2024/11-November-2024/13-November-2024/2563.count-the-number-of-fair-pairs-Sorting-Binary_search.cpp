/*
 * @lc app=leetcode id=2563 lang=cpp
 *
 * [2563] Count the Number of Fair Pairs
 */

// @lc code=start
/*
    Sorting+Binary search
    Time complexity: O(n log n)
    Space complexity: O(1)
*/
typedef long long ll;
typedef std::vector<int> vi;

class Solution {
    public:
        ll countFairPairs(vi& nums, int lower, int upper) {
            std::sort(nums.begin(),nums.end());
            int n=nums.size();
            ll ans=0;
            for(int i=0;i<n-1;++i){
                int up=std::upper_bound(nums.begin()+i+1,nums.end(),upper-nums[i])-nums.begin();
                int low=std::lower_bound(nums.begin()+i+1,nums.end(),lower-nums[i])-nums.begin();
                ans+= (up-low);
            }
            return ans;
        }
};
// @lc code=end

