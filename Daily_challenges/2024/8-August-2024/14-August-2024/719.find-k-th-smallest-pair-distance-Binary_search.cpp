/*
 * @lc app=leetcode id=719 lang=cpp
 *
 * [719] Find K-th Smallest Pair Distance
 */

// @lc code=start
#include<bits/stdc++.h>

/*
    Binarys search
    n: size of input array
    mx: maximum number in input array
    Time complexity: O(nlogn+nlogmx)
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
            int lo=0,hi=mx;
            while(lo<hi){
                int mid=(lo+hi)>>1;
                /*
                    count total number of pairs with
                    absolute difference <= diff
                */
                auto count=[&](void)->int{
                    int l=0,cnt=0;
                    for(int r=0;r<n;++r){
                        while(nums[r]-nums[l]>mid) l++;
                        cnt+=r-l;
                    }
                    return cnt;
                };

                

                int cnt=count();

                if(cnt>=k) hi=mid;
                else lo=mid+1;
            }
            
            return hi; // or lo
        }
};
// @lc code=end

