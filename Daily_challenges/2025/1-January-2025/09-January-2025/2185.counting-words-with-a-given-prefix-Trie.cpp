/*
 * @lc app=leetcode id=2185 lang=cpp
 *
 * [2185] Counting Words With a Given Prefix
 */

// @lc code=start
/*
    Trie
    Time complexity: O(n.m+k),  WC: k=m => O(nm)
    Space complexity: O(nm)
    n: length of the given list of words
    m: length of the longest word in the given list words
    k: length of the given prefix
*/
class Trie{
    public:
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
        
        
        ~Trie(){delete_trie(root);}

        // Delete the try to avoid memory leaks
        void delete_trie(TrieNode* root){
            if(!root) return;
            for(int i=0;i<26;++i){
                TrieNode* node=root->children[i];
                delete_trie(node);
            }
            delete root;
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
                cur->children[i]->count++;
                cur=node;
            }
        }

        int compute(std::string& s){
            TrieNode* cur=root;
            for(auto& c: s){
                int i=c-'a';
                TrieNode* node=cur->children[i];
                if(!node) return 0;
                cur=node;
            }
            return cur->count;
        }
};

class Solution {
public:
    int prefixCount(std::vector<std::string>& words, std::string pref){
        int k=pref.size();
        Trie trie=Trie();
        for(auto& word: words) trie.insert(word);
        
        int ans=trie.compute(pref);
        return ans;
    }
};
// @lc code=end

