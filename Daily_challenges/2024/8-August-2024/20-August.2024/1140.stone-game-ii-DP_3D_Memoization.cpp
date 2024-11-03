/*
 * @lc app=leetcode id=1140 lang=cpp
 *
 * [1140] Stone Game II
 */

// @lc code=start
#include<bits/stdc++.h>

/*
    DP: 3D Array Memoization
    Time complexity: O(n*M^2)
    Space complexity: O(n^3+n*M^2)

    Without memoization
    Time complexity: O(n^M)
    Space complexity: O(n^M)
*/
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef std::vector<vvi> vvvi;
class Solution {
    public:
        int stoneGameII(std::vector<int>& piles) {
            int n=piles.size();
            vvvi memo(2,vvi(n+1,vi(n+1,-1)));
            auto solve=[&](bool is_alice,int i,int M,auto& self)->int{
                if(i>=n) return 0;

                if(memo[is_alice][i][M]!=-1) return memo[is_alice][i][M];

                int ans=(is_alice)?0:INT_MAX;

                int prefix_sum=0;
                for(int X=1;X<=std::min(2*M,n-i);++X){
                    //if(i+X>n) break;
                    prefix_sum+=piles[i+X-1];
                    ans=is_alice
                        ?std::max(ans,prefix_sum+self(!is_alice,i+X,std::max(M,X),self))
                        :std::min(ans,self(!is_alice,i+X,std::max(M,X),self));
                }
                return memo[is_alice][i][M]=ans;
            };

            return solve(true,0,1,solve);
        }
};
// @lc code=end

