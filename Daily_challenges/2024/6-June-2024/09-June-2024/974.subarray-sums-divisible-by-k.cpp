/*
 * @lc app=leetcode id=974 lang=cpp
 *
 * [974] Subarray Sums Divisible by K
 */

// @lc code=start
#include<bits/stdc++.h>

class Solution {
public:
    int modulo(int a,int b){
        return ((a%b)+b)%b;
    }

    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        std::vector<int> prefix(n+1,0);
        for(int i=1;i<=n;++i) prefix[i]=prefix[i-1]+nums[i-1];
        for(int i=0;i<=n;++i) prefix[i]=modulo(prefix[i],k);
        std::map<int,int> count;
        for(auto& v: prefix) count[v]++;
        int ans=0;
        for(auto& [v,f]: count) ans+= (f-1)*f/2;
        return ans;
    }
};
// @lc code=end


/*
    [5]\n9\n

    [0,10,-100,3,15,20,-20,45,-1,99,6,33]\n5\n
    ==>21

    [0,10,-100,3,15,20,-20,45,-1,99,6,33]\n3\n
    ==>31

    [0,10,-100,3,15]\n3\n

*/
