/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Find the Index of the First Occurrence in a String
 */

// @lc code=start
#include<bits/stdc++.h>

/*
    KMP
    Time complexity: O(n+m)
    Space complexity: O(1)
*/
class Solution {
    public:
        int strStr(string haystack, string needle) {
            if(needle=="") return 0;

            // Longest prefix suffix
            int n=haystack.size();
            int m=needle.size();
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

            i=0; // Pointer for haystack
            int j=0; // Pointer for needle
            while(i<n){
                if(haystack[i]==needle[j]){
                    i++;
                    j++;
                }
                else if(j==0) i++;
                else j=lps[j-1];
                
                if(j==m) return i-m;
            }
            return -1;
        }
};
// @lc code=end

