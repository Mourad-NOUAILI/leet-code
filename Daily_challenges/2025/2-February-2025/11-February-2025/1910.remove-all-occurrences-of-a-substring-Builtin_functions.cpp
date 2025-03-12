/*
 * @lc app=leetcode id=1910 lang=cpp
 *
 * [1910] Remove All Occurrences of a Substring
 */

// @lc code=start
/*
    In place: Straight forward simulation built-in functions
    Time commplexity:   O(n^2/m)
    Space complexity:   O(1)
    n=|s|,m=|part|
*/
class Solution {
    public:
        std::string removeOccurrences(std::string& s, std::string& part){
            // While part exists in s
            std::size_t pos=s.find(part);
            while(pos!=std::string::npos){
                // Erase it
                s.erase(pos,part.size());
                pos=s.find(part);
            }
            return s;
        }
};
// @lc code=end

