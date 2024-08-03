/*
 * @lc app=leetcode id=2418 lang=cpp
 *
 * [2418] Sort the People
 */

// @lc code=start
#include<bits/stdc++.h>

/*
    construct an array over pair (height, name)
    Then sort it wrt greater.
    Reuse names to return the answer.

    Time complexity: O(n+nlogn+n)=O(nlogn)
    Extra space complexity: O(2n+logn)
*/
class Solution {
public:
    std::vector<std::string> sortPeople(std::vector<string>& names, std::vector<int>& heights) {
        std::vector<std::pair<int,std::string>> heights_names;
        int n=names.size();
        for(int i=0;i<n;++i) heights_names.push_back({heights[i],names[i]});
        std::sort(heights_names.begin(),heights_names.end(),std::greater<>());
        for(int i=0;i<n;++i) names[i]=heights_names[i].second;
        return names;
    }
};
// @lc code=end

