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
        Extra space complexity: O(6n)
    */
    long long maximumImportance(int n, std::vector<std::vector<int>>& roads) {
        std::map<int,int> deg;
        for(auto& road: roads){
            deg[road[0]]++;
            deg[road[1]]++;
        }

        std::vector<std::pair<int,int>> vec;
        for (auto& p: deg) vec.push_back(p);
        sort(vec.begin(),vec.end(),[](const std::pair<int,int>& p1,const std::pair<int,int>& p2){return p1.second>p2.second;});

        std::map<int,int> assignments;
        for(int i=0;i<n;++i) assignments[i]=0;
        
        int v=n;
        for(auto& [u,d]: vec){
          assignments[u]=v;
          v--;
        }

        long long ans=0;
        for(auto& road: roads){
            ans+=assignments[road[0]]+assignments[road[1]];
        }

        return ans;
    }
};
// @lc code=end

