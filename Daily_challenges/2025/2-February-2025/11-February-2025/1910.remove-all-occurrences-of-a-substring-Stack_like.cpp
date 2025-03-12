/*
 * @lc app=leetcode id=1910 lang=cpp
 *
 * [1910] Remove All Occurrences of a Substring
 */

// @lc code=start
/*
    Stack-Like
    Time commplexity:   O(n*m)
    Space complexity:   O(1), if output not counted
                        O(n), if output counted
    n=|s|,m=|part|
*/

class Solution {
    public:
        std::string removeOccurrences(std::string s, std::string part) {
            int n=s.size();
            int m=part.size();

            std::string ans;
            // For each character in s
            for(int i=0;i<n;++i){
                ans.push_back(s[i]); // Add it to the answer
                // If answer's length is greater than part's length 
                if(ans.size()>=m){
                    // If the m last characters of ans are equal to part
                    if(ans.substr(ans.size()-m,m)==part){
                        // Erase them from the answer
                        for(int j=0;j<m;++j) ans.pop_back();
                    }
                }
            }

            return ans;
        }
};
// @lc code=end

