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
       int u1=edges[0][0];
       int u2=edges[0][1];
       int u3=edges[1][0];
       int u4=edges[1][1];
       if(u1==u3 || u1==u4) return u1;
       return u2;
    }
};
// @lc code=end

