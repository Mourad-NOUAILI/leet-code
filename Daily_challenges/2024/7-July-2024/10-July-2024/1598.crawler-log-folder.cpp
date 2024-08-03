/*
 * @lc app=leetcode id=1598 lang=cpp
 *
 * [1598] Crawler Log Folder
 */

// @lc code=start
#include<bits/stdc++.h>

class Solution {
public:
    int minOperations(std::vector<std::string>& logs) {
         int ans=0;
        for(auto& log: logs){
            if(log == "./") continue;
            if(log=="../") ans=std::max(0,ans-1);
            else ans++;
        }
        
        return ans;
    }
};
// @lc code=end

