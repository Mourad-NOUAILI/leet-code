/*
 * @lc app=leetcode id=1545 lang=cpp
 *
 * [1545] Find Kth Bit in Nth Binary String
 */

// @lc code=start

#include<bits/stdc++.h>

/*
    Brute force
    Time complexity: O(2^n)
    Space complexity: O(2^n)
*/
class Solution {
    public:
        std::string invert(std::string s){
            int n=s.size();
            for(int i=0;i<n;++i){
                s[i]=s[i]=='0'?'1':'0';
            }
            return s;
        }
        std::string reverse(std::string s){
            std::reverse(s.begin(),s.end());
            return s;
        }
        char findKthBit(int n, int k){
            std::string s="0";
            for(int i=2;i<=n;++i){
                s+="1"+reverse(invert(s));
            }
            return s[k-1];
        }
};
// @lc code=end

