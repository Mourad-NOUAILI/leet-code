/*
 * @lc app=leetcode id=409 lang=cpp
 *
 * [409] Longest Palindrome
 */

// @lc code=start
#include<bits/stdc++.h>

class Solution {
public:
    /*
        Time complexity: O(|s|)
        Extra space complexity: O(52)=O(1)
    */
    int longestPalindrome(std::string s){
        int freq[52]={0};
        for(auto& l: s){
            if(islower(l)) freq[l-'a']++;
            else freq[l-'A'+26]++;
        }
        int sum=0;
        for(int i=0;i<52;++i) sum+=freq[i]%2;
        
        return sum==0?s.size():s.size()-sum+1;  
    }
};
// @lc code=end

/*
    "aabaAbbA"\n
    ==>7

    "aabaAbbAcccAaAC"\n
    ==>13

    "aaaabbccccccAABBCC"\n
    ==>18

    "aaaabbccccccAAABBBBCC"\n
    ==>21

    "hzhdhKDHDDHJSgsgsgXxXXXXXXXXXXXxxxxxTTTETEtrtsshshhHHHHhdhdhtte"\n
*/