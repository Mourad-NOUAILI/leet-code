/*
 * @lc app=leetcode id=796 lang=cpp
 *
 * [796] Rotate String
 */

// @lc code=start
#include<bits/stdc++.h>

/*
    KMP (see LC's problem 28 )
    Time complexity: O(n)
    Space complexity: O(2n+m)
*/
class Solution {
    public:
        bool rotateString(std::string s,std::string goal){
            if(s.size()!=goal.size()) return false;
            
            std::string ss=s+s;

            int n=ss.size();
            int m=goal.size();

            // Build Longest prefix suffix array
            std::vector<int> lps(m,0);
            int prev=0,i=1;
            while(i<m){
                if(goal[prev]==goal[i]){
                    lps[i]=prev+1;
                    prev++;
                    i++;
                }
                else if(prev==0){
                    lps[i]=0;
                    i++;
                }
                else prev=lps[prev-1];
            }

            // Check the 1st occurence of `goal` in `s+s`
            i=0;
            int j=0;
            while(i<n){
                if(ss[i]==goal[j]){
                    i++;
                    j++;
                }
                else if(j==0) i++;
                else j=lps[j-1];

                if(j==m) return true;
            }

            return false;
        }

};
// @lc code=end

