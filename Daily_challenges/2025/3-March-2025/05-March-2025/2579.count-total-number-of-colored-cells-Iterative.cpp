/*
 * @lc app=leetcode id=2579 lang=cpp
 *
 * [2579] Count Total Number of Colored Cells
 */

// @lc code=start
/*
    Iterative
    Time compelxity: O(n)
    Space compelxity: O(1)
*/
class Solution {
    public:
        long long coloredCells(int n) {
            long long to_add=4,ans=1;
            while(--n){
                ans+=to_add;
                to_add+=4;
            }
            return ans;
        }
};
// @lc code=end

