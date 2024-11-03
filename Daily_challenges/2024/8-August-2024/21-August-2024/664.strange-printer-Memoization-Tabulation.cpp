/*
 * @lc app=leetcode id=664 lang=cpp
 *
 * [664] Strange Printer
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Tabulation
    Time complexity: O(n^3)
    Space complexity: O(n^2)
*/
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

class Solution {
    public:
        // Remove duplicates: aaabbbaaaacccaaa=>abaca
        std::string compression(std::string& s){
            std::string res;
            int n=s.size(),i=0;
            while(i<n){
                char c=s[i];
                res.push_back(c);
                while(i<n&&c==s[i]) i++;
            }
            return res;
        }

        int strangePrinter(std::string s) {

            s=compression(s);
           
            int n=s.size();

            vvi dp(n,vi(n,INT_MAX/2));

            for(int i=0;i<n;++i) dp[i][i]=1;

            for(int length=2;length<=n;++length){
                for(int i=0;i<=n-length;++i){
                    int j=i+length-1;
                    dp[i][j]=length;
                    for(int k=0;k<length-1;++k){
                        dp[i][j]=std::min(dp[i][j],dp[i][i+k]+dp[i+k+1][j]-(int(s[i]==s[j])));
                    }
                }
            }
           return dp[0][n-1];
        }
};

// @lc code=end

