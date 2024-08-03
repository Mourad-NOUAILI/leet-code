/*
 * @lc app=leetcode id=2418 lang=cpp
 *
 * [2418] Sort the People
 */

// @lc code=start
#include<bits/stdc++.h>

/*
    Pack each height with its correspondant index (height[i],i)
    sort the packed data (based on height)
    unpack tbe data, ino order to put each name in unpakded i, in its correct position 
    Time complexity: O(n+nlogn+n)=O(nlogn)
    Extra space complexity: O(2n+logn)
*/
class Solution {
public:
    std::vector<std::string> sortPeople(std::vector<string>& names, std::vector<int>& heights) {
        const int n=names.size();
        for(int i=0; i<n; i++) heights[i]=((heights[i]<<10)|i);
       
        sort(heights.begin(), heights.end(), greater<>());
        
        vector<string> ans(n);
        for(int i=0; i<n; i++) ans[i]=names[heights[i]&1023];
        return ans; 
    }
};
// @lc code=end

