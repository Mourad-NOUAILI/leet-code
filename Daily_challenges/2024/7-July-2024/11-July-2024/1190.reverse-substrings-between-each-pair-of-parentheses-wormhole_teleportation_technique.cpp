/*
 * @lc app=leetcode id=1190 lang=cpp
 *
 * [1190] Reverse Substrings Between Each Pair of Parentheses
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Time complexity: O(nm), m is # of valid barckets
    Extra space complexity: O(n)
*/
class Solution {
    public:
        string reverseParentheses(string s) {
            int n=s.size();
            std::stack<int> st;
            std::vector<int> oppsite_index(n,-1);
            for(int i=0;i<n;++i){
                if (s[i]=='(') st.push(i);
                else if(s[i]==')'){
                    int p=st.top();
                    st.pop();
                    oppsite_index[p]=i;
                    oppsite_index[i]=p;
                }
            }

            int dir=1;
            int i=0;
            std::string ans="";
            while (i<n){
                if(s[i]=='(' || s[i]==')'){
                    i=oppsite_index[i];
                    dir*=-1;
                }
                else ans+=s[i];

                i+=dir;
            }

            return ans;
        }
   
};
// @lc code=end

