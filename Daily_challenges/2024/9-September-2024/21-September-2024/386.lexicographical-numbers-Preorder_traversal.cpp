/*
 * @lc app=leetcode id=386 lang=cpp
 *
 * [386] Lexicographical Numbers
 */

// @lc code=start
#include<bits/stdc++.h>

/*
    Recursion preorder traversal
    Time complexity: O(n)
    Space complexity: O(log10(n))
*/

class Solution {
    public:
        std::vector<int> lexicalOrder(int n) {
            std::vector<int> ans;
            auto solve=[&](int cur,auto& self)->void{
                if(cur>n) return;
                ans.push_back(cur);
                cur*=10;
                for(int i=0;i<=9;++i) self(cur+i,self); 
            };
            for(int i=1;i<=9;++i) solve(i,solve);
            return ans;
        }
};
// @lc code=end

