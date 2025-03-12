/*
 * @lc app=leetcode id=1590 lang=cpp
 *
 * [1590] Make Sum Divisible by P
 */

// @lc code=start
#include<bits/stdc++.h>

/*
    Prefix sums+hash map
    Time complexity: O(n)
    Space complexity: O(n)
*/
class Solution{
    public:
        int minSubarray(vector<int>& nums, int p){
            int n=nums.size();
            int r=0;
            for(auto& e: nums) r=(r+e)%p;

            if(r==0) return 0;

            std::unordered_map<int, int> prefix_indexes;
            prefix_indexes[0]=-1; 
            long prefix_sum=0;
            int ans=INT_MAX;

            for (int i=0;i<n;++i) {
                prefix_sum=(prefix_sum+nums[i])%p;
                int test=(((prefix_sum-r)%p)+p)%p; // (prefix_sum-r)%p;
                if(prefix_indexes.find(test)!=prefix_indexes.end()) ans=std::min(ans,i-prefix_indexes[test]);
                prefix_indexes[prefix_sum]=i;
            }

            if(ans==n) return -1;
            return ans==INT_MAX?-1:ans;
        }
};
// @lc code=end

