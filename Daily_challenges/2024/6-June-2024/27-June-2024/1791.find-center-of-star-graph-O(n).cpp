/*
 * @lc app=leetcode id=1791 lang=cpp
 *
 * [1791] Find Center of Star Graph
 */

// @lc code=start
#include<bits/stdc++.h>

class Solution {
public:
    /*
        Time complexity: O(n)
        Extra space complexity: O(2n)
    */
    int findCenter(std::vector<std::vector<int>>& edges) {
        int m=edges.size();
        
        std::map<int,int> freq;
        for(auto& edge: edges){
            freq[edge[0]]++;
            freq[edge[1]]++;
        }

        for(auto& [u,f]: freq){
            if(f==m) return u;
        }

        return -1; // Never reached
    }
};
// @lc code=end

