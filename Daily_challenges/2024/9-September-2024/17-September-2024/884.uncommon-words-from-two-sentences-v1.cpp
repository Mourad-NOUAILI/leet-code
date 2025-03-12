/*
 * @lc app=leetcode id=884 lang=cpp
 *
 * [884] Uncommon Words from Two Sentences
 */

// @lc code=start
#include<bits/stdc++.h>

/*
    Custom algo to split words + map
    Time complexity: O(nlog w1 +m log (w1+w2)+log (w1+w2))
    Space complexity: O(w1+w2)
    n: size of sentence 1
    m: size of sentence 2
    w1: #words in sentence 1
    w2: #words in sentence 2
*/
class Solution {
    public:
        void count(std::string& s,std::map<std::string,int>& freq){
            s+=" ";
            int n=s.size();
            std::string word="";
            for(auto& letter: s){
                if(letter!=' ') word+=letter;
                else{
                    freq[word]++;
                    word="";
                }
            }
        }
        std::vector<std::string> uncommonFromSentences(std::string s1, std::string s2) {
            std::map<std::string,int> freq;
            count(s1,freq);
            count(s2,freq);
            std::vector<std::string> ans;
            for(auto& [word,f]: freq){
                if(f==1) ans.push_back(word);
            }
            return ans;
        }
};
// @lc code=end

