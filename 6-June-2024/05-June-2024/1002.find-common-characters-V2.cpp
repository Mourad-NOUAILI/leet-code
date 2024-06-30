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
        Extra space complexity: O(26)+O(26)=O(1)
    */
    vector<string> commonChars(vector<string>& words) {
        std::vector<int> count(26,0);
        for(auto& letter: words[0]){
            count[letter-'a']++;
        }

        for(auto& word: words){
            std::vector<int> tmp_count(26,0);
            for(auto& letter: word){
                tmp_count[letter-'a']++;
            }

            for(int i=0;i<26;++i){
                count[i]=std::min(count[i],tmp_count[i]);
            }
        }

        std::vector<string> ans;
        for(int i=0;i<26;++i){
            if(count[i]>0){
                for(int j=1;j<=count[i];++j){
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