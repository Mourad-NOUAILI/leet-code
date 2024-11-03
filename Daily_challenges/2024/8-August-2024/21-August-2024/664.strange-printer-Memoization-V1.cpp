/*
 * @lc app=leetcode id=664 lang=cpp
 *
 * [664] Strange Printer
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Memoization
    Time complexity: O(n^3)
    Space complexity: O(n^2)
*/
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

class Solution {
    public:
        int strangePrinter(string s) {
            int n=s.size();

            vvi memo(n,vi(n,-1));

            auto solve=[&](int i,int j, auto& self)->int{
            if (i==j) return 1;

            if(memo[i][j]!=-1) return memo[i][j];
            
            int ans=INT_MAX;

            for (int k=i;k<j;++k) {
                    ans=std::min(ans, self(i,k,self)+self(k+1,j,self));
            }

            return memo[i][j]=s[i]==s[j]?ans-1:ans;

            };

            
            return solve(0,n-1,solve);
        }
};
// @lc code=end

