/*
 * @lc app=leetcode id=1106 lang=cpp
 *
 * [1106] Parsing A Boolean Expression
 */

// @lc code=start

#include<bits/stdc++.h>
/*
    Recursion
    Time complexity: O(n)
    Space complexity: O(n)
*/

class Solution {
    public:
        bool parseBoolExpr(std::string expression){
            // int& i: all intances of the function should share the same i pointer
            auto solve=[&](std::string& exp,int& i,auto& self)->bool{
                char c=exp[i++]; // Get current character

                if(c=='t') return true;
                if(c=='f') return false;

                // Handle "!(...)"
                if(c=='!'){
                    i++; // Skip '('
                    bool ans=!self(exp,i,self);
                    i++; // Skip ')'
                    return ans;
                }

                // Handle "&(...)" and "|(...)"
                i++; // Skip '('
                std::vector<bool> operands;
                while(exp[i]!=')'){
                    if(exp[i]!=',') operands.push_back(self(exp,i,self));
                    else i++; // Skip ','
                }
                i++; // Skip ')'

                // Evaluate "|(...)"
                if(c=='|'){
                    for(bool v: operands){
                        if (v) return true;
                    }
                    return false;
                }

                // Evaluate "&(...)"
                if(c=='&'){
                    for(bool v: operands){
                        if (!v) return false;
                    }
                    return true;
                }

                return true; // Never reached
            };
            
            int i=0;
            return solve(expression,i,solve);
        }
};
// @lc code=end

