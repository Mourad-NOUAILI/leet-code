/*
 * @lc app=leetcode id=3068 lang=cpp
 *
 * [3068] Find the Maximum Sum of Node Values
 */

// @lc code=start
#include<bits/stdc++.h>

typedef long long ll;
class Solution {
    public:
        ll maximumValueSum(std::vector<int>& nums, int k, std::vector<std::vector<int>>& edges){
            ll ans=0,count=0,min_diff=INT_MAX;
            for(auto& val: nums){
                ll xor_val=(val^k)*1ll;
                if(xor_val>val){
                    ans+=xor_val;
                    count++;
                    min_diff=std::min(min_diff,xor_val-val);
                }
                else{
                    ans+=val;
                    min_diff=std::min(min_diff,val-xor_val);
                }
            }
            if(count%2==0) return ans;
            return ans-min_diff;
        }

};
// @lc code=end


// [3,5,4,10,2]\n6\n[[0,1],[0,2],[1,3],[1,4]]\n
// ==> 28

// [2,3]\n7\n[[0,1]]\n
// ==> 9

// [7,7,7,7,7,7]\n3\n[[0,1],[0,2],[0,3],[0,4],[0,5]]\n
//==> 42

// [7,0,1,50,7,333]\n3\n[[0,1],[0,2],[0,3],[0,4],[0,5]]\n
// ==> 402