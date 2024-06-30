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
        Time complexity: O(n^3)
        Extra space complexity: O(1)
    */
    int numberOfSubarrays(std::vector<int>& nums, int k){
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;++i){
            for(int j=i;j<n;++j){
                int cnt=0;
                for(int k=i;k<=j;++k){
                    if(nums[k]%2!=0) cnt++;
                }
                if(cnt==k) ans++;
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