/*
 * @lc app=leetcode id=1140 lang=cpp
 *
 * [1140] Stone Game II
 */

// @lc code=start
#include<bits/stdc++.h>

/*
    DP: 2D array Memoization
    Time complexity: O(n*M^2)
    Space complexity: O(n^2+n.M^2)

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

            vi suffix_sum(n,0);

            // Calculate suffix sums
            suffix_sum[n-1]=piles[n-1];
            for (int i=n-2;i>=0;--i) {
                suffix_sum[i]=suffix_sum[i+1]+piles[i];
            }

            vvi memo(n+1,vi(n+1,-1));

            auto solve=[&](int i,int M,auto& self)->int{
                if(i>=n) return 0;

                if(memo[i][M]!=-1) return memo[i][M];

                int ans=INT_MIN;

                for(int X=1;X<=std::min(2*M,n-i);++X){
                    ans=std::max(ans,suffix_sum[i]-self(i+X,std::max(X,M),self));
                }
                return memo[i][M]=ans;
            };

           
            int sum=accumulate(piles.begin(), piles.end(), 0);
            return solve(0,1,solve);
        }
    };
// @lc code=end

