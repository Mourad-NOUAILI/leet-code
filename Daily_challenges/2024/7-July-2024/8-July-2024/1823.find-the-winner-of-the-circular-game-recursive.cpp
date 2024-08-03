/*
 * @lc app=leetcode id=1823 lang=cpp
 *
 * [1823] Find the Winner of the Circular Game
 */

// @lc code=start
#include<bits/stdc++.h>

/*
    Time complexity=O(n)
    Extra space complexity: O(n)
*/
class Solution {
public:
    int findTheWinner(int n, int k) {
        auto solve=[&](int n,auto& self)->int{
            if(n==1) return 0;
            return (self(n-1,self)+k)%n;
        };

        return solve(n,solve)+1;
    }
};
// @lc code=end

