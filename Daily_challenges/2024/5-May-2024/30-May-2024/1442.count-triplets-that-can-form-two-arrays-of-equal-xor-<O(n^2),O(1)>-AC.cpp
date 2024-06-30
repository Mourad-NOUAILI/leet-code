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
        Time complexity: O(n^2)
        Extra space complexity: O(1)
    */
    int countTriplets(std::vector<int>& arr) {
        int n=arr.size();

        int ans=0;
        for(int i=0;i<n-1;++i){
            int xor_val=arr[i];
            for(int k=i+1;k<n;++k){
                xor_val^=arr[k];
                if(xor_val==0) ans+=(k-i);
            }
        }
        return ans;
    }
};
// @lc code=end

