/*
 * @lc app=leetcode id=3045 lang=cpp
 *
 * [3045] Count Prefix and Suffix Pairs II
 */

// @lc code=start
/*
    Prefix tree (Trie)
    Time compelxity: O(n.m)
    Space compelxity: O(n.m)
*/
class Trie{
    public:
        class TrieNode{
            public:
                std::unordered_map<int,TrieNode*> children;
                long long count=0;
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
            for(auto& [_,node]: root->children){
                delete_trie(node);
            }
            delete root;
        }

        long long solve(std::vector<std::string>& words){
            int n=words.size();
            long long ans=0;
            for(auto& word: words){
                TrieNode* cur=root;
                int m=word.size();
                for(int i=0;i<m;++i){
                    int hash=(word[i]-'a')*26+word[m-i-1]-'a';
                    TrieNode* node=cur->children[hash];
                    if(!node){
                        node=new TrieNode();
                        cur->children[hash]=node;
                    }
                    
                    ans+=cur->children[hash]->count;
                    cur=node;
                }
                // The word is completely processed, it could be a prefix and a suffix for another word,
	            // so increment its count
                cur->count++;
            }
            return ans;
        } 
};


class Solution {
    public:
        long long countPrefixSuffixPairs(std::vector<std::string>& words) {
            Trie trie=Trie();
            return trie.solve(words);
        }
};
// @lc code=end

