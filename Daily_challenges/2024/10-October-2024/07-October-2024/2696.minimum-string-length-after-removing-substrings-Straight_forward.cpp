/*
 * @lc app=leetcode id=2696 lang=cpp
 *
 * [2696] Minimum String Length After Removing Substrings
 */

// @lc code=start

#include<bits/stdc++.h>
/*
    Straight forward approach
    Time complexity: O(n^2)
    Space complexity: O(1)
*/
class Solution {
    public:
        int minLength(std::string s){
            bool flag=true;
            while(flag){
                flag=false;
                string::size_type i=s.find("AB");
                if (i!=string::npos){
                    flag=true;
                    s.erase(i,2);
                }
                i=s.find("CD");
                if (i!=string::npos){
                    flag=true;
                    s.erase(i,2);
                }
            }
            return s.size();
        }
};
// @lc code=end

