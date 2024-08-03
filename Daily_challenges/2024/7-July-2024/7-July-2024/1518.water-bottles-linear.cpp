/*
 * @lc app=leetcode id=1518 lang=cpp
 *
 * [1518] Water Bottles
 */

// @lc code=start
/*
    Time complexity: O(numBottles)
*/
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int consumed=0;
        while(numBottles>=numExchange){
            consumed+=numExchange;
            numBottles-=numExchange;
            numBottles++;
        }
        return consumed+numBottles;
    }
};
// @lc code=end

