/*
 * @lc app=leetcode id=1639 lang=cpp
 *
 * [1639] Number of Ways to Form a Target String Given a Dictionary
 */

// @lc code=start
/*
    DP Memoization
    Time compelxity: O(n.m.k)
    Space compelxity: O(m+mk)
*/
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

class Solution {
    public:
        int numWays(vector<string>& words, string target) {
            int n=words.size(); // Number of words
            int m=words[0].size(); // Length of a word string
            int k=target.size(); // Length of the target string

            vvi memo(m,vi(k,-1));

            auto solve=[&](int letter_index,int target_index,auto& self)->long long{
                // If all letters in target are processed, then a match is found
                if(target_index==k) return 1;
                
                // No match found (There are remaining letters to processed in target)
                // If we reached the end of the word
                // or the remaining letters in a word is less than the remaining letters in target
                // then we can't go further any more, return 0
                if(letter_index==m || m-letter_index<k-target_index) return 0;
                
                if(memo[letter_index][target_index]!=-1) return memo[letter_index][target_index];

                long long ans=0;
                // For each word in words
                for(int i=0;i<n;++i){
                    // If the letter at the position letter_index of each word is equal to the letter at target_index in target
                    // check for the next letter in the words and the next letter in target 
                    if(words[i][letter_index]==target[target_index]) ans+=self(letter_index+1,target_index+1,self);    
                }

                // If don't match, check for same letter in target with the next letter in words
                ans+=self(letter_index+1,target_index,self);
        
                return memo[letter_index][target_index]=ans%1000000007;
            };

            return solve(0,0,solve);
        }
};
// @lc code=end

