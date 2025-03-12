/*
 * @lc app=leetcode id=1400 lang=cpp
 *
 * [1400] Construct K Palindrome Strings
 */

// @lc code=start
/*
    Math: counting number of odds frequencies
    using a bitmask
    Time Complexity:O(n)
    Space compelxity: O(1)

*/
class Solution {
    public:
        bool canConstruct(std::string s, int k) {
            if(k>s.size()) return false;

            // Update the bitmask for each character
            int bitmask=0;
            for(auto& letter: s) bitmask^=1<<(26-(letter-'a'));

            // Count the number of set bits in the bitmask
            int count_odd= __builtin_popcount(bitmask);
            return count_odd<=k;
        }
};
// @lc code=end

