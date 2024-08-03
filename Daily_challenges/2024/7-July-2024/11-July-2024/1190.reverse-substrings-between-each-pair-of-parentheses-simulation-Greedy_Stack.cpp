/*
 * @lc app=leetcode id=1190 lang=cpp
 *
 * [1190] Reverse Substrings Between Each Pair of Parentheses
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Time complexity: O(n^2)
    Extra space complexity: O(n)
*/
class Solution {
    public:
        string reverseParentheses(string s) {
            std::stack<char> st;
            for(auto& c: s){
                if(c!=')') st.push(c);
                else{
                    std::string tmp;
                    while(!st.empty() && st.top()!='('){
                        tmp.push_back(st.top());
                        st.pop();
                    }
                    if(!st.empty()) st.pop();
                    for(auto& e: tmp) st.push(e);
                }
            }

            s="";
            while(!st.empty()){
                s.push_back(st.top());
                st.pop();
            }

            std::reverse(s.begin(),s.end());
                
            return s;
        }
   
};
// @lc code=end

