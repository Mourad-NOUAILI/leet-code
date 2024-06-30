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
        Sliding window(two pointers technique)+max heap+min heap
        Time complexity: O(n log n)
        Extra space complexity: O(2n)
      
    */
    int longestSubarray(std::vector<int>& nums, int limit) {
        int n=nums.size();

        std::priority_queue<ii> max_heap;
        std::priority_queue<ii,std::vector<ii>,std::greater<ii>> min_heap;

        int i=0,j=0,d=0,ans=0;
        while(j<n){
            max_heap.push({nums[j],j});
            min_heap.push({nums[j],j});
            d=max_heap.top().first-min_heap.top().first;
            while(i<j&&d>limit){
                i=std::min(max_heap.top().second,min_heap.top().second)+1;
                while(max_heap.top().second<i) max_heap.pop();
                while(min_heap.top().second<i) min_heap.pop();
                d=max_heap.top().first-min_heap.top().first;
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