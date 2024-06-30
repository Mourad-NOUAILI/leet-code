/*
 * @lc app=leetcode id=1438 lang=cpp
 *
 * [1438] Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit
 */

// @lc code=start
#include<bits/stdc++.h>

class Solution {
public:
    /*
        Sliding window(two pointers technique)+sqrt decomposition
        Time complexity: O(n*sqrt(n)+2n)
        Extra space complexity: O(2sqrt(n))
      
    */
    int longestSubarray(std::vector<int>& nums, int limit) {
        int n=nums.size();
        int m=ceil(sqrt(n));

        int MINUS_INF=std::numeric_limits<int>::min();
        int PLUS_INF=std::numeric_limits<int>::max();

         // <O(n),O(n)>
        auto build=[&](int op)->std::vector<int>{
            int f=op==1?MINUS_INF:PLUS_INF;
            std::vector<int> B(m,f);
            for(int i=0;i<n;++i) B[i/m]=op==1?std::max(B[i/m],nums[i]):std::min(B[i/m],nums[i]);
            return B;
        };

        // <O(sqrt(n)),O(1)>
        auto query=[&](std::vector<int> B,int l,int r,int op)->int{
            int ans=op==1?MINUS_INF:PLUS_INF;
            while(l<=r){
                if(l%m==0&&l+m<=r){
                    ans=op==1?std::max(ans,B[l/m]):std::min(ans,B[l/m]);
                    l+=m;
                }
                else{
                    ans=op==1?std::max(ans,nums[l]):std::min(ans,nums[l]);
                    l++;
                }
            }
            return ans;
        };

        std::vector<int> B_max=build(1);
        std::vector<int> B_min=build(-1);

        // <O(n*sqrt(n)),O(2n)>
        int i=0,j=0,d=0,ans=0;
        while(j<n){
            d=query(B_max,i,j,1)-query(B_min,i,j,-1);
            while(i<j&&d>limit){
                i++;
                d=query(B_max,i,j,1)-query(B_min,i,j,-1);
            }

            ans=std::max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};
// @lc code=end

/*
    [10,1,2,4,7,2]\n5\n

    [4,2,2,2,4,4,2,2]\n0\n

    [1,2,5]\n10\n

    [1,5,6,7,8,10,6,5,6]\n4\n

*/