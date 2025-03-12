/*
 * @lc app=leetcode id=796 lang=cpp
 *
 * [796] Rotate String
 */

// @lc code=start
#include<bits/stdc++.h>

/*
    Concatenation check
    Time complexity: O(n)
    Space complexity: O(2n)
*/
class Solution {
    public:
        bool rotateString(std::string s,std::string goal) {
            int n=s.size();
            if(n!=goal.size()) return false;

            // if `goal` can be obtained by rotating `s`, `goal` must be
            // a subtring of  s+s
            std::string ss=s+s;
            return ss.find(goal)!=std::string::npos;
        }
};
// @lc code=end

