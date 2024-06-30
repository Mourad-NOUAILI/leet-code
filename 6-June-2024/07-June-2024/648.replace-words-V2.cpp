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
        Time complexity: O(n*m)
        Extra space complexity: O(1)
        n: size od the dictionary
        m: number of the words in the sentence
    */
    string replaceWords(vector<string>& dictionary, string sentence) {
        sentence.push_back(' ');
        string word;
        string ans="";
        for(auto& c: sentence){
            if(c!=' ') word.push_back(c);
            else{
                for(auto& dic_word: dictionary){
                    if(dic_word==word.substr(0,dic_word.size())){
                        word=dic_word;
                    }
                }
                ans+=word+" ";
                word.clear();
            }
        }

        ans.pop_back();
        return ans;
    }
};
// @lc code=end

/*
    ["cat","bat","rat","catt","w","rattle"]\n"the cattle was rattled by the battery"\n

    ["a","b","c"]\n"aadsfasf absbs bbab cadsfafs"\n

    ["ab"]\n"a"\n

*/