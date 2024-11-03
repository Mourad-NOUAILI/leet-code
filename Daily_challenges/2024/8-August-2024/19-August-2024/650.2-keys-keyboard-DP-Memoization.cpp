/*
 * @lc app=leetcode id=650 lang=cpp
 *
 * [650] 2 Keys Keyboard
 */

#include<bits/stdc++.h>

/*
    DP: Memoization (Top-Down)
    Time complexity: O(n^2)
    Space complexity: O(n+n^2)
*/

typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

class Solution {
public:
    int minSteps(int n) {   
        vvi memo(n+1,vi(n/2+1,-1));
        auto solve=[&](int i,int j,auto& self)->int{
            if(i==n) return 0;
            if(i>n) return INT_MAX/2;
            if(memo[i][j]!=-1) return memo[i][j];
            return memo[i][j]=std::min(2+self(2*i,i,self) , 1+self(i+j,j,self));
        };

        if(n==1) return 0;
        return 1+solve(1,1,solve);
    }
};
// @lc code=end

