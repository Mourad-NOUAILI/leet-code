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
            int sum=nums[0]; // Prefix sum initial value
            int ans=nums[0]; // Array could be of size 1
            // Iterate over all elements
            for(int i=0;i<n-1;++i){
                // If previous element is greater than the next one
                if(nums[i]<nums[i+1]){
                    // Cumulate the sum
                    sum+=nums[i+1];
                }
                // Otherwise, reset the sum the the value that breaks the condition
                else sum=nums[i+1];

                // Maximize the sum
                ans=std::max(ans,sum);
            }
            return ans;
        }
};
// @lc code=end

