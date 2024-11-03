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
        // Find number of bits of n
        int m=floor(log2(n))+1;

        // One's complement=((2^m)-1) xor n
        return (int)(((1*1ll)<<m)-1)^n;
    }
};
// @lc code=end

