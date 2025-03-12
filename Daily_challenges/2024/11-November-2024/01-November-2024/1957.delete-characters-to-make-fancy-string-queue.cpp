/*
 * @lc app=leetcode id=1957 lang=cpp
 *
 * [1957] Delete Characters to Make Fancy String
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Queue
    Time complexity: O(n)
    Space complexity: O(n) 
*/
class Solution {
    public:
        std::string makeFancyString(std::string s){
            int n=s.size();

            // Use a queue to store the indices of the characters to remove
            std::queue<int> to_remove;
            for(int i=1;i<n-1;++i){
                if(s[i]==s[i-1] && s[i]==s[i+1]) to_remove.push(i);
            }


            std::string ans;
            for(int i=0;i<n;++i){
                // Get indices of the characters to remove
                int j=to_remove.front();

                // If the current character index is different from
                // the index extracted from the queue
                // and the current character to the answer
                if(i!=j) ans.push_back(s[i]);

                // Otherwise, skip that cuurent character and
                // pass to the next index of the character to remove
                else to_remove.pop();
            }
            
            return ans;
        }
};
// @lc code=end

