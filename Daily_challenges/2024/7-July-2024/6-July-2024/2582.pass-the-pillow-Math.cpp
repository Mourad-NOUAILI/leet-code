/*
 * @lc app=leetcode id=2582 lang=cpp
 *
 * [2582] Pass the Pillow
 */

// @lc code=start

/*
    Math
    Time complexity: O(1)
    Extra space complexity: O(1)
*/
class Solution {
public:
    int passThePillow(int n, int time) {
        int complete_rounds=time/(n-1);
        int remain_rounds=time%(n-1);

        /*
            If complete rounds is even, we go left to complete the remaining rounds starting from 1
            Otherwise, we go right to complete the remaining rounds starting from n-1
        */

        
        return complete_rounds%2==0?remain_rounds+1:n-remain_rounds;
    }
};
// @lc code=end

