/*
 * @lc app=leetcode id=1508 lang=cpp
 *
 * [1508] Range Sum of Sorted Subarray Sums
 */

// @lc code=start
#include<bits/stdc++.h>
/*  
    min heap
    Time complexity:O(nlogn)
    Space complexity: O(n)
*/
typedef std::pair<int,int> ii;
typedef std::vector<ii> vii;

class Solution {
    public:
        int rangeSum(std::vector<int>& nums, int n, int left, int right) {
            int MOD=1'000'000'007;

            std::priority_queue<ii,vii,std::greater<ii>> min_heap;

            for(int i=0;i<n;++i) min_heap.push({nums[i],i});

            int s=0;
            for(int i=0;i<right;++i){
                auto [e,index]=min_heap.top();
                min_heap.pop();
                if(i>=left-1) s=(s+e)%MOD;
                if(index+1<n) min_heap.push({e+nums[index+1],index+1});
            }
            return s;
        }
};
// @lc code=end