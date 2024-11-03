/*
 * @lc app=leetcode id=476 lang=cpp
 *
 * [476] Number Complement
 */

// @lc code=start
#include<bits/stdc++.h>

/*
    Bit manipulation
    Time complexity: O(log2n)
    Space complexity: O(1)
*/
class Solution {
public:
    int findComplement(int num) {
        if (num == 0) return 1;
        
        // Create a 32 set bits
        unsigned int mask = ~0;
        
        // ~mask is equal to(2^m)-1
        while (num & mask) {
            mask <<= 1;
        }

        // ((2^m)-1) ^ num 
        return ~mask & ~num;
    }
};
// @lc code=end

