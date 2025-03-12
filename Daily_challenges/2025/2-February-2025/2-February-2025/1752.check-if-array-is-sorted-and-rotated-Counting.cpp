/*
 * @lc app=leetcode id=1752 lang=cpp
 *
 * [1752] Check if Array Is Sorted and Rotated
 */

// @lc code=start

/*
    Counting bad pairs
    Time complexity: O(n)
    Space complexity: O(1)
*/
class Solution {
    public:
        bool check(std::vector<int>& nums) {
            int n=nums.size();
            int count=0;
            for(int i=0;i<n-1;++i){
                if(nums[i+1]<nums[i]) count++;
            }
            count+=nums[0]<nums[n-1];
            return count<2;
        }
};
// @lc code=end

