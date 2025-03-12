/*
 * @lc app=leetcode id=2696 lang=cpp
 *
 * [2696] Minimum String Length After Removing Substrings
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
        int minLength(std::string s){
            std::stack<char> st;
            bool push=true; // To know what to push
            for(char& c: s){
                push=true; // By default we will push the current character
                if(!st.empty() && c=='B'){ // if current character is 'B'
                    // if the previuos character is 'A', remove it and 
                    // no need to push 'B'
                    if(st.top()=='A') st.pop(),push=false;
                }
                else if(!st.empty() && c=='D'){ // if current character is 'D'
                    // if the previuos character is 'C', remove it and 
                    // no need to push 'D'
                    if(st.top()=='C') st.pop(),push=false;
                }
                
                if(push) st.push(c);
            }
            
            return st.size();
        }
};
// @lc code=end

