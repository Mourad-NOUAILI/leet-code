/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start

/*
    Brute force
    Time complexity: O(n^2)
    Space complexity: O(1)
*/
typedef std::vector<int> vi;

class Solution {
    public:
        vi twoSum(vi& nums, int target) {
            int n=nums.size();
           
            for(int i=0;i<n-1;++i){
                for(int j=i+1;j<n;++j){
                    if(nums[i]+nums[j]==target) return {i,j};
                }
            }
            return {};
        }
};
// @lc code=end

