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
        
        Dynamic sliding window|two pointers technique: AC
        Time complexity: O(n)
        Extra space complexity: O(1)
    */
    int numberOfSubarrays(std::vector<int>& nums, int k){
        int n=nums.size();

        for(int i=0;i<n;++i) nums[i]=nums[i]%2==0?0:1;

        auto nb_subarrays_with_sum_at_most_k=[&](int k)->int{
            int n=nums.size();
            int ans=0,s=0,i=0,j=0;
            while(j<n){
                s+=nums[j];
                while(i<=j&&s>k) s-=nums[i++];
                ans+=j-i+1;
                j++;
            }
            return ans;
        };
        return nb_subarrays_with_sum_at_most_k(k)-nb_subarrays_with_sum_at_most_k(k-1);
    }
};
// @lc code=end

/*
    [2,2,1,2,2,2,1,2,1,2]\n2\n
    ==>14

    [2,2,1,2,2,2,1,2,1,2]\n3\n
*/