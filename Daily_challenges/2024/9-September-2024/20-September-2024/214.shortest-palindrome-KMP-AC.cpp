/*
 * @lc app=leetcode id=214 lang=cpp
 *
 * [214] Shortest Palindrome
 */

// @lc code=start

#include<bits/stdc++.h>


/*
    Knuth–Morris–Pratt(KMP)
    Time complexity: O(n*(n+n+n))= O(3n^2)=O(n^2)
    Space complexity: O(n)
*/

class Solution {
    public:
        std::string shortestPalindrome(std::string s) {
            int n=s.size();

            std::string rev=std::string(s.rbegin(), s.rend());
            std::string needle=s+'@'+rev;
            int m=needle.size();
            
            // Longest prefix suffix
            std::vector<int> lps(m,0);
            int prev_lps_index=0,i=1;
            while(i<m){
                if(needle[prev_lps_index]==needle[i]){
                    lps[i]=prev_lps_index+1;
                    prev_lps_index++;
                    i++;
                }
                else if(prev_lps_index==0){
                    lps[i]=0;
                    i++;
                }
                else prev_lps_index=lps[prev_lps_index-1];
            }

            int len=lps[needle.size()-1];

            return rev.substr(0,s.size()-len)+s;
        }
};
// @lc code=end

