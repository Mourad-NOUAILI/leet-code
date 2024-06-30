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
            int n=nums.size();
            std::vector<int> diff;
            ll ans=0;
            for(auto& val: nums) {
                diff.push_back((val^k)-val);
                ans+=val;
            }

            std::sort(diff.begin(),diff.end(),std::greater<int>());

            int i=0;
            while(i<n-n%2){
                if(diff[i]+diff[i+1]>0) ans+=diff[i]+diff[i+1];
                i+=2;
            }
            return ans;
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