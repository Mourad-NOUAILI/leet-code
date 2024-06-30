/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 */

// @lc code=start
#include<bits/stdc++.h>

class Solution {
public:
    void reverseString(std::vector<char>& s) {
        /*int i=0;
        int j=s.size()-1;
        while(i<=j) std::swap(s[i++],s[j--]);*/

        auto solve=[&](int left,int right,auto& self){
            if(left>right) return;
            std::swap(s[left],s[right]);
            self(left+1,right-1,self);
        };

        solve(0,s.size()-1,solve);
    }
};
// @lc code=end

