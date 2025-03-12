/*
 * @lc app=leetcode id=1749 lang=cpp
 *
 * [1749] Maximum Absolute Sum of Any Subarray
 */

// @lc code=start
/*
    Prefix sum,prefix max positive,prefix min negative
    Time complexity: O(n)
    Space complexity: o(1)
*/
class Solution {
    public:
        int maxAbsoluteSum(std::vector<int>& nums) {
            int prefix_sum=0,max_pos_sum=0, min_neg_sum=0,ans=0;
            for(auto& e: nums){
                max_pos_sum=std::max(max_pos_sum,prefix_sum);
                min_neg_sum=std::min(min_neg_sum,prefix_sum);

                prefix_sum+=e;

                ans=(prefix_sum>=0)
                    ?std::max(ans,prefix_sum-min_neg_sum)
                    :std::max(ans,max_pos_sum-prefix_sum);
            }
            
            return ans;
        }
};
// @lc code=end

