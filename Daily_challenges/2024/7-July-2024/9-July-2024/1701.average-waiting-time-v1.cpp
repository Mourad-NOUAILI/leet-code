/*
 * @lc app=leetcode id=1701 lang=cpp
 *
 * [1701] Average Waiting Time
 */

// @lc code=start
#include<bits/stdc++.h>

/*
    Simulation (Greedy)
    Time complexity: O(n)
    Extra space complexity: O(1)
*/
class Solution {
public:
    double averageWaitingTime(std::vector<std::vector<int>>& customers) {
        int n=customers.size();
        long long start=customers[0][0];
        long long end=start+customers[0][1];
        long long s=end-start;
        for(int i=1;i<n;++i){
            auto c=customers[i];
            start=c[0];
            if(start<=end) end+=c[1];
            else end=c[0]+c[1];
            s+=(end-start);
        }
        return s*1.0/n;
    }
};
// @lc code=end

