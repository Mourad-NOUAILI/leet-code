/*
 * @lc app=leetcode id=1508 lang=cpp
 *
 * [1508] Range Sum of Sorted Subarray Sums
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Brute force
    Time complexity:O(n^2+nlogn+n)=O(n^2+nlogn+n)=O(n^2)
    Space complexity: O(n+logn)=O(n+logn)=O(n)
*/
class Solution {
public:
    int rangeSum(std::vector<int>& nums, int n, int left, int right) {
        int MOD=1'000'000'007;
        std::vector<int> sums;
        for(int i=0;i<n;++i){
            int s=0;
            for(int j=i;j<n;++j){
                s+=nums[j];
                sums.push_back(s);
            }
        }
        
        std::sort(sums.begin(),sums.end());

        int s=0;
        left--;
        right--;
        for(int i=left;i<=right;++i) s=s%MOD+sums[i];
        
        return s;
    }
};
// @lc code=end

