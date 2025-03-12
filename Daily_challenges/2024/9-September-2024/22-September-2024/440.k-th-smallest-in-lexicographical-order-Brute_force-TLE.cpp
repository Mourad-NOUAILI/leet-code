/*
 * @lc app=leetcode id=440 lang=cpp
 *
 * [440] K-th Smallest in Lexicographical Order
 */

// @lc code=start

/*
    Brute force:Get all numbers in lexicographical order
    until reaching the k-th
    Time complexity: O(n) - TLE
    Space complexity: O(1)
*/
class Solution {
    public:
        int findKthNumber(int n, int k) {
            long long cur=1;
            k--; // We have already 1.
            while(k){
                k--;
                if(cur*10>n){
                    while(cur==n || cur%10==9) cur/=10;
                    cur++;
                }
                else cur*=10;
            }
            return cur;
        }
};
// @lc code=end

