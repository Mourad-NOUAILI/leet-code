/*
 * @lc app=leetcode id=2419 lang=cpp
 *
 * [2419] Longest Subarray With Maximum Bitwise AND
 */

// @lc code=start
#include<bits/stdc++.h>

/*
    Modified Kadane's algorithm-version 2
    Time complexity: O(n)=O(n)
    Space complexity: O(1)
*/
class Solution {
    public:
        int longestSubarray(vector<int>& nums) {
            int n=nums.size();
            int cur_max_and=0,tmp_ans=0,ans=0;
            for(auto& e: nums){
                if(e>cur_max_and){
                    cur_max_and=e;
                    tmp_ans=1;
                    ans=0;

                }
                else if(e==cur_max_and) tmp_ans+=1;
                else {
                    tmp_ans=0;
                }
                ans=std::max(ans,tmp_ans);
            }
            return ans;
        }
};
// @lc code=end

