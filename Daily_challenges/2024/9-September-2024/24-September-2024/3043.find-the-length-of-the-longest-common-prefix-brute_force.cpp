/*
 * @lc app=leetcode id=3043 lang=cpp
 *
 * [3043] Find the Length of the Longest Common Prefix
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Brute force - TLE
    Time complexity: O(n*m*min(log_10(x),log_10(y)))
    Space complexity: O(1)
    n: size of arr1
    m: size of arr2
    x: elements of arr1
    y: elements of arr2
*/

class Solution {
    public:
        int longest_prefix(std::string& s1, std::string& s2){
            int i=0;
            int limit=std::min(s1.size(),s2.size());
            while(i<limit &&  s1[i]==s2[i]) i++;
            return i;
        }
        int longestCommonPrefix(std::vector<int>& arr1, std::vector<int>& arr2) {
            int ans=0;
            for(auto& x: arr1){
                for(auto& y: arr2){
                    std::string sx=std::to_string(x);
                    std::string sy=std::to_string(y);
                    ans=std::max(ans,longest_prefix(sx,sy));
                }
            }
            return ans;
        }
};
// @lc code=end

