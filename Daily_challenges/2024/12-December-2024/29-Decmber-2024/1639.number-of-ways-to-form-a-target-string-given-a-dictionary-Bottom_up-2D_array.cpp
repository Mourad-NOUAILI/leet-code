/*
 * @lc app=leetcode id=1639 lang=cpp
 *
 * [1639] Number of Ways to Form a Target String Given a Dictionary
 */

// @lc code=start
#include<bits/stdc++.h>

/*
    DP Bottom up with 2D array
    Time compelxity: O(m+m+mk)
    Space compelxity: O(mk)
*/
typedef std::vector<long long> vi;
typedef std::vector<vi> vvi;

class Solution {
    public:
        int numWays(vector<string>& words, string target) {
            int n=words.size();
            int m=words[0].size();
            int k=target.size();

            vvi freq(m,vi(26,0));
            for(auto& word: words){
                for(int i=0;i<m;++i){
                    int letter_pos=word[i]-'a';
                    freq[i][letter_pos]++;
                }
            }

            vvi dp(m+1,vi(k+1,0));
            
            // There only one way to build empty string With each letter from words.
            for(int letter_index=0;letter_index<=m;++letter_index) dp[letter_index][0]=1;

            // Fill the table using cells dependecies seen in editorial
            for(int letter_index=1;letter_index<=m;++letter_index){
                for(int target_index=1;target_index<=k;++target_index){
                    // Match
                    int cur_pos=target[target_index-1]-'a';
                    dp[letter_index][target_index]=(freq[letter_index-1][cur_pos]*dp[letter_index-1][target_index-1])%1000000007;

                    // No match
                    dp[letter_index][target_index]+=(dp[letter_index-1][target_index]);
                }
            }

            return dp[m][k]%1000000007;
        }
};
// @lc code=end

