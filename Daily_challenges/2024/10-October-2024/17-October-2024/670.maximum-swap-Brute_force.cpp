/*
 * @lc app=leetcode id=670 lang=cpp
 *
 * [670] Maximum Swap
 */

// @lc code=start

#include<bits/stdc++.h>

/*
    Brute force
    Time complexity: O(n^2)
    Space complexity: O(n)
    n=log_10(num)
*/
class Solution {
public:
    int maximumSwap(int num){
        std::string s=std::to_string(num);
        int n=s.size();
        // For every digit s[i]
        for(int i=0;i<n-1;++i){
            // Find the last maximum from i+1 to n-1
            char mx='0'; // Last encountered max
            int mx_pos=0; // with its position (will be used for teh swap)
            for(int j=i+1;j<n;++j){
                if(mx<=s[j]){
                    mx=s[j];
                    mx_pos=j;
                }
            }
            // If the current digit s[i] is less than the maximum,
            // perform the swap
            if(s[i]<mx){
                std::swap(s[i],s[mx_pos]);
                return std::stoi(s);
            }
        }

        // If no swap is performed
        return std::stoi(s);
    }
};
// @lc code=end

