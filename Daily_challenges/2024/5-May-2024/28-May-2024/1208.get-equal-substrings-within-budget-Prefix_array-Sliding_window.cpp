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
    // Extra space complexity: O(n)
    int equalSubstring(std::string s, std::string t, int maxCost) {
        int n=s.size();
        std::vector<int> coast(n+1);
        coast[0]=0;
        for(int i=1;i<=n;++i){
            coast[i]=abs((s[i-1]-'a')-(t[i-1]-'a'));
        }

        for(int i=1;i<=n;++i) coast[i]=coast[i]+coast[i-1];

        int i=1,ans=0;
        for(int j=1;j<=n;++j){
            int c=coast[j]-coast[i-1];
            while(c>maxCost){
                i++;
                c=coast[j]-coast[i-1];
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

    "abcdefgh"\n"xddgfoei"\n10\n

*/