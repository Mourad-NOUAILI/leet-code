/*
 * @lc app=leetcode id=2185 lang=cpp
 *
 * [2185] Counting Words With a Given Prefix
 */

// @lc code=start
/*
    STL find
    Time complexity: O(n.m.k),  WC: k=m => O(nm^2)
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
                if(word.find(pref)==0) ans++;
            }
            return ans;
        }
};
// @lc code=end

