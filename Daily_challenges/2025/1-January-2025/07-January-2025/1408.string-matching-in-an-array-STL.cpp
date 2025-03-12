/*
 * @lc app=leetcode id=1408 lang=cpp
 *
 * [1408] String Matching in an Array
 */

// @lc code=start
/*
    Brute force: STL find
    Time complexity: O(n^2*m^2)
    Space complexity: O(1)
    n: size of the words's list
    m: size of a word in the list of words 
*/
class Solution {
    public:
        std::vector<std::string> stringMatching(std::vector<std::string>& words){
            int n=words.size();
            std::vector<std::string> ans;

            // For each words[i] as a needle:
            for(int i=0;i<n;++i){
                for(int j=0;j<n;++j){
                    // take words[j] as a haystack
                    // if same string ignore it
                    if(i==j) continue;

                    // If the the needle words[i] math in the haystack words[j]
                    // add the needle words[i] to the answer
                    if(words[j].find(words[i])!=string::npos){
                        ans.push_back(words[i]);
                        break; // ans must contains unique words
                    }
                }
            }
            return ans;
        }
};
// @lc code=end

