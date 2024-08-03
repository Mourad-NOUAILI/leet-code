/*
 * @lc app=leetcode id=1518 lang=cpp
 *
 * [1518] Water Bottles
 */

// @lc code=start
/*
    Time complexity: O(1)
*/
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        return numBottles+(numBottles-1)/(numExchange-1);
    }
};
// @lc code=end

