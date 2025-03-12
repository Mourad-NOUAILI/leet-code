/*
 * @lc app=leetcode id=2220 lang=cpp
 *
 * [2220] Minimum Bit Flips to Convert Number
 */

// @lc code=start

/*
    Bit manimulation: left shift
    Time complexity: O(max bits)
    Space complexity: O(1)
*/
class Solution {
    public:
        int minBitFlips(int start, int goal) {
            int xored=start^goal;
            int ans=0;
            while(xored){
                if(xored&1) ans++;
                xored>>=1;
            }
            return ans;
        }
};
// @lc code=end

