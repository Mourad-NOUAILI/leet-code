/*
 * @lc app=leetcode id=2220 lang=cpp
 *
 * [2220] Minimum Bit Flips to Convert Number
 */

// @lc code=start

#include<bits/stdc++.h>


/*
    Built-in function: Count set bits
    Time complexity: O(32)=O(1)
    Space complexity: O(1)
*/
class Solution {
public:
    int minBitFlips(int start, int goal) {
        return __builtin_popcount(start ^ goal);
    }
};
// @lc code=end

