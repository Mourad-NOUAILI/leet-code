/*
 * @lc app=leetcode id=2582 lang=cpp
 *
 * [2582] Pass the Pillow
 */

// @lc code=start

/*
    Greedy
    Time complexity: O(time)
    Extra space complexity: O(1)
*/
class Solution {
public:
    int passThePillow(int n, int time) {
       int i=1,dir=1;
       while(time>0){
            if(i+dir>=1 && i+dir<=n) {
                i+=dir;
                time--;    
            }
            else dir*=-1;
        }
        return i;
    }
};
// @lc code=end

