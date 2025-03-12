/*
 * @lc app=leetcode id=1079 lang=cpp
 *
 * [1079] Letter Tile Possibilities
 */

// @lc code=start
/*
    Spacee optimization using frequency array
    Time complexity: O(n!)
    Space complexity: O(n)
*/
class Solution{
    public:
        int numTilePossibilities(std::string tiles) {
            int n=tiles.size();

            std::vector<int> freq(26,0);
            for(auto& c: tiles) freq[c-'A']++;
    

            auto generate=[&](auto& self)->int{
                int ans=0;
    
                for(int i=0;i<26;++i){
                    if(freq[i]==0) continue;
                    freq[i]--;
                    ans+=1+self(self);
                    freq[i]++;
               }
               return ans;
            };
            
            return generate(generate);
        }
};
// @lc code=end

