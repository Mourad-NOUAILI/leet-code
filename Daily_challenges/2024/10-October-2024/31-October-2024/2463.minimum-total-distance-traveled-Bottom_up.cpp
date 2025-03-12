/*
 * @lc app=leetcode id=2463 lang=cpp
 *
 * [2463] Minimum Total Distance Traveled
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Include/Exclude: bottom up
    Time complexity: O(nlogn+mlogm+nm)=O(mn)
    Space complexity: O(m+mn)
*/

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
class Solution {
    public:
        ll minimumTotalDistance(vi& robot,vvi& factory){
            // To ensure that the robot goes the the nearest factory 
            std::sort(robot.begin(),robot.end());
            std::sort(factory.begin(),factory.end());
            
            /*
                having 1 factory of k limits <=> having k factories of limit 1
                (at the same position)
            */
            vi factories;
            for(auto& f: factory){
                for(int i=1;i<=f[1];++i) factories.push_back(f[0]); 
            }

            int n=robot.size();
            int m=factories.size();

            std::vector<std::vector<ll>> dp(n+1,std::vector<ll>(m+1,0));

            for(int robot_index=1;robot_index<=n;++robot_index) dp[robot_index][0]=LONG_MAX/2;

            for(int robot_index=1;robot_index<=n;++robot_index){
                for(int factory_index=1;factory_index<=m;++factory_index){
                    
                    ll include=abs(robot[robot_index-1]-factories[factory_index-1])
                                +dp[robot_index-1][factory_index-1];

                    ll exclude=dp[robot_index][factory_index-1];

                    dp[robot_index][factory_index]=std::min(include,exclude);
                }
            }
                      
            return dp[n][m];
        }
};
// @lc code=end

