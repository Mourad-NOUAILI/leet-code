/*
 * @lc app=leetcode id=1823 lang=cpp
 *
 * [1823] Find the Winner of the Circular Game
 */

// @lc code=start
#include<bits/stdc++.h>

/*
    Time complexity=O(n)
    Extra space complexity: O(1)
*/
class Solution {
public:
    int findTheWinner(int n, int k) {
        int x=0;
        for(int i=2;i<=n;++i) x=(x+k)%i;
        return x+1;
    }
};
// @lc code=end

