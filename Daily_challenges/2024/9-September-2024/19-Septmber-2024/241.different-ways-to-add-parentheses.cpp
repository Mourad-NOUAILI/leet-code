/*
 * @lc app=leetcode id=241 lang=cpp
 *
 * [241] Different Ways to Add Parentheses
 */

// @lc code=start
#include<bits/stdc++.h>


/*
    Recursivity
    Time complexity: O(n.2^n)
    Space complexity: O(2^n)
*/

typedef std::vector<int> vi;
class Solution {
    public:
        // dispatch table
        std::unordered_map<char , std::function<int(int,int)> > operations{
            {'+',[](int a, int b){ return a + b;} },
            {'-',[](int a, int b){ return a - b;} },
            {'*',[](int a, int b){ return a * b;} } };

    public:
        vi diffWaysToCompute(std::string expression){
            // Base case
            if(std::all_of(expression.begin(),expression.end(),::isdigit)){
                return {std::stoi(expression)};
            }

            int n=expression.size();
            vi ans;
            // Divide...
            for(int i=0;i<n;++i){
                char c=expression[i];
                if(operations.find(c)!=operations.end()){
                    //... and conquer
                    vi left=diffWaysToCompute(expression.substr(0,i));
                    vi right=diffWaysToCompute(expression.substr(i+1,n-1-i));

                    // Combine
                    for(auto& x: left){
                        for(auto& y: right){
                            ans.push_back(operations[c](x,y));
                        }
                    }
                }
            }
            
           return ans;
        }
};
// @lc code=end

