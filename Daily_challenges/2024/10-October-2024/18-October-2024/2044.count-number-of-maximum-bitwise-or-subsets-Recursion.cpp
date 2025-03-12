/*
 * @lc app=leetcode id=2044 lang=cpp
 *
 * [2044] Count Number of Maximum Bitwise-OR Subsets
 */

// @lc code=start
#include<bits/stdc++.h>

// https://artofproblemsolving.com/wiki/index.php/Principle_of_Inclusion-Exclusion

/*
    Recursion
    Time complexity:O(n+2^n)=O(2^n)
    Spave complexity: O(n)
*/
class Solution {
    public:
        int countMaxOrSubsets(vector<int>& nums) {
            int n=nums.size();
            int mx=0;
            for(int e: nums) mx|=e;

            auto solve=[&](int index,int cur,auto& self)->int{
                if(index>=n) return cur==mx?1:0;
                
                int exclude=self(index+1,cur,self);
                int include=self(index+1,cur|nums[index],self);
                return include+exclude;
            };
            
            return solve(0,0,solve);
        }
};
// @lc code=end

