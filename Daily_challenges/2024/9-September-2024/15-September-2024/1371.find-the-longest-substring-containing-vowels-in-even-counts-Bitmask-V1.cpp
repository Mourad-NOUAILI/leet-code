/*
 * @lc app=leetcode id=1371 lang=cpp
 *
 * [1371] Find the Longest Substring Containing Vowels in Even Counts
 */

// @lc code=start

#include<bits/stdc++.h>

/*
    Bitmask version 1
    Time complexity: O(32+n)=O(n)
    Space complexity: O(2^5)=O(32)=O(1)
*/
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
class Solution {
    public:
        int findTheLongestSubstring(std::string s) {
            int n=s.size();

            vi seen(32,INT_MIN);
            seen[0]=-1;
            int mask=0;
            int ans=0;
            for(int i=0;i<n;++i){
                if(s[i]=='a') mask^=(1<<4);
                else if(s[i]=='e') mask^=(1<<3);
                else if(s[i]=='i') mask^=(1<<2);
                else if(s[i]=='o') mask^=(1<<1);
                else if(s[i]=='u') mask^=(1<<0);
                if(seen[mask]!=INT_MIN) ans=std::max(ans,i-seen[mask]);
                else seen[mask]=i;
            }
            return ans;
        }
};
// @lc code=end

