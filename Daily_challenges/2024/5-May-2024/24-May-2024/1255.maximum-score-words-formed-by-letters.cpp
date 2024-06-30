/*
 * @lc app=leetcode id=1255 lang=cpp
 *
 * [1255] Maximum Score Words Formed by Letters
 */

// @lc code=start
#include<bits/stdc++.h>

class Solution {
public:
    int maxScoreWords(std::vector<std::string>& words, std::vector<char>& letters, std::vector<int>& score) {
        int nb_words=words.size();
        std::vector<int> freq_letters(26,0);
        std::vector<int> freq_letters_in_words(26,0);

        for(auto& c: letters) freq_letters[c-'a']++;

        int ans=0,temp_ans=0;

        auto solve = [&](int index,auto& self)->void{
            for(int i=0;i<26;++i){
                if(freq_letters_in_words[i]>freq_letters[i]) return;
            }
            
            ans=std::max(ans,temp_ans);

            for(int i=index;i<nb_words;++i){
                for(auto& c: words[i]){
                    freq_letters_in_words[c-'a']++;
                    temp_ans+=score[c-'a'];
                }
            
                self(i+1,self);

                for(auto& c: words[i]){
                    freq_letters_in_words[c-'a']--;
                    temp_ans-=score[c-'a'];
                }
            }

        };

        solve(0,solve);

        return ans;
    }
};
// @lc code=end

/*

    ["xxxz","ax","bx","cx"]\n["z","a","b","c","x","x","x"]\n[4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,10]\n


    ["leetcode"]\n["l","e","t","c","o","d"]\n[0,0,1,1,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0]\n



    ["add","dda","bb","ba","add"]\n["a","a","a","a","b","b","b","b","c","c","c","c","c","d","d","d"]\n[3,9,8,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]\n

*/