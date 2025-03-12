/*
 * @lc app=leetcode id=1800 lang=cpp
 *
 * [1800] Maximum Ascending Subarray Sum
 */

// @lc code=start

/*
    Signle pass, single pointer
    Time complexity: O(n)
    Space complexity: O(1)
*/

typedef std::vector<int> vi;

class Solution {
    public:
        int maxAscendingSum(vi& nums) {
            int n=nums.size();
            int sum=nums[0],ans=0;
            for(int i=0;i<n-1;++i){
                if(nums[i]>=nums[i+1]){
                    ans=std::max(ans,sum);
                    sum=0;
                }
                sum+=nums[i+1];
            }
            return std::max(ans,sum);
        }
};
// @lc code=end

