/*
 * @lc app=leetcode id=2044 lang=cpp
 *
 * [2044] Count Number of Maximum Bitwise-OR Subsets
 */

// @lc code=start
#include<bits/stdc++.h>

/*
    Memoization
    Time complexity:O(n+n*mx)=O(n*mx)
    Space complexity: O(n+n*mx)
*/
class Solution{
    public:
        int countMaxOrSubsets(std::vector<int>& nums){
            int mx=0;
            for(int e: nums) mx|=e;

            int n=nums.size();
            std::vector<std::vector<int>> memo(n,std::vector<int>(mx+1,-1));
            auto solve=[&](int index,int cur,auto& self)->int{
                if(index>=n) return cur==mx?1:0;

                if(memo[index][cur]!=-1) return memo[index][cur];
                
                int exclude=self(index+1,cur,self);
                int include=self(index+1,cur|nums[index],self);
                return memo[index][cur]=include+exclude;
            };
            
            return solve(0,0,solve);
        }
};
// @lc code=end

