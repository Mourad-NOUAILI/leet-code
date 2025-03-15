/*
 * @lc app=leetcode id=2460 lang=cpp
 *
 * [2460] Apply Operations to an Array
 */

// @lc code=start
/*
    Two passes: Simulation+fill answer
    Time complexity: O(n)
    Space complexity: O(n)
*/
class Solution {
public:
    std::vector<int> applyOperations(std::vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n-1;++i){
            if(nums[i]==nums[i+1]){
                nums[i]=2*nums[i];
                nums[i+1]=0;
            }
        }

        std::vector<int> ans(n);
        int l=0,r=n-1;
        for(int i=0;i<n;++i){
            if(nums[i]==0) ans[r--]=0;
            else ans[l++]=nums[i];
        }
        return ans;
    }
};
// @lc code=end

