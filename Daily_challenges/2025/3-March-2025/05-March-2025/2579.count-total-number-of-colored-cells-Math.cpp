/*
 * @lc app=leetcode id=2579 lang=cpp
 *
 * [2579] Count Total Number of Colored Cells
 */

// @lc code=start
/*
    Math
    Time compelxity: O(1)
    Space compelxity: O(1)
*/
class Solution {
    public:
        long long coloredCells(int n) {
            return 2*n*1ll*n*1ll-2*n*1ll+1ll;
        }
};
// @lc code=end

