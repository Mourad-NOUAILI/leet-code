/*
 * @lc app=leetcode id=2463 lang=cpp
 *
 * [2463] Minimum Total Distance Traveled
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Include/Exclude: Recursion+Memoization
    Time complexity: O(nlogn+mlogm+nm)=O(mn)
    Space complexity: O(mn)+O(m+n)
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

            std::vector<std::vector<ll>> memo(n,std::vector<ll>(m,-1));

            auto solve=[&](int robot_index,int factory_index,auto& self)->ll{
                // All robots are repaired
                //(Must be called first)
                if(robot_index==n) return 0;

                // If we still have broken robots and not no more factories 
                if(factory_index==m) return LONG_MAX/2;

                 if(memo[robot_index][factory_index]!=-1) return memo[robot_index][factory_index];

                
                ll include=
                    abs(robot[robot_index]-factories[factory_index]) // current robot moves to current factory
                    +self(robot_index+1,factory_index+1,self); // Pass the the next robot and next factory
                                                                // This is why sorting is important

                // Current robot skip the current factory
                // and go the next nearest factoty
                // This is why sorting is important
                ll exclude=self(robot_index,factory_index+1,self);

                return  memo[robot_index][factory_index]=std::min(include,exclude);
            };
            
            return solve(0,0,solve);
        }
};
// @lc code=end

