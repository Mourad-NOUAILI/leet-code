/*
 * @lc app=leetcode id=592 lang=cpp
 *
 * [592] Fraction Addition and Subtraction
 */

// @lc code=start

#include<bits/stdc++.h>

/*
    C++ convert using regex
    Time complexity: O(n+n+m+m+m)=O(2n+3m)=O(n)
    Space complexity: O(m+m+2m)=O(m)
    where:  n is the length of the given expression
            m the number of fractions in the given expression
             m<n
*/

typedef std::pair<int,int> ii; 
typedef std::vector<ii> vii;

class Solution {
    public:
        vii convert(string& expression) {
            vii fractions;
            std::regex regex("([+-]?\\d+)/(\\d+)");
            smatch matches;
            while (std::regex_search (expression,matches,regex)){
                int num=stoi(matches[1]),denom=stoi(matches[2]);
                fractions.push_back({num,denom});
                expression=matches.suffix().str();
            }
            return fractions;
        }

        ii add(ii& x, ii& y){
            auto [xp, xq]=x;
            auto [yp, yq]=y;
            long long q=xq*yq;
            long long p=xp*yq+xq*yp;
            long long g=gcd(p, q);
            return {p/g, q/g};
        }
        
        std::string fractionAddition(std::string expression){
            vii fractions=convert(expression);
            int m=fractions.size();
            ii ans={0,1};
            for(auto& f: fractions){
                ans=add(ans,f);
            }
            string s=to_string(ans.first)+"/"+to_string(ans.second);
            return s;
        }
        
};
// @lc code=end

