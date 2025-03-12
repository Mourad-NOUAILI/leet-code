/*
 * @lc app=leetcode id=1684 lang=cpp
 *
 * [1684] Count the Number of Consistent Strings
 */

// @lc code=start
#include<bits/stdc++.h>

/*
    Time complexity: O(n+mk)
    Space complexity: O(26)=O(1)
*/
class Solution {
    public:
        int countConsistentStrings(std::string allowed, std::vector<std::string>& words) {
            bool exist[26]={false};
            for(auto& letter: allowed) exist[letter-'a']=true;

            int ans=0;
            for(auto& word: words){
                int i=0,k=word.size();
                while(i<k&&exist[word[i]-'a']) i++;
                ans+=(i==k);
            }
                
            return ans; 
        }
};
// @lc code=end

