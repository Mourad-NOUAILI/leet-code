/*
 * @lc app=leetcode id=1442 lang=cpp
 *
 * [1442] Count Triplets That Can Form Two Arrays of Equal XOR
 */

// @lc code=start
#include<bits/stdc++.h>

class Solution {
public:
    /*
        Time complexity: O(n^4)
        Extra space complexity: O(1)
    */
    int countTriplets(std::vector<int>& arr) {
        int n=arr.size();

        int ans=0;
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                for(int k=j;k<n;++k){
                    auto xor_sum=[&](int l,int r, auto& self)->int{
                        int s=0;
                        for(int i=l;i<=r;++i) s^=arr[i];
                        return s;
                    };

                    if(xor_sum(i,j-1,xor_sum)==xor_sum(j,k,xor_sum)) ans++;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

