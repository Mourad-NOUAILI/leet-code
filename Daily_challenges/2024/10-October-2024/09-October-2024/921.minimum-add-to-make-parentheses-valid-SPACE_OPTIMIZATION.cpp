/*
 * @lc app=leetcode id=921 lang=cpp
 *
 * [921] Minimum Add to Make Parentheses Valid
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
        int minAddToMakeValid(std::string s) {
            int open=0;
            int close=0;
            for (char& c : s){
                if (c=='(') open++;
                else open>0?open--:close++;
            }   
            return close+open;
        }
};
// @lc code=end

