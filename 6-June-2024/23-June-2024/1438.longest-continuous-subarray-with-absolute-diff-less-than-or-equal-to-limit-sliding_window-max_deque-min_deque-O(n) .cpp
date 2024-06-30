/*
 * @lc app=leetcode id=1438 lang=cpp
 *
 * [1438] Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit
 */

// @lc code=start
#include<bits/stdc++.h>

typedef std::pair<int,int> ii;

class Solution {
public:
    /*
        Sliding window(two pointers technique)+max deque+min deque
        Time complexity: O(n)
        Extra space complexity: O(2n)
      
    */
    int longestSubarray(std::vector<int>& nums, int limit) {
        int n=nums.size();

        std::deque<ii> max_dq;
        std::deque<ii> min_dq;

        int i=0,j=0,d=0,ans=0;
        while(j<n){
            while(!max_dq.empty()&&nums[j]>max_dq.back().first) max_dq.pop_back();
            while(!min_dq.empty()&&nums[j]<min_dq.back().first) min_dq.pop_back();
            max_dq.push_back({nums[j],j});
            min_dq.push_back({nums[j],j});
            d=max_dq.front().first-min_dq.front().first;
            while(i<j&&d>limit){
                i=std::min(max_dq.front().second,min_dq.front().second)+1;
                while(!max_dq.empty()&&max_dq.front().second<i) max_dq.pop_front();
                while(!min_dq.empty()&&min_dq.front().second<i) min_dq.pop_front();
                d=max_dq.front().first-min_dq.front().first;
            }
            ans=std::max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};
// @lc code=end

/*
    [10,1,2,4,7,2]\n5\n

    [4,2,2,2,4,4,2,2]\n0\n

    [1,2,5]\n10\n

    [1,5,6,7,8,10,6,5,6]\n4\n

*/