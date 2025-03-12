/*
 * @lc app=leetcode id=2109 lang=cpp
 *
 * [2109] Adding Spaces to a String
 */

// @lc code=start
/*
    Two pointers, one pass
    Time compelxity: O(n)
    Space complexity: O(n+m)
*/
class Solution {
public:
    std::string addSpaces(std::string s, std::vector<int>& spaces) {
        int n=s.size();
        int m=spaces.size();
        std::string ans="";
        int p=0;
        for(int i=0;i<n;++i){
            if(p<m && i==spaces[p]) ans+=' ',p++;
            ans+=s[i];
        }
        return ans;
    }
};
// @lc code=end

