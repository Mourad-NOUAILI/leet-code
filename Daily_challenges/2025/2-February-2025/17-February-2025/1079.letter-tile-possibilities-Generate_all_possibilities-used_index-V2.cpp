/*
 * @lc app=leetcode id=1079 lang=cpp
 *
 * [1079] Letter Tile Possibilities
 */

// @lc code=start
/*
    Brute force: Generating one tree: all possible words
    Time complxity: O(n!)
    Space complexity: O(2n+n!)=O(n!)
*/
class Solution{
    public:
        int numTilePossibilities(std::string tiles) {
            int n=tiles.size();

            std::vector<int> used(n,0);
           
            
            std::string word;
            
            std::unordered_set<std::string> distinct_words;
            
            auto generate=[&](int k,auto& self)->void{
                if(k==0) return;
                for(int i=0;i<n;++i){
                    if(used[i]==0){
                        word.push_back(tiles[i]);
                        used[i]=1;
                        self(k-1,self);
                        distinct_words.insert(word);
                        used[i]=0;
                        word.pop_back();
                    }
                }
            };
            
            generate(n,generate);


            return distinct_words.size();
        }
};
// @lc code=end

