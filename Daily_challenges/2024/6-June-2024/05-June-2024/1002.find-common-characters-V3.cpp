/*
 * @lc app=leetcode id=1002 lang=cpp
 *
 * [1002] Find Common Characters
 */

// @lc code=start
#include<bits/stdc++.h>

class Solution {
public:
    /*
        Time complexity: O(n*|word|)+O(26n)=O(n*|word|)
        Extra space complexity: O(n*26)=O(n)
    */
    vector<string> commonChars(vector<string>& words) {
        int n=words.size();
        std::vector<std::vector<int>> count(n,std::vector<int>(26,0));
       
        for(int i=0;i<n;++i){
            for(auto& letter: words[i]){
                count[i][letter-'a']++;
            }
        }

        std::vector<string> ans;

        for(int i=0;i<26;++i){
            int mi=INT_MAX;
            for(int j=0;j<n;++j){
                mi=std::min(mi,count[j][i]);
            }
            for(int j=1;j<=mi;++j){
                ans.push_back(string{char(i+'a')});
            }
        }
        

        return ans;
    }
};
// @lc code=end

/*
    ["coooooooooool","loock","cook"]\n
    ==>["c","o","o"]


    ["abcd"]\n

    ["abcd","xycd","abef"]\n

    ["acabcddd","bcbdbcbd","baddbadb","cbdddcac","aacbcccd","ccccddda","cababaab","addcaccd"]
    ==>[]

*/