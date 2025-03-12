/*
 * @lc app=leetcode id=1813 lang=cpp
 *
 * [1813] Sentence Similarity III
 */

// @lc code=start

#include<bits/stdc++.h>

/*
    Arrays (two pointers)
    Time complexity: O(n+m)
    Space complexity: O(#words in sentence1+#words in sentence2)
*/
class Solution {
    public:
        void string2vector(std::string s, std::vector<std::string>& v){
            std::stringstream ss(s);
            std::string word;
            while(ss>>word) v.push_back(word);
        }

        bool areSentencesSimilar(string sentence1, string sentence2) {
            // To be sure that sentence1 is longer than sentence2
            if(sentence1.size()<sentence2.size()) swap(sentence1,sentence2);

            // Put words of each sentence in an array
            std::vector<std::string> v1,v2;
            string2vector(sentence1,v1);
            string2vector(sentence2,v2);

            int n=v1.size();
            int m=v2.size();

            // Check similarity
            int i=0,j=n-1; // sentence1 (v1)
            int k=0,l=m-1; // sentence2 (v2)
            while(k<m && v1[i]==v2[k]){
                i++;
                k++;
            }
            while(l>=0 && v1[j]==v2[l]){
                j--;
                l--;
            }
               
            return l<k;
        }
};
// @lc code=end

