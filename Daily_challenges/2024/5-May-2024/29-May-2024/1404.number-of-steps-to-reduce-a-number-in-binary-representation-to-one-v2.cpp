/*
 * @lc app=leetcode id=1404 lang=cpp
 *
 * [1404] Number of Steps to Reduce a Number in Binary Representation to One
 */

// @lc code=start
#include<bits/stdc++.h>
class Solution {
    public:
        /*
            Version #2: Do not modify the input string
            Overall time complexity: O(ans*|s|)
            Extra space complexity: O(1)
        */
        int numSteps(std::string s) {
            int ans=0,carry=0;
            int n=s.size();
            for(int i=n-1;i>0;--i){
                if((s[i]-'0'+carry)%2){
                    ans+=2;
                    carry=1;
                }
                else ans++;
                
            }
            return ans+carry;
        }
};
// @lc code=end

