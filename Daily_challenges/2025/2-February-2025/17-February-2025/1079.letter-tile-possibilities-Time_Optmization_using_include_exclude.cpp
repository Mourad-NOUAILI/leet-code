/*
 * @lc app=leetcode id=1079 lang=cpp
 *
 * [1079] Letter Tile Possibilities
 */

// @lc code=start
/*
    Time optimization using include/exclude
    Time complexity: O(nlogn+n.2^n)
    Space complexity: O(n.2^n)
*/
class Solution{
    public:
        int numTilePossibilities(std::string tiles) {
            int n=tiles.size();

            // Preprocess factoriel computations 
            std::vector<int> factoriel(n+1,1);
            auto preprocess_factoriel=[&]()->void{
                for(int i=2;i<=n;++i) factoriel[i]=factoriel[i-1]*i;
            };

            preprocess_factoriel();

            // Sort characters to handle duplicates efficiently
            std::sort(tiles.begin(), tiles.end());

            // To store distinct words
            std::unordered_set<std::string> distinct_words;

            // Generate all possibilities using include/exclude technique
            auto generate=[&](std::string cur_word, int i,auto& self)->int{
                
                // Count the number of permutations without repetitions of a word
                auto count_permutation=[&]()->int{

                    std::vector<int> freq(26,0);
                    for(auto& c: cur_word) freq[c-'A']++;

                    int num=factoriel[cur_word.size()];
                    int denom=1;
                    for(int i=0;i<26;++i){
                        denom*=factoriel[freq[i]];
                    }
                    return num/denom;
                };

                // If we reach the last level
                if(i>=n){
                    // If the current word exists, means that we have already computed its number
                    // of permuations without repetitions
                    if(distinct_words.find(cur_word)!=distinct_words.end()) return 0;

                    // Otherwise:
                    distinct_words.insert(cur_word);    // Add it to the set
                    return count_permutation();         // Compute its number of permutaions without repetitions
                }

                // If last level not reached
                int include=self(cur_word+tiles[i],i+1,self);   // Include the current letters 
                int exclude=self(cur_word,i+1,self);            // Exclude it

               return include+exclude;
            };
            
            return generate("",0,generate)-1; // -1 for empty string
        }
};
// @lc code=end

