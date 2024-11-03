/*
 * @lc app=leetcode id=476 lang=cpp
 *
 * [476] Number Complement
 */

// @lc code=start
#include<bits/stdc++.h>

/*
    C++ built-in functions
    Time complexity: O(log2n)
    Space complexity: O(1)
*/
class Solution {
public:
    int findComplement(int n) {
        return ((~0) << (32-__builtin_clz(n))) ^ (~n);
    }
};
// @lc code=end

