/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Find the Index of the First Occurrence in a String
 */

// @lc code=start
#include<bits/stdc++.h>

/*
    Brute force
    Time complexity: O(nm)
    Space complexity: O(1)
*/
class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        if(needle=="") return 0;
        int n=haystack.size();
        int m=needle.size();
        for(int i=0;i<=n-m;++i){
            if(haystack.substr(i,m)==needle) return i;
        }
        return -1;
    }
};
// @lc code=end

