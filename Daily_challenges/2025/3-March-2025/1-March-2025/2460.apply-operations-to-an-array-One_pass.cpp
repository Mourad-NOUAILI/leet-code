/*
 * @lc app=leetcode id=2460 lang=cpp
 *
 * [2460] Apply Operations to an Array
 */

// @lc code=start
/*
    One pass: read/write pointers (in place)
    Time complexity: O(n)
    Space complexity: O(1)
*/
class Solution {
    public:
        std::vector<int> applyOperations(std::vector<int>& nums) {
            int n=nums.size();
            int w=0;
            for(int r=0;r<n;++r){
                if(r<n-1 && nums[r]==nums[r+1]){
                    nums[r]=2*nums[r];
                    nums[r+1]=0;
                }
                if(nums[r]!=0){
                    if(r!=w) std::swap(nums[r],nums[w]);
                    w++;
                }
            }

            return nums;
        }
};
// @lc code=end

