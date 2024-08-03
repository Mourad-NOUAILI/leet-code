/*
 * @lc app=leetcode id=350 lang=cpp
 *
 * [350] Intersection of Two Arrays II
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Counting
    n=|nums1|, m=|nums2|
    Time complexity: O(n log n+m*log n)
    Extra space complexity: O(n)
*/
class Solution {
public:
    std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::map<int,int> freq;
        for(auto& e: nums1) freq[e]++;

        std::vector<int> ans;
        int m=nums2.size();
        for(auto& e: nums2){
          if(freq[e]>0){
            freq[e]--;
            ans.push_back(e);
          }
        }

        return ans;
    }
};
// @lc code=end

