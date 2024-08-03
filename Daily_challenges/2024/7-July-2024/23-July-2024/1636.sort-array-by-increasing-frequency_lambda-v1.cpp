/*
 * @lc app=leetcode id=1636 lang=cpp
 *
 * [1636] Sort Array by Increasing Frequency
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Time complexity: O(nlogn)
    Extra space complexity: O(n+2n+logn)
*/
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n=nums.size();

        std::unordered_map<int,int> freq;
        for(auto& val: nums) freq[val]++;

        std::vector<std::pair<int,int>> nums_freq;
        for(auto& val: nums){
            int f=freq[val];
            nums_freq.push_back({val,f});
        }
        
        std::sort(nums_freq.begin(),nums_freq.end(),[](const std::pair<int,int>& p1,const std::pair<int,int>& p2){
                                                        if(p1.second==p2.second) return p1.first>p2.first;
                                                        return p1.second<p2.second;
                                                    });

        for(int i=0;i<n;i++) nums[i]=nums_freq[i].first; 

        return nums;
    }
};
// @lc code=end

