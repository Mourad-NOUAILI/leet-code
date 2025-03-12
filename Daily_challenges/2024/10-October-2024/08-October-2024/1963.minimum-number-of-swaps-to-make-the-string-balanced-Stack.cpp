/*
 * @lc app=leetcode id=1963 lang=cpp
 *
 * [1963] Minimum Number of Swaps to Make the String Balanced
 */

// @lc code=start
#include<bits/stdc++.h>

/*
    Stack
    Time complexity: O(n)
    Space complexity: O(n)
*/
class Solution {
    public:
        int minSwaps(std::string s) {
            std::stack<char> st;
            int ans=0;
            for (char& c: s){
                if (c=='[') st.push(c);
                else{
                    if(!st.empty()) st.pop();
                    else ans++;
                }  
            }
            return (ans+1)/2;
        }
};
// @lc code=end

