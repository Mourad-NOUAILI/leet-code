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
        Check 930. Binary Subarrays With Sum
        
        Prefix sums: AC
        Time complexity: O(n log n)
        Extra space complexity: O(n)
    */
    int numberOfSubarrays(std::vector<int>& nums, int k){
        int n=nums.size();

        for(int i=0;i<n;++i) nums[i]=nums[i]%2==0?0:1;

        std::map<int,int> freq;
        freq[0]=1;
        int pre=0,ans=0;
        for(auto& e: nums){
            pre+=e;
            ans+=freq[pre-k];
            freq[pre]++;
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