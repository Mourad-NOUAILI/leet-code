/*
 * @lc app=leetcode id=386 lang=cpp
 *
 * [386] Lexicographical Numbers
 */

// @lc code=start
#include<bits/stdc++.h>

/*
    Iterative
    Time complexity: o(n)
    Space complexity: O(1)
*/

class Solution {
    public:
        std::vector<int> lexicalOrder(int n) {
            std::vector<int> ans;
            int cur=1;
            while(ans.size()<n){
                ans.push_back(cur);
                if(cur*10<=n) cur*=10;
                else{
                    while(cur==n || cur%10==9) cur/=10;
                    cur++;
                }
            }
            return ans;
        }
};
// @lc code=end

