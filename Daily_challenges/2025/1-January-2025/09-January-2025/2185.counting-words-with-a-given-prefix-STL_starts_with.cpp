/*
 * @lc app=leetcode id=2185 lang=cpp
 *
 * [2185] Counting Words With a Given Prefix
 */

// @lc code=start
/*
    STL starts_with
    Time complexity: O(n.k), WC: k=m => O(nm)
    Space complexity: O(1)
    n: length of the given list of words
    m: length of the longest word in the given list words
    k: length of the given prefix
*/
class Solution {
    public:
        int prefixCount(std::vector<std::string>& words, std::string pref) {
            int ans=0;
            for(auto& word: words){
                if(word.starts_with(pref)) ans++;
            }
            return ans;
        }
};
// @lc code=end

