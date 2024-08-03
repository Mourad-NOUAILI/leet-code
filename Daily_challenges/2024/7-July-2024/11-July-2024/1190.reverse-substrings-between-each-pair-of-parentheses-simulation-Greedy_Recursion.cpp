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
            int i=0;
            int n=s.size();
            auto solve=[&](std::string& str,auto& self)->std::string{
                std::string ans="";
                while(i<n){
                    if(s[i]==')'){
                        i++;
                        std::reverse(ans.begin(),ans.end());
                        return ans;
                    }
                    else if(s[i]=='('){
                        i++;
                        ans+=self(s,self);
                    }
                    else{
                        ans+=s[i];
                        i++;
                    }
                }
                return ans;
            };   
                
            return solve(s,solve);
        }
   
};
// @lc code=end

