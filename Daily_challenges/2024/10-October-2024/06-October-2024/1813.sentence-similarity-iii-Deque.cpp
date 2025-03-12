/*
 * @lc app=leetcode id=1813 lang=cpp
 *
 * [1813] Sentence Similarity III
 */

// @lc code=start

#include<bits/stdc++.h>

/*
    Deque
    Time complexity: O(n+m)
    Space complexity: O(#words in sentence1+#words in sentence2)
*/
class Solution {
    public:
        void string2deque(std::string s, std::deque<std::string>& q){
            std::stringstream ss(s);
            std::string word;
            while(ss>>word) q.push_back(word);
        }
        bool areSentencesSimilar(string sentence1, string sentence2) {
            // To be sure that sentence1 is longer than sentence2
            if(sentence1.size()<sentence2.size()) swap(sentence1,sentence2);

            // Put words of each sentence in an deque
            std::deque<std::string> q1,q2;
            string2deque(sentence1,q1);
            string2deque(sentence2,q2);

            // Check
            while(!q2.empty() && q1.front()==q2.front()){
                q1.pop_front();
                q2.pop_front();
            }
            while(!q2.empty() && q1.back()==q2.back()){
                q1.pop_back();
                q2.pop_back();
            }
               
            return q2.empty();
        }
};
// @lc code=end

