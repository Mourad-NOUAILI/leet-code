/*
 * @lc app=leetcode id=796 lang=cpp
 *
 * [796] Rotate String
 */

// @lc code=start
#include<bits/stdc++.h>

/*
    Straight simulation v1
    Time complexity: O(n^2)
    Space complexity: O(1)
*/
class Solution {
    public:
        bool rotateString(std::string s,std::string goal) {
            int n=s.size();
            if(n!=goal.size()) return false;
            while(n--){
                s.push_back(s[0]);
                s.erase(s.begin());
                if(s==goal) return true;
            }
            return false;
        }
};
// @lc code=end

