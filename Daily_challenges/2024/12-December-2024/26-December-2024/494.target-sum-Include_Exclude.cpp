/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */

// @lc code=start

/*
    Recursion: Include/Exclude technique
    Time complexity: O(2^n)
    Space complexity: O(n) 
*/
class Solution {
    public:
        int findTargetSumWays(std::vector<int>& nums, int target) {
            int n=nums.size();
            int ans=0;
            auto solve=[&](int i,int cur_sum,auto& self)->void{
                // If all numbers are proccessed
                if(i>=n){
                    // check if the sum is equal to target
                    if(cur_sum==target) ans++;
                    return;
                }

                // + branch
                self(i+1,cur_sum+nums[i],self);

                // - branch
                self(i+1,cur_sum-nums[i],self);
                
            };

            solve(0,0,solve);
            
            return ans;
        }
};
// @lc code=end

