/*
 * @lc app=leetcode id=1639 lang=cpp
 *
 * [1639] Number of Ways to Form a Target String Given a Dictionary
 */

// @lc code=start
#include<bits/stdc++.h>

/*
    DP Bottom up with 1D array
    Time compelxity: O(m+k+mk)
    Space compelxity: O(k)
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

            vi prev_row(k+1,0);
            prev_row[0]=1;
           
            for(int letter_index=1;letter_index<=m;++letter_index){
                vi cur_row(k+1,0);
                cur_row[0]=1;
                for(int target_index=1;target_index<=k;++target_index){
                    // Match
                    int cur_pos=target[target_index-1]-'a';
                    cur_row[target_index]=(freq[letter_index-1][cur_pos]*prev_row[target_index-1])%1000000007;

                    // No match
                    cur_row[target_index]+=prev_row[target_index];
                }
                prev_row=cur_row;
            }

            return prev_row[k]%1000000007;
        }
};
// @lc code=end

