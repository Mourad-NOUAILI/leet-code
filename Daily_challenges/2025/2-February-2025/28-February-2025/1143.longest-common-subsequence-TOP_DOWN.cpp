/*
 * @lc app=leetcode id=1143 lang=cpp
 *
 * [1143] Longest Common Subsequence
 */

// @lc code=start
/*
    Top-Down
    Time complexity: O(nm)
    Space compelxity:O(nm+(n+m))
*/
class Solution {
public:
    int longestCommonSubsequence(std::string text1, std::string text2) {
        int n=text1.size(),m=text2.size();
        std::vector<std::vector<int>> memo(n+1,std::vector<int>(m+1,-1));
        auto lcs=[&](int i,int j,auto& self)->int{
            if(i==n || j==m) return memo[i][j]=0;

            if (memo[i][j]!=-1) return memo[i][j]; 

            if(text1[i]==text2[j]) return memo[i][j]=1+self(i+1,j+1,self);
            return memo[i][j]=std::max(self(i+1,j,self),self(i,j+1,self));
        };
        return lcs(0,0,lcs);
    }
};
// @lc code=end

