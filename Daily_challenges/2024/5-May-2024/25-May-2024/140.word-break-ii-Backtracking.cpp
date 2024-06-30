/*
 * @lc app=leetcode id=140 lang=cpp
 *
 * [140] Word Break II
 */

// @lc code=start
#include<bits/stdc++.h>

class Solution {
public:
    std::vector<std::string> wordBreak(std::string s, std::vector<std::string>& wordDict) {
        int n=s.size();

        auto solve=[&](std::string s,auto& self)-> std::vector<std::string>{

            if(s=="") return {""};
            
            std::vector<std::string> ans;

            for(auto& w: wordDict){
                if(s.substr(0, w.size()) == w){
                    auto sub_words=self(s.substr(w.size()),self);
                    for(auto& sw: sub_words){
                        std::string str=w+(sw!=""?" ":"")+sw;
                        ans.push_back(str);
                    }
                }
            }
            return ans;
        };

        return solve(s,solve);
    }
};
// @lc code=end


/*

    "pineapplepenapple"\n["apple","pen","applepen","pine","pineapple"]\n

*/

