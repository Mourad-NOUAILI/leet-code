/*
 * @lc app=leetcode id=260 lang=cpp
 *
 * [260] Single Number III
 */

// @lc code=start
#include<bits/stdc++.h>

class Solution {
public:
    std::vector<int> singleNumber(std::vector<int>& nums){
        int xor_val=0;
        for(auto& v: nums) xor_val^=v;

    
        /*int bitmask=1;
        while(!(xor_val&bitmask)) bitmask<<=1;

        or
        */
       int bitmask=xor_val&(-(xor_val*1u));

        int a=0,b=0;
        for(auto& v: nums){
            if(bitmask&v) a^=v;
            else b^=v;
        }

        return {a,b};
    }
};
// @lc code=end

/*

[1,1,0,-2147483648]

*/