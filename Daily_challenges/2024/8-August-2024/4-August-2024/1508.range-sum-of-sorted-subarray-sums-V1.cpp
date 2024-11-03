/*
 * @lc app=leetcode id=1508 lang=cpp
 *
 * [1508] Range Sum of Sorted Subarray Sums
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Time complexity:O(n+n+n^2+nlogn+n)=O(n^2+nlogn+3n)=O(n^2)
    Space complexity: O(n+n+logn)=O(2n+logn)=O(n)
*/
class Solution {
public:
    int rangeSum(std::vector<int>& nums, int n, int left, int right) {
        int MOD=1'000'000'007;
        std::vector<int> prefix_sum(n+1,0);
        for(int i=1;i<=n;++i) prefix_sum[i]=prefix_sum[i-1]+nums[i-1];
        
        std::vector<int> sums;
        for(int i=0;i<=n;++i){
            for(int j=i+1;j<=n;++j){
                sums.push_back(prefix_sum[j]-prefix_sum[i]);
            }
        }
        
        std::sort(sums.begin(),sums.end());

        int s=0;
        left--;
        right--;
        for(int i=left;i<=right;++i) s=(s%MOD+sums[i]);
        return s;
    }
};
// @lc code=end

