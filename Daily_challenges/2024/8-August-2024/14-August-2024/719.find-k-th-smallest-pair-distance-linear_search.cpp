/*
 * @lc app=leetcode id=719 lang=cpp
 *
 * [719] Find K-th Smallest Pair Distance
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Linear search - TLE
    n: size of input array
    mx: maximum number in input array
    Time complexity: O(nlogn+mx^2)
    Space complexity: O(1)
*/
typedef std::vector<int> vi;

class Solution {
    public:
        int smallestDistancePair(vi& nums, int k) {
            int n=nums.size();

            std::sort(nums.begin(),nums.end());

            int mx=*std::max_element(nums.begin(),nums.end());

            /*
                All absolute difference are in range [0-mx],
                So, is the k-th smaller difference.

            */

            for(int diff=0;diff<=mx;++diff){

                /*
                    count total number of pairs with
                    absolute difference <= diff
                */
                auto count=[&](void)->int{
                    int l=0,cnt=0;
                    for(int r=0;r<n;++r){
                        while(nums[r]-nums[l]>diff) l++;
                        cnt+=r-l;
                    }
                    return cnt;
                };

                int cnt=count();

                if(cnt>=k) return diff;
            }
            
            return -1;
        }
};
// @lc code=end

