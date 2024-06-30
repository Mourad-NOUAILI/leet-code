/*
 * @lc app=leetcode id=1608 lang=cpp
 *
 * [1608] Special Array With X Elements Greater Than or Equal X
 */

// @lc code=start
#include<bits/stdc++.h>

class Solution {
public:
    // Time complexity: O(n log n+ log²n)
    // Extar time complexity: O(1)
    int specialArray(std::vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int lo=1,hi=n;
        while(lo<=hi){
            int mid=(lo+hi)>>1;
            auto lb=std::lower_bound(nums.begin(),nums.end(),mid)-nums.begin();
            int tmp_cnt=n-lb;
            if(tmp_cnt==mid) return mid;
            else if(tmp_cnt<mid) hi=mid-1;
            else lo=mid+1;
        }
        return -1;
    }
};
// @lc code=end

/*
    [0,4,3,0,4]\n
    =>3

    [2,3,5,10,1,7,1,0,11,30,0]\n
    ==>5 (5 values(5,10,7,11,30) >= 5)

    [2,5,5,10,1,7,1,0,11,30,0]\n
    ==>-1
*/