/*
 * @lc app=leetcode id=592 lang=cpp
 *
 * [592] Fraction Addition and Subtraction
 */

// @lc code=start

#include<bits/stdc++.h>

/*
    Intuitive approach:  String manipulation+Math+implementation
    Time complexity: O(n+n+m+m+m)=O(2n+3m)=O(n)
    Space complexity: O(m+m+2m)=O(m)
    where:  n is the length of the given expression
            m the number of fractions in the given expression
             m<n
*/

typedef std::vector<int> vi;
typedef std::pair<int,int> ii; 
typedef std::vector<ii> vii;

class Solution {
    public:
         /*
            Return an array of integers containing all denominators
            extracted from the given expression.
            Time Complexity: O(n)
            Space complexity: O(m)
            where:  n is the length of the given expression
                    m the number of fractions in the given expression
                    m<n
        */
        vi get_denominators(std::string& exp){
            vi res;
            int n=exp.size();
            int i=0;
            while(i<n){
                char c=exp[i];
                if(c=='/'){
                    int j=i+1;
                    std::string number_str="";
                    while(j<n&&std::isdigit(exp[j])){
                        number_str+=exp[j];
                        j++;
                    }
                    if(number_str!="") res.push_back(stoi(number_str));
                    i=j;
                }
                else i++;
            }
            return res;
        }

         /*
            Return an array of integers containing all numerators
            extracted from the given expression.
            Time Complexity: O(n)
            Space complexity: O(m)
            where:  n is the length of the given expression
                    m the number of fractions in the given expression
                    m<n
        */
        vi get_numerators(std::string& exp){
            int n=exp.size();
            vi res;
            int i=0;
            while(i<n){
                char c=exp[i];
                if(c=='/'){
                    int j=i-1;
                    std::string number_str="";
                    while(j>=0 && std::isdigit(exp[j])){
                        number_str=exp[j]+number_str;
                        j--;
                    }
                    if(j==0 && exp[j]=='-') number_str='-'+number_str;
                    if(j-1>=0 && (exp[j-1]=='+' || exp[j-1]=='-')) number_str='-'+number_str;
                    if(j-1>=0 && (exp[j]=='-' && std::isdigit(exp[j-1]))) number_str='-'+number_str;
                    if(number_str!="") res.push_back(stoi(number_str));
                }
                i++;
            }
            return res;
        }
        /*
            Compute LCM as common denominator
        */
        ii add(ii& x, ii& y){
            auto [xp, xq]=x;
            auto [yp, yq]=y;
            long long q=xq*yq;
            long long p=xp*yq+xq*yp;
            long long g=std::gcd(abs(p), abs(q));
            return {p/g, q/g};
        }
        
        std::string fractionAddition(std::string expression){
            vi denominators=get_denominators(expression);

            vi numerators=get_numerators(expression);
        
            int m=numerators.size();
            vii fractions(m);
        
            for(int i=0;i<m;++i){
                fractions[i]={numerators[i],denominators[i]}; 
            }

            ii ans={0,1};
            for(auto& f: fractions){
                ans=add(ans,f);
            }
            std::string s=to_string(ans.first)+"/"+to_string(ans.second);
            return s;
        }
};
// @lc code=end

