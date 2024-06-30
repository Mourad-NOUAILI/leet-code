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
        Time complexity: O(n^3)
        Extra space complexity: O(n)
    */
    int countTriplets(std::vector<int>& arr) {
        int n=arr.size();

        std::vector<int> P(n+1,0);
        for(int i=1;i<=n;++i) P[i]=(P[i-1]^arr[i-1]);

        int ans=0;
        /*
        This one:
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                for(int k=j;k<n;++k){
                    if((P[j]^P[i])==(P[k+1]^P[j])) ans++;
                }
            }
        }
        
        or this one:
        */
        for(int i=1;i<n;++i){
            for(int j=i+1;j<=n;++j){
                for(int k=j;k<=n;++k){
                    if((P[j-1]^P[i-1])==(P[k]^P[j-1])) ans++;
                }
            }
        }


        return ans;
    }
};
// @lc code=end

