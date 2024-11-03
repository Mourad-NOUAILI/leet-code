/*
 * @lc app=leetcode id=1937 lang=cpp
 *
 * [1937] Maximum Number of Points with Cost
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Dynamic programming: Memoization
    Time complexity: o(n.mn)=O(mn^2) (TLE)
    Space complexity: O(2mn)=O(mn)
*/
typedef vector<long long> vi; 
typedef vector<vi> vvi;

class Solution {
public:
    long long maxPoints(std::vector<std::vector<int>>& points) {
        int m=points.size();
        int n=points[0].size();

        vvi memo(m,vi(n,-1));

        auto solve=[&](int i, int j, auto& self)->long long{
            if(i>=m) return 0;
            if(memo[i][j]!=-1) return memo[i][j];
            long long ans=0;
            for(int k=0;k<n;++k) {
                long long val=points[i][k]-abs(k-j)+self(i+1,k,self);
                ans=std::max(ans,val);
                
            }
            return memo[i][j]=ans;
        };

        long long ans=0;
        for(int i=0;i<n;++i) {
            long long val=(long long)points[0][i]+solve(1,i,solve);
            ans=std::max(ans,val);
        }
        
        return ans;
    }
};
// @lc code=end

