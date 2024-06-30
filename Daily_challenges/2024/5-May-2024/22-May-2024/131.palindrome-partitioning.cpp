/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */

// @lc code=start
#include<bits/stdc++.h>

class Solution {
public:
    // Time complexity: O(2^n * (n+n))
    // Extra space complexity: O(n) + O(2^n)
    std::vector<std::vector<std::string>> partition(std::string s) {
        std::vector<std::vector<std::string>> ans;
        std::vector<std::string> tmp;

        function<void(int)> solve=[&](int start){
            if(start==s.size()){
                ans.push_back(tmp);
                return;
            }
            for(int end=start;end<s.size();++end){
                std::string to_check=s.substr(start,end-start+1);
                if(std::equal(to_check.begin(),to_check.end(),to_check.rbegin())){
                    tmp.push_back(to_check);
                    solve(end+1);
                    tmp.pop_back();
                }
            }
        };

        solve(0);
        return ans;
    }
};
// @lc code=end

// "ababaab"\n
/* ==> [
        ["a","b","a","b","a","a","b"], <-
        ["a","b","a","b","aa","b"],
        ["a","b","a","baab"],
        ["a","b","aba","a","b"],
        ["a","bab","a","a","b"],
        ["a","bab","aa","b"],
        ["aba","b","a","a","b"], <-
        ["aba","b","aa","b"],
        ["aba","baab"],
        ["ababa","a","b"]
    ]

    "abaab"\n
    [
        ["a","b","a","a","b"],
        ["a","b","aa","b"],
        ["a","baab"],
        ["aba","a","b"]
    ]


]*/