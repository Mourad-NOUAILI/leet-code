/*
 * @lc app=leetcode id=1937 lang=cpp
 *
 * [1937] Maximum Number of Points with Cost
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Dynamic programming: Tabulation
    Time complexity: O(n+m(n+n^2)+n)=O(2n+mn+mn^2)=O(mn^2) (TLE)
    Space complexity: O(n)
*/
typedef vector<long long> vi; 
typedef vector<vi> vvi;
class Solution {
public:
    long long maxPoints(std::vector<std::vector<int>>& points) {
        int m=points.size();
        int n=points[0].size();
        
        vi dp(points[0].begin(),points[0].end());

        for(int i=1;i<m;++i){
            vi tmp=dp;
            for(int j=0;j<n;++j){
                long long mx=-1;
                for(int k=0;k<n;++k){
                    mx=std::max(mx,tmp[k]+points[i][j]-(abs(k-j)));
                }
                dp[j]=mx;
            }
        }

        long long ans=*std::max_element(dp.begin(),dp.end());

        return ans;
    }
};
// @lc code=end

