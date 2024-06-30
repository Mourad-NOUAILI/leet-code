/*
 * @lc app=leetcode id=1208 lang=cpp
 *
 * [1208] Get Equal Substrings Within Budget
 */

// @lc code=start
#include<bits/stdc++.h>
class Solution {
public:
    // Time complexity: O(n)
    // Extra space complexity: O(1)
    int equalSubstring(std::string s, std::string t, int maxCost) {
        int n=s.size();
        int i=0,ans=0,c=0;
        for(int j=0;j<n;++j){
            c+=abs((s[j]-'a')-(t[j]-'a'));
            while(c>maxCost){
                c-=abs((s[i]-'a')-(t[i]-'a'));
                i++;
            }
            ans=std::max(ans,j-i+1);
        }
        return ans;
    }
};
// @lc code=end

/*
    "abcd"\n"cdef"\n3\n

    "abcd"\n"acde"\n0\n

    "abcdefgh"\n"ijklmnop"\n100\n 
    ==>8

*/