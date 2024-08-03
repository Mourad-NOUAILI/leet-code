/*
 * @lc app=leetcode id=1518 lang=cpp
 *
 * [1518] Water Bottles
 */

// @lc code=start
/*
    Time complexity: O(log_numExchange (numBottles))
*/
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans=numBottles;
        int empty=numBottles;
        while(numBottles>0){
            numBottles=empty/numExchange;
            ans+=numBottles;
            empty%=numExchange;
            empty+=numBottles;
        }
        return ans;
    }
};
// @lc code=end

