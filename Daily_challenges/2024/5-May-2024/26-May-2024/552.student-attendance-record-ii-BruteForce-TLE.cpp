/*
 * @lc app=leetcode id=552 lang=cpp
 *
 * [552] Student Attendance Record II
 */

// @lc code=start
#include<bits/stdc++.h>

class Solution {
public:
    // Time complexity: O(3^n+n+n)
    // Extra space complexity: DFS: O(n)
    int checkRecord(int n) {
        const int MOD=10e9+7;
        const std::string letters="ALP";
        std::string s;
      
        auto solve=[&](int n,auto& self)->int{
            if(n==0){
                int abscenes=std::count(s.begin(),s.end(),'A');
                int is_late=s.find("LLL")!=-1;
                return abscenes<2 && !is_late;
            }
            int ans=0;
            for(int i=0;i<3;++i){
                char letter=letters[i];
                s.push_back(letter);
                ans+=(self(n-1,self)%MOD);
                s.pop_back(); 
            }
            return ans%MOD;
        };
        return solve(n,solve);
    }
};
// @lc code=end

