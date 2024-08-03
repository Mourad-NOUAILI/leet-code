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
    Time complexity: O(n+m)
    Extra space complexity: O(x)
*/
class Solution {
public:
    std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::vector<int> freq(1001,0);
        for(auto& e: nums1) freq[e]++;

        std::vector<int> ans;
        int m=nums2.size();
        for(int i=0;i<m;++i){
            int b=nums2[i];
            if(freq[b]>0){
                freq[b]--;
                ans.push_back(b);
            }
        }

        return ans;
    }
};
// @lc code=end

