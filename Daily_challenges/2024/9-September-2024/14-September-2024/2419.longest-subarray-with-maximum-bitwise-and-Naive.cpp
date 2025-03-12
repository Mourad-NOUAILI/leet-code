/*
 * @lc app=leetcode id=2419 lang=cpp
 *
 * [2419] Longest Subarray With Maximum Bitwise AND
 */

// @lc code=start
#include<bits/stdc++.h>

/*
    Naive approach
    Time complexity: O(n^2)
    Space complexity: O(1)
*/
class Solution {
    public:
        int longestSubarray(vector<int>& nums) {
            int n=nums.size();
            int max_and=0;
            int ans=1;
            for(int i=0;i<n;++i){
                int cur_max_and=nums[i];
                for(int j=i;j<n;++j){
                    cur_max_and &= nums[j];
                    if(cur_max_and!=0){
                        if(cur_max_and>max_and){
                            max_and=cur_max_and;
                            ans=j-i+1;
                        }
                        else if(cur_max_and==max_and){
                            ans=std::max(ans,j-i+1);
                        }
                    }
                }
            }
            return ans;
        }
};

// @lc code=end

