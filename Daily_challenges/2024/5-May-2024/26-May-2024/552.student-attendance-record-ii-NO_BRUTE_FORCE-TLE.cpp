/*
 * @lc app=leetcode id=552 lang=cpp
 *
 * [552] Student Attendance Record II
 */

// @lc code=start
#include<bits/stdc++.h>
typedef long long ll;
class Solution {
public:
    // Time complexity: O(n)
    // Extra space complexity: DFS: O(n)
    int checkRecord(int n) {
        const int MOD=1e9+7;
 
        auto solve=[&](int n, int nb_absent,int nb_consecutive_late,auto& self)->ll{
            if(n==0) return 1;
            
            ll ans=0;
            ans=(self(n-1,nb_absent,0,self))%MOD;
            if(nb_absent<1) ans=(ans+self(n-1,nb_absent+1,0,self))%MOD;
            if(nb_consecutive_late<2) ans=(ans+self(n-1,nb_absent,nb_consecutive_late+1,self))%MOD;
            return ans%MOD;
        };
        
        return solve(n,0,0,solve);
    }
};
// @lc code=end

