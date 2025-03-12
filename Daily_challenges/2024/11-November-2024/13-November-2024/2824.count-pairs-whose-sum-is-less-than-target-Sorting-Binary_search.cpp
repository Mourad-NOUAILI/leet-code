/*
 * @lc app=leetcode id=2824 lang=cpp
 *
 * [2824] Count Pairs Whose Sum is Less than Target
 */

// @lc code=start
/*
    Sorting+Binary search
    Time complexity: O(n log n)
    Space complexity: O(1)
*/
class Solution {
    public:
        int countPairs(std::vector<int>& nums, int target){
            std::sort(nums.begin(),nums.end());
            int n=nums.size();
            int ans=0;
            for(int i=0;i<n-1;++i){
                // Find the in the range [i+1,n-1] x,
                // such that nums[i]+x<target => nums[i]+x<=target-1 => x<=target-nums[i]-1
                int j=std::upper_bound(
                    nums.begin()+i+1,
                    nums.end(),
                    target-nums[i]-1)-nums.begin()-1; // -1 to get the index of the last value of x<=target-nums[i]-1
                
                ans+= (j-i);
            }
            return ans;
        }
};
// @lc code=end

