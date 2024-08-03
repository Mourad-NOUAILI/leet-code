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
    Time complexity: O(n log n+m log m+max(n,m))
    Extra space complexity: O(log n)
*/
class Solution {
public:
    std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
      std::sort(nums1.begin(),nums1.end());
      std::sort(nums2.begin(),nums2.end());
      int n=nums1.size(),m=nums2.size(),i=0,j=0;
      std::vector<int> ans;
      while(i<n&&j<m){
        int ai=nums1[i];
        int bj=nums2[j];
        if(ai==bj){
          ans.push_back(ai);
          i++;
          j++;
        }
        else if (ai<bj) i++;
        else j++;
      }
      return ans;
    }
};
// @lc code=end

