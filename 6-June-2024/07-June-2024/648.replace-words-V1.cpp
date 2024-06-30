/*
 * @lc app=leetcode id=648 lang=cpp
 *
 * [648] Replace Words
 */

// @lc code=start
#include<bits/stdc++.h>

class Solution {
public:
        /*
            Time complexity: O(m)
            Extra space complexity: O(m)
            m: number of the words in the sentence
        */
    vector<string> split_string(string& s, char delimeter){
        s.push_back(delimeter);
        vector<string> words;
        string word;
        for(auto& c: s){
            if(c!=delimeter) word.push_back(c);
            else{
                words.push_back(word);
                word.clear();
            }
        }
        return words;
    }

    /*
        Time complexity: O(m)+O(n*m)+O(m)=O(n*m)
        Extra space complexity: O(m)
        n: size od the dictionary
        m: number of the words in the sentence
    */
    string replaceWords(vector<string>& dictionary, string sentence) {
        std::vector<string> words=split_string(sentence,' ');

        int m=words.size();
        for(auto& dic_word: dictionary){
            for(int i=0;i<m;++i){
                string word=words[i];
                if(dic_word==word.substr(0,dic_word.size())) words[i]=dic_word;
            }
        }
        
        string ans="";
        for(auto& word: words) ans+=word+" ";
        ans.pop_back();
        return ans;
    }
};
// @lc code=end

/*

    ["a","b","c"]\n"aadsfasf absbs bbab cadsfafs"\n

    ["ab"]\n"a"\n

*/