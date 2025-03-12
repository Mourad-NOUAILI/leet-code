/*
 * @lc app=leetcode id=1233 lang=cpp
 *
 * [1233] Remove Sub-Folders from the Filesystem
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Trie
    Time complexity: O(n.m)
    Space complexity: O(n.m)
    n: Number of folders
    m: Maximum length of a folder path
*/
class Trie{
    private:
        class TrieNode{
            public:
                std::unordered_map<std::string,TrieNode*> children;
                bool is_end_of_folder_path=false;
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
            for(auto& [folder,node]: root->children){
                delete_trie(node);
            }
            delete root;
        }

        void insert(std::string& path){
            TrieNode* cur_node=root;
            std::stringstream ss(path);
            std::string f;
            while(std::getline(ss,f,'/')){
                if(f.empty()) continue;
                TrieNode* node=cur_node->children[f];
                if(!node){
                    node=new TrieNode();
                    cur_node->children[f]=node;
                }
                cur_node=node; 
            }
            cur_node->is_end_of_folder_path=true;
        }

        bool is_sub_folder(std::string& path){
            TrieNode* cur_node=root;
            std::stringstream ss(path);
            std::string f; 
            while(std::getline(ss,f,'/')){
                if(f.empty()) continue;
                TrieNode* next_node=cur_node->children[f];
                // If the current folder is a path and is not the last folder
                if(next_node->is_end_of_folder_path && ss.tellg()!=-1) return true;
                cur_node=next_node;    
            }
            return false;
        }
};

typedef std::vector<std::string> vs;

class Solution {
    public:
        
        vs removeSubfolders(vs& folder){
            Trie trie=Trie();

            // For each path insert the folders in the trie
            for(auto& path: folder) trie.insert(path);

            // For each pathr, check if it is a subfolder
            // It it is, don't insert it  
            vs ans;
            for(auto& path: folder){
                if(!trie.is_sub_folder(path)) ans.push_back(path);  
            }

            return ans;
        }
};
// @lc code=end

