/*
 * @lc app=leetcode id=1079 lang=cpp
 *
 * [1079] Letter Tile Possibilities
 */

// @lc code=start
/*
    Brute force: Generating one tree: all possible words
    Time complxity: O(n!)
    Space complexity: O(n+n!)=O(n!)
*/
class Solution{
    public:
        int numTilePossibilities(std::string tiles) {
            int n=tiles.size();

            std::vector<int> freq(26,0);
            for(auto& c: tiles) freq[c-'A']++;
            
            std::string word;
            
            std::unordered_set<std::string> distinct_words;
            
            auto generate=[&](int k,auto& self)->void{
                if(k==0) return;
                
                for(int i=0;i<n;++i){
                    if(freq[tiles[i]-'A']!=0){
                        word.push_back(tiles[i]);
                        freq[tiles[i]-'A']--;
                        distinct_words.insert(word);
                        self(k-1,self);
                        freq[tiles[i]-'A']++;
                        word.pop_back();
                    }
                }
            };
            
            
            generate(n,generate);
            

            return distinct_words.size();
        }
};
// @lc code=end

