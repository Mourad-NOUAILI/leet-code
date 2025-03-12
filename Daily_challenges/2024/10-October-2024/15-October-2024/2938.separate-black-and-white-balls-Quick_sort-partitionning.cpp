/*
 * @lc app=leetcode id=2938 lang=cpp
 *
 * [2938] Separate Black and White Balls
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Quick sort (Partitioning principle needs two pointers )
    Time complexity: O(n)
    Space complexity: O(n)
*/
class Solution {
    public:
        long long minimumSteps(string& s){
            int n=s.size();
            long long ans=0;
           
            int l=0,r=n-1;
            while(l<r){
                while(l<n && s[l]=='0') l++;
                while(r>=0 && s[r]=='1') r--;
                if(l<r){
                    ans+=(r-l);
                    std::swap(s[l],s[r]);
                }
            }
            return ans;
        }
};
// @lc code=end

