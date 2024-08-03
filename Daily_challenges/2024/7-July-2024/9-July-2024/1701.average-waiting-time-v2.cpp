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
        long long s=0;
        long long end=0;
        for(int i=0;i<n;++i){
            auto c=customers[i];
            long long arrival=c[0];
            long long time=c[1];
            s+=(std::max(arrival,end)+time-arrival);
            end=(std::max(arrival,end)+time);
        }
        return s*1.0/n;
    }
};
// @lc code=end

