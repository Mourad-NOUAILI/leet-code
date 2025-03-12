/*
 * @lc app=leetcode id=1079 lang=cpp
 *
 * [1079] Letter Tile Possibilities
 */

// @lc code=start
/*
    Brute force: Generating n trees: all possible possible words for each level
    Time complxity: O(n! sum(1,k)(1/(n-k)!))
    Space complexity: O(2n+n!)=O(n!)
*/
class Solution{
    public:
        int numTilePossibilities(std::string tiles) {
            int n=tiles.size();

            // To check if the letter at same index is used or not
            std::vector<int> used(n,0);
           
           // To store the generating word
            std::string word;
            
            // To store distinct words
            std::unordered_set<std::string> distinct_words;
            
            auto generate=[&](int k,auto& self)->void{
                // If the generated word is of size k
                if(k==0){
                    // Save the generated word in the set
                    distinct_words.insert(word);
                    return;
                }

                // For each letter in the tiles
                for(int i=0;i<n;++i){
                    // If the letter at position i is not used
                    if(used[i]==0){
                        word.push_back(tiles[i]);   // Add it to the word
                        used[i] = 1;                // Mark it as used
                        self(k-1,self);             // Do the same to the (k-1) remaing positions in word

                        // If a word of size k is generated
                        used[i]=0; // Mark the current letter as not used
                        word.pop_back(); // Reduce the size of the word
                    }
                }
            };
            
            // generate a word of size k from the tiles
            for(int k=1;k<=n;++k){
                generate(k,generate); // create a tree of height k 
            }

            return distinct_words.size();
        }
};
// @lc code=end

