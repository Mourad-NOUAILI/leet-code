/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */

// @lc code=start

/*
    Recursion with DP Memoization: Include/Exclude technique
    Time complexity: O(n.m)
    Space complexity: O(n.m) 
*/
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // Create nxm 2D array `memo` for momoization
        int n=nums.size();
        int s=std::accumulate(nums.begin(),nums.end(),0);
        int m=2*s+1;
        std::vector<std::vector<int>> memo(n,std::vector<int>(m,-1));

        auto solve=[&](int i,int cur_sum,auto& self)->int{
            // If all numbers are proccessed
            if(i>=n){
                // check if the sum is equal to target
                if(cur_sum==target) return 1; // 1 to add to the answer
                return 0; // otherwise, nothing to add to the answer
            }

            int ans=0;

            // If the subtree is solved twice
            if(memo[i][s+cur_sum]!=-1) return memo[i][s+cur_sum];

            // + branch
            int plus=self(i+1,cur_sum+nums[i],self);

            // - branch
            int minus=self(i+1,cur_sum-nums[i],self);
            
            // Memoize the result
            return memo[i][s+cur_sum]=plus+minus;
        };

        return solve(0,0,solve);
    }
};
// @lc code=end

