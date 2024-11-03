/*
 * @lc app=leetcode id=719 lang=cpp
 *
 * [719] Find K-th Smallest Pair Distance
 */

// @lc code=start
#include<bits/stdc++.h>

/*
    Brute force (naive)- TLE
    n: size of input array
    mx: maximum number in input array
    Time complexity: O(n^2+mxlogmx)
    Space complexity: O(mx)
*/
typedef std::vector<int> vi;

class Solution {
    public:
        int smallestDistancePair(vi& nums, int k) {
            int n = nums.size();
            vi diffs;
            for(int i=0;i<n-1;++i){
                for(int j=i+1;j<n;++j){
                    diffs.push_back(abs(nums[i]-nums[j]));
                }
            }

            std::sort(diffs.begin(),diffs.end());

            return diffs[k-1];

        }
};
// @lc code=end

