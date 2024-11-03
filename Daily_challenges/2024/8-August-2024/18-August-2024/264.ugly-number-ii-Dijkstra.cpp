/*
 * @lc app=leetcode id=264 lang=cpp
 *
 * [264] Ugly Number II
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Dijkstra Hamming problem: Array
    Time complexity: O(n) - AC
    Space complexity: O(n)
*/
class Solution {
public:
  
    int nthUglyNumber(int n){
        std::vector<int>h(n);
        h[0]=1;

        int x2=2, x3=3, x5=5;

        int i2=0, i3=0, i5=0;
            
        for (int i=1;i<n;i++) {
            h[i]=std::min({x2,x3,x5});
            if (h[i]==x2) x2=2*h[++i2];
            if (h[i]==x3) x3=3*h[++i3];
            if (h[i]==x5) x5=5*h[++i5];
        }
        return h[n-1];
    }
};
// @lc code=end

