/*
 * @lc app=leetcode id=2109 lang=cpp
 *
 * [2109] Adding Spaces to a String
 */

// @lc code=start
/*
    Naive
    Time compelxity: O(m.(n+m))=O(m^2+m.n)=O(m^2)
    Space complexity: O(1)
*/
class Solution {
public:
    std::string addSpaces(std::string s, std::vector<int>& spaces) {
        int new_size=0; // Track of the new size of s
        for(auto& p: spaces){
            s.insert(s.begin()+p+new_size,' ');
            new_size++;
        }
        return s;
    }
};
// @lc code=end

