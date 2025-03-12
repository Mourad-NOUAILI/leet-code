/*
 * @lc app=leetcode id=2416 lang=cpp
 *
 * [2416] Sum of Prefix Scores of Strings
 */

// @lc code=start
#include<bits/stdc++.h>

/*
    Prefix tree (Trie)
    
    Time complexity: O(nm)
    Space complexity: O(nm)
    n: size of words' array
    m: the average length of the strings in words
*/
class Trie{
    private:
        class TrieNode{
            public:
                TrieNode* children[26]={nullptr};
                int count=0;
        };
        TrieNode* root;
    public:
        Trie(){
            root=new TrieNode();
        }
        void insert(std::string& s){
            TrieNode* cur=root;
            for(auto& c: s){
                int i=c-'a';
                TrieNode* node=cur->children[i];
                if(!node){
                    node=new TrieNode();
                    cur->children[i]=node;
                }
                cur->children[i]->count+=1;
                cur=node;
            }
        }

        int compute(std::string& s){
            TrieNode* cur=root;
            int ans=0;
            for(auto& c: s){
                int i=c-'a';
                TrieNode* node=cur->children[i];
                if(node){
                    ans+=cur->children[i]->count;
                    cur=node;
                }
            }
            return ans;
        }
};
class Solution {
    public:
        std::vector<int> sumPrefixScores(std::vector<std::string>& words){
            Trie trie=Trie();
            for(auto& word: words) trie.insert(word);
            std::vector<int> ans;
            for(auto& word: words){
                ans.push_back(trie.compute(word));
            }
            return ans;   
        }
};

// @lc code=end

