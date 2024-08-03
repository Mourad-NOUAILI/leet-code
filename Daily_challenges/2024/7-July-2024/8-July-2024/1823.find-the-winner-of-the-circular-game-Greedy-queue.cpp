/*
 * @lc app=leetcode id=1823 lang=cpp
 *
 * [1823] Find the Winner of the Circular Game
 */

// @lc code=start
#include<bits/stdc++.h>

/*
    Time complexity=O(nk)
    Extra space complexity: O(n)
*/
class Solution {
public:
    int findTheWinner(int n, int k) {
        std::queue<int> q;
        for(int i=1;i<=n;++i) q.push(i);
        while(q.size()>1){
           for(int i=1;i<k;++i){
            q.push(q.front());
            q.pop();
           }
           q.pop();
        }
        return q.front();
    }
};
// @lc code=end

