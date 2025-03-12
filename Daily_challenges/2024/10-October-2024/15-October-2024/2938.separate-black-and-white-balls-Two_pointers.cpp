/*
 * @lc app=leetcode id=2938 lang=cpp
 *
 * [2938] Separate Black and White Balls
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Two pointers (space optimization)
    Time complexity: O(n)
    Space complexity: O(1)
*/
class Solution {
    public:
        long long minimumSteps(string& s){
            int n=s.size();
            long long ans=0;
            int l=0,r=n-1;
            while (l<r){
                while(r>=0 && s[r]=='1') r--;
                if(s[l]=='1'){
                    if(l<r) ans+=(r-l);
                    r--;
                }
                l++;
            }
            return ans;
        }
};
// @lc code=end

