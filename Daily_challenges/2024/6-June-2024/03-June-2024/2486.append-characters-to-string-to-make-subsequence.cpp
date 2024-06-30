/*
 * @lc app=leetcode id=2486 lang=cpp
 *
 * [2486] Append Characters to String to Make Subsequence
 */

// @lc code=start
#include<bits/stdc++.h>

class Solution {
public:
    int appendCharacters(std::string s, std::string t){
        int n=s.size();
        int m=t.size();
        int i=0;
        int j=0;
        while(i<n && j<m){
            if(s[i]==t[j]){
                i++;
                j++;
            }
            else i++;
        }
        return m-j;
    }
};
// @lc code=end

