/*
 * @lc app=leetcode id=1636 lang=cpp
 *
 * [1636] Sort Array by Increasing Frequency
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Time complexity: O(nlogn)
    Extra space complexity: O(n)
*/
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n=nums.size();

        std::vector<int> freq(201,0);
        for(auto& val: nums) freq[val+100]++;

        std::sort(nums.begin(),nums.end(),[&](const int& a,const int& b){
                                                        return freq[a+100]==freq[b+100]?a>b:freq[a+100]<freq[b+100];
                                                    });

        return nums;
    }
};
// @lc code=end

