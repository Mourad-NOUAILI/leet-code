/*
 * @lc app=leetcode id=2044 lang=cpp
 *
 * [2044] Count Number of Maximum Bitwise-OR Subsets
 */

// @lc code=start
#include<bits/stdc++.h>

/*
    Bit manipulation
    Time complexity: O(2^n*n )
    Spave complexity: O(1)
*/
class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int mx=0;
        for(int e: nums) mx|=e;

        int n=nums.size();
        int m=1<<n;
        int ans=0;
        for(int i=0;i<m;++i){
            int x=0;
            for(int j=0;j<n;++j){
                if( (i&(1<<j))!=0 ) x|=nums[j];
            }
            if(x==mx) ans++;
        }

        return ans;
    }
};
// @lc code=end

