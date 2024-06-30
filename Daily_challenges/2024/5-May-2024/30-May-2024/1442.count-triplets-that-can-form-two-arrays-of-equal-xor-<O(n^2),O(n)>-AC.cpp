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
        Extra space complexity: O(n)
    */
    int countTriplets(std::vector<int>& arr) {
        int n=arr.size();

        std::vector<int> P(n+1,0);
        for(int i=1;i<=n;++i) P[i]=(P[i-1]^arr[i-1]);

        int ans=0;
    
        //This:
        for(int i=0;i<n-1;++i){
            for(int k=i+1;k<n;++k){
                if( (P[k+1]^P[i])==0 ) ans+=(k-i);
            }
        }

        //or this:
        /*for(int i=1;i<n;++i){
            for(int k=i+1;k<=n;++k){
                if( (P[k]^P[i-1])==0 ) ans+=(k-i);
            }
        }*/
        return ans;
    }
};
// @lc code=end

