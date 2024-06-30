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
        Time complexity: O(n)
        Extra space complexity: O(n)
    */
    int countTriplets(std::vector<int>& arr) {
        int n=arr.size();

        std::vector<int> P(n+1,0);
        for(int i=1;i<=n;++i) P[i]=(P[i-1]^arr[i-1]);

        int ans=0,p=0;
        std::unordered_map<int,int> xor_count,sum_of_i;
        xor_count[0]=1;
        sum_of_i[0]=0;

        for(int k=1;k<=n;++k){
            int p=P[k];
            ans+=k*xor_count[p]-sum_of_i[p]-1*xor_count[p];
            xor_count[p]++;
            sum_of_i[p]+=k;
        }
        return ans;
    }
};
// @lc code=end

