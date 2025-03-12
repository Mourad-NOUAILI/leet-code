/*
 * @lc app=leetcode id=1957 lang=cpp
 *
 * [1957] Delete Characters to Make Fancy String
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Two pointers
    Time complexity: O(n)
    Space complexity: O(n) 
*/
class Solution {
    public:
        std::string makeFancyString(std::string s){
            int n=s.size();
            int left=0,right=0;
            std::string ans;
            while(left<n){
                // if same character extend the window from the right
                if(right<n && s[left]==s[right]) right++;

                // Otherwise
                else{
                    int len=right-left; // Window's length

                    // If window's length >= 2, keep only two characters
                    if(len>=2) ans.push_back(s[left]),ans.push_back(s[left]);

                    // Otherwise, don't delete that character
                    else ans.push_back(s[left]);

                    // Start a new window
                    left=right;
                }
            }
            return ans;
        }
};
// @lc code=end

