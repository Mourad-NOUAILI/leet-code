/*
 * @lc app=leetcode id=2530 lang=cpp
 *
 * [2530] Maximal Score After Applying K Operations
 */

// @lc code=start
#include<bits/stdc++.h>

/*
    max heap
    Time complexity: O((n+k)logn)
    space complexity: O(n)
*/
class Solution {
    public:
        long long maxKelements(vector<int>& nums,int k){
            std::priority_queue<int,std::vector<int>> max_heap;
            for(auto& e: nums) max_heap.push(e);
            long long score=0;
            while(k--){
                int mx=max_heap.top();
                max_heap.pop();
                score+=mx;
                mx=ceil((double)mx/3.0);
                max_heap.push(mx);
            }
            return score;
        }
};
// @lc code=end

