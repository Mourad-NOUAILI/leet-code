/*
 * @lc app=leetcode id=1248 lang=cpp
 *
 * [1248] Count Number of Nice Subarrays
 */

// @lc code=start
#include<bits/stdc++.h>

class Solution{
public:
    /*
        Brute force: TLE
        Time complexity: O(n^2)
        Extra space complexity: O(n)
    */
    int numberOfSubarrays(std::vector<int>& nums, int k){
        int n=nums.size();

        for(int i=0;i<n;++i) nums[i]=nums[i]%2==0?0:1;

        std::vector<int> pre(n+1,0);
        for(int i=1;i<=n;++i) pre[i]=pre[i-1]+nums[i-1];

        int ans=0;
        for(int i=0;i<n;++i){
            for(int j=i;j<n;++j){
                if(pre[j+1]-pre[i]==k) ans++;
            }
        }
        return ans;
    }
};
// @lc code=end

/*
    [2,2,1,2,2,2,1,2,1,2]\n2\n
    ==>14

    [2,2,1,2,2,2,1,2,1,2]\n3\n
*/