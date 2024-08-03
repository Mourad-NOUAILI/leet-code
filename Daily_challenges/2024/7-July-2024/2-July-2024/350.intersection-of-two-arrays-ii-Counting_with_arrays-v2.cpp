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
    x=max(nums1[i],nums2[i])
    Time complexity: O(n+m+1000x)
    Extra space complexity: O(x)
*/
class Solution {
public:
    std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::vector<int> freq1(1001,0);
        for(auto& e: nums1) freq1[e]++;

        std::vector<int> freq2(1001,0);
        for(auto& e: nums2) freq2[e]++;

        std::vector<int> ans;
        for(int i=0;i<=1000;++i){
            if(freq1[i]==0 || freq2[i]==0) continue;
            int cnt=std::min(freq1[i],freq2[i]);
            for(int j=1;j<=cnt;j++) ans.push_back(i);
        }

        return ans;
    }
};
// @lc code=end

