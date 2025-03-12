/*
 * @lc app=leetcode id=1639 lang=cpp
 *
 * [1639] Number of Ways to Form a Target String Given a Dictionary
 */

// @lc code=start
#include<bits/stdc++.h>

/*
    Fequencies compression 
    Include/Exclude technique + DP Memoization
    Time compelxity: O((nm+mk)
    Space compelxity: O(m+mk+mk)
*/
typedef std::vector<int> vi;
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

            vvi memo(m,vi(k,-1));

            auto solve=[&](int letter_index,int target_index,auto& self)->long long{
                if(target_index==k) return 1;
                if(letter_index==m || m-letter_index<k-target_index) return 0;
                if(memo[letter_index][target_index]!=-1) return memo[letter_index][target_index];
                int cur_pos=target[target_index]-'a';
                long long match=freq[letter_index][cur_pos]*self(letter_index+1,target_index+1,self);
                long long not_match=self(letter_index+1,target_index,self);
                return memo[letter_index][target_index]=(match+not_match)%1000000007;
            };

            return solve(0,0,solve);
        }
};
// @lc code=end

