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
        Time complexity: O(n*|word|)+O(26n)+O(min_count[i]*26)=O(n*|word|)
        Extra space complexity: O(n*26)+O(26)=O(n)
    */
    vector<string> commonChars(vector<string>& words) {
        std::unordered_map<string,std::vector<int>> counting;
        for(auto& word: words){
            std::vector<int> count(26,0);
            for(auto& letter: word){
                count[letter-'a']++;
            }
            counting[word]=count;
        }

        std::vector<int>min_count(26,INT_MAX);
        for(auto& [word,count]: counting){
            for(int i=0;i<26;++i) min_count[i]=std::min(min_count[i],count[i]);
        }

        vector<string> ans;
        for(int i=0;i<26;++i){
            if(min_count[i]>0) {
                for(int j=1;j<=min_count[i];++j){
                    ans.push_back(string{char(i+'a')});
                }
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