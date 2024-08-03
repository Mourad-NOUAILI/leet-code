/*
 * @lc app=leetcode id=912 lang=cpp
 *
 * [912] Sort an Array
 */

// @lc code=start
#include<bits/stdc++.h>

/*
    priority_queue (min heap)
    
    Time complexity: O(nlogn)
    Extra space complexity: O(n)
*/
class Solution {
public:
    std::vector<int> sortArray(std::vector<int>& nums) {
        std::priority_queue<int,std::vector<int>,std::greater<int>> q;
        for(auto& e: nums) q.push(e);
        int i=0;
        while(!q.empty()){
            nums[i++]=q.top();
            q.pop();
        }
        return nums;
    }
};
// @lc code=end

