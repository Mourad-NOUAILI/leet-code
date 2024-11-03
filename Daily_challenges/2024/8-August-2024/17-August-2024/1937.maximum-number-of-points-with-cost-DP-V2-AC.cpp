/*
 * @lc app=leetcode id=1937 lang=cpp
 *
 * [1937] Maximum Number of Points with Cost
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Dynamic programming: Tabulation+prefix,suffix max
    Time complexity: O(n+m.6n+n)=O(2n+6mn)=O(m.n) (AC)
    Space complexity: O(3n)=O(n)
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
            vi prefix_max(n,0),suffix_max(n,0);
            prefix_max[0]=dp[0];
            for(int j=1;j<n;++j){
                prefix_max[j]=std::max(dp[j],prefix_max[j-1]-1);
            }

            suffix_max[n-1]=dp[n-1];
            for(int j=n-2;j>=0;--j){
                suffix_max[j]=std::max(dp[j],suffix_max[j+1]-1);
            }

            std::transform(points[i].begin(),points[i].end(),dp.begin(),[](int x) {return (long long)x;});

            for(int j=0;j<n;++j){
                dp[j]+=std::max(prefix_max[j],suffix_max[j]);
            }
        }

        long long ans=*std::max_element(dp.begin(),dp.end());

        return ans;
    }
};
// @lc code=end

