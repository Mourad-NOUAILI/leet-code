/*
 * @lc app=leetcode id=1143 lang=cpp
 *
 * [1143] Longest Common Subsequence
 */

// @lc code=start
/*
    Recursion
    Time complexity: O(2^{n+m})
    Space compelxity:O(n+m)
*/
class Solution {
    public:
        int longestCommonSubsequence(std::string text1, std::string text2) {
            int n=text1.size(),m=text2.size();
            auto lcs=[&](int i,int j,auto& self)->int{
                if(i==n || j==m) return 0;
                if(text1[i]==text2[j]) return 1+self(i+1,j+1,self);
                return std::max(self(i+1,j,self),self(i,j+1,self));
            };
            return lcs(0,0,lcs);
        }
};
// @lc code=end

