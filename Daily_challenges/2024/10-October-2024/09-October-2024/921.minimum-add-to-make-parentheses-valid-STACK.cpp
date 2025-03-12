/*
 * @lc app=leetcode id=921 lang=cpp
 *
 * [921] Minimum Add to Make Parentheses Valid
 */

// @lc code=start

#include<bits/stdc++.h>
/*
    Stack
    Time complexity: O(n)
    Space complexity: O(n)
*/
class Solution {
    public:
        int minAddToMakeValid(std::string s) {
            std::stack<char> st;
            bool push;
            for(char& c: s){
                push=true;
                if(c==')'){
                    if(!st.empty() && st.top()=='(') st.pop(),push=false;
                }
                if(push) st.push(c);
            }
            return st.size();
        }
};
// @lc code=end

