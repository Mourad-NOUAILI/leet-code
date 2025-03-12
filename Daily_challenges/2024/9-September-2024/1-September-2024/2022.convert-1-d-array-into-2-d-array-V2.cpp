/*
 * @lc app=leetcode id=2022 lang=cpp
 *
 * [2022] Convert 1D Array Into 2D Array
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Time complexity: O(m*n)
    Space complexity: O(1)
*/
typedef std::vector<int> vi;
typedef std::vector<std::vector<int>> vvi;
class Solution {
public:
    vvi construct2DArray(vi& original, int m, int n) {
        if(m*n!=original.size()) return {};
        vvi ans(m);
        for(int i=0;i<m;++i){
            ans[i]=vi(original.begin()+(i*n),original.begin()+(i*n+n));
        }
        return ans;
    }
};
// @lc code=end

