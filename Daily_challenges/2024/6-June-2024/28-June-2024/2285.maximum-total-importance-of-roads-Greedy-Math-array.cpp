/*
 * @lc app=leetcode id=2285 lang=cpp
 *
 * [2285] Maximum Total Importance of Roads
 */

// @lc code=start
#include<bits/stdc++.h>

class Solution {
public:
    /*
        Time complexity: O(n log n)
        Extra space complexity: O(2n)
    */
    long long maximumImportance(int n, std::vector<std::vector<int>>& roads) {
        std::vector<int> deg(n,0);
        for(auto& road: roads){
            deg[road[0]]++;
            deg[road[1]]++;
        }

        sort(deg.begin(),deg.end());

        long long ans=0;
        long long v=1;
        for(auto& d: deg){
            ans+=d*v;
            v++;
        }

        return ans;
    }
};
// @lc code=end

