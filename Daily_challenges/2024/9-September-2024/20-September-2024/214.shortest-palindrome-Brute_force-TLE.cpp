/*
 * @lc app=leetcode id=214 lang=cpp
 *
 * [214] Shortest Palindrome
 */

// @lc code=start

#include<bits/stdc++.h>


/*
    Brute force - TLE
    Time complexity: O(n*(n+n+n))= O(3n^2)=O(n^2)
    Space complexity: O(n)
*/
class Solution {
    public:
        bool is_palindrome(std::string& s, int left, int right){
            int i=left,j=right;
            while(left<=right && s[left]==s[right]){
                left++;
                right--;
            }
            return left>right;
        }
        std::string shortestPalindrome(std::string s) {
            int n=s.size();
            for(int i=n-1;i>=0;--i){
                if(is_palindrome(s,0,i)){
                    std::string to_add=s.substr(i+1,n-1-i);
                    std::reverse(to_add.begin(),to_add.end());
                    return to_add+s;
                }
            }
            return ""; 
        }
};

// @lc code=end

