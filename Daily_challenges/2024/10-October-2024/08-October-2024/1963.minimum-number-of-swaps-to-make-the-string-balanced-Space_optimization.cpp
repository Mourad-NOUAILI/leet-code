/*
 * @lc app=leetcode id=1963 lang=cpp
 *
 * [1963] Minimum Number of Swaps to Make the String Balanced
 */

// @lc code=start
#include<bits/stdc++.h>

/*
    Space optimization
    Time complexity: O(n)
    Space complexity: O(1)
*/

class Solution {
    public:
        int minSwaps(std::string s) {
            int ans=0;
            for(char& c: s) {
                if (c=='[') ans++;
                else if (ans>0) ans--;
            }
            return (ans+1)/2;
        }
};
// @lc code=end

